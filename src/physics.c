#include "physics.h"

#include "board.h"
#include "blocks.h"

#include "globals.h"

Board * env;

u8 status;
u8 newstatus;

u16 front_ind;
u16 back_floor_ind;
u16 front_floor_ind;
u16 floor_ind;
u16 front;
u16 back;

u8 dir;
u16 attr;
Actor * curr;

u8 result;

struct Actor fx = {0,
    0,
    0,
    {0, 0},
    {0, 0},
    0,
    0
};

static inline void calc_front_block(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) - 1) );
}

static inline void calc_front_floor(){
    front_floor_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) );
}

static inline void calc_back_floor(){
    back_floor_ind = XY_TO_IND( PX_TO_BLOCK( back ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_floor(){
    floor_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_front(){
    front = dir ? POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size);
}
static inline void calc_back(){
    back = dir ? POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size);
}

static inline u8 fall(u8 ind){
    return !( SOLID & env->front_blocks[ind] ) &&  ( POS_TO_PX(curr->pos[Y])  < BOARD_Y_PX );
}

static inline u8 turn_around(){
    return (front_floor_ind < BOARD_BUFFER) && !( SOLID & env->front_blocks[front_floor_ind] );
}

static inline u8 crash_into(){
    if( front >= BOARD_X_PX )
        return FRAME;
    if(SOLID & env->front_blocks[front_ind])
        return BLOCK;
    else
        return 0;
}

static inline u8 breakable(){
    return (BREAKABLE & env->front_blocks[front_ind]);
}

static inline u8 land(){
    return ( SOLID & env->front_blocks[ floor_ind ] ) || (POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX);
}

static inline void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.character = &blk_debris0_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED_2X;
    ACT_add(&fx);
    fx.character = &blk_debris1_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED;
    ACT_add(&fx);
    fx.character = &blk_debris2_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED;
    ACT_add(&fx);
    fx.character = &blk_debris3_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED_2X;
    ACT_add(&fx);
}

static inline void nastie_tree(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            switch(attr & MOVT_BITMSK){
                case STILL:
                    calc_floor();
                    if(fall(floor_ind)){
                        newstatus = FALL_RIGHT;
                        status = FALL_RIGHT; //Ugly hack
                        curr->speed[Y] = FALLSPEED;
                        curr->speed[0] = 0;
                        return;
                    }
                    curr->speed[X] = 0;
                    return;
                case WALKS:
                    calc_back();
                    calc_back_floor();
                    if(fall(back_floor_ind)){
                        newstatus = dir | FALL_RIGHT;
                        curr->speed[Y] = FALLSPEED;
                        curr->speed[X] = 0;
                        return;
                    }
                    calc_front();
                    calc_front_block();
                    switch(crash_into()){
                        case FRAME:
                            newstatus = dir | RIGHT_TURN_LEFT;
                            curr->frames = TURN_FRAMES;
                            curr->speed[X] = 0;
                            return;
                        case BLOCK:
                            switch(attr & BRK_BITMSK){
                                case DELETES:
                                case BREAKS:
                                    if(breakable()){
                                        newstatus = dir | ATTACK_RIGHT_IN;
                                        curr->frames = ATTK_FRAMES;
                                        curr->speed[X] = 0;
                                        return;
                                    }else{
                                        newstatus = dir | RIGHT_TURN_LEFT;
                                        curr->frames = TURN_FRAMES;
                                        curr->speed[X] = 0;
                                        return;
                                    }
                                    break;
                                default:
                                    newstatus = dir | RIGHT_TURN_LEFT;
                                    curr->frames = TURN_FRAMES;
                                    curr->speed[X] = 0;
                                    return;
                                    break;
                            }
                            break;
                        default:
                            break;

                    }
                    calc_front_floor();
                    if(!(attr & LEAPS) && turn_around()){
                        newstatus = dir | RIGHT_TURN_LEFT;
                        curr->frames = TURN_FRAMES;
                        curr->speed[X] = 0;
                        return;
                    }
                break;
            }
            
            curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
        break;
        case RIGHT_TURN_LEFT:
            newstatus = WALK_RIGHT | !dir;
            curr->speed[X] = dir ? WALKSPEED : -WALKSPEED;
        break;
        case ATTACK_RIGHT_IN:
            calc_front();
            break_block_ind(env, front_ind);
            switch(attr & BRK_BITMSK){
                case BREAKS:
                    brk_debris(front_ind, BRK_SPEED, 0);
                break;
                case DELETES:

                break;
            }
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT:
            if(attr & GOES_THRU){
                newstatus = WALK_RIGHT | dir;
                curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
            }else{
                newstatus = RIGHT_TURN_LEFT | !dir;
                curr->frames = TURN_FRAMES;
            }
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land()) {
                newstatus = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
                break;
            }
        break;
        case UP_TURN_DOWN:
        
        break;
        case ATTACK_UP:
        
        break;
    }
}

static inline void fx_tree(){
    switch(attr & FX_TYP_MSK){
        case SHRAPNEL:
            if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
                result = ACT_DELETION;
            }
            curr->speed[Y] += GRAVITY;
        break;
        case DELETER:
        
        break;
        case CREATOR:

        break;
    }
}

static inline void class_tree(){
    switch(attr & ENT_CHECK_BITMSK){
        case NASTIE:
            nastie_tree(status);
        break;
        case BIG_ENTITY:

        break;
        case PROJECTILE:

        break;
        case FX:
            fx_tree();
        break;

    }
}

void PHY_init(Board * board){
    env = board;
}

u8 PHY_computeStatus(Actor * actor){
    result = 0;
    if(actor->frames){
        actor->frames--;
        return result;
    }
    curr = actor;
    status = curr->status;
    newstatus = status;
    attr = curr->character->attr;
    dir = (status & 0x0001);

    class_tree();
    
    curr->status = newstatus;
    if(status != newstatus) result = ACT_CHANGED;
    return result;
}
