#include "physics.h"

#include "board.h"
#include "blocks.h"
#include "sound.h"
#include "gameplay.h"

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


u8 bl_ctrl;
u8 gr_ctrl;
u8 * ctrl;
u8 dir;
u16 attr;
Actor * curr;

#define SFX_IND 5 //magic number

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
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 4 ) ) ) );
}

static inline void calc_front_floor(){
    front_floor_ind = XY_TO_IND( PX_TO_BLOCK( (front - 1) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) );
}

static inline void calc_back_floor(){
    back_floor_ind = XY_TO_IND( PX_TO_BLOCK( (back - 1) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_floor(){
    floor_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_front(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size);
}
static inline void calc_back(u8 direction){
    back = direction ? POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size);
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

static inline u8 land(u8 ind){
    return ( SOLID & env->front_blocks[ ind ] ) || (POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX);
}

static inline void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.frames = 0;
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

static inline void summon_deletor(u8 front_ind, u8 deletes){
    fx.status = deletes ? 1 : 0;
    fx.character = &deletor_ent;
    fx.frames = DELETOR_FRAMES;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 7;
    fx.pos[Y] = BLOCK_TO_PX( (IND_TO_Y(front_ind) + 1) );
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
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
                    calc_back(dir);
                    calc_back_floor();
                    if(fall(back_floor_ind)){
                        newstatus = dir | FALL_RIGHT;
                        curr->speed[Y] = FALLSPEED;
                        curr->speed[X] = 0;
                        return;
                    }
                    calc_front(dir);
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
            calc_front(dir);
            calc_front_block();
            break_block_ind(env, front_ind);
            switch(attr & BRK_BITMSK){
                case BREAKS:
                    brk_debris(front_ind, BRK_SPEED, 0);
                    XGM_setPCM(SFX_IND, blk_phy_break, sizeof(blk_phy_break));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                break;
                case DELETES:
                    summon_deletor(front_ind, TRUE);
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
                newstatus = WALK_RIGHT | !dir;
            }
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                newstatus = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
                break;
            }
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
            result = ACT_DELETION;
        break;
    }
}

static inline void player_tree(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_floor();
            if(fall(floor_ind)){
                newstatus = FALL_RIGHT | dir;
                curr->speed[Y] = FALLSPEED;
                curr->speed[X] = 0;
                return;
            }
            calc_front(dir);
            calc_front_block();
            if(crash_into()){
                curr->speed[X] = 0;
            }
            else{
                curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
            }
            if( *ctrl & CTRL_JUMP){
                newstatus = JUMP_RIGHT | dir;
                curr->speed[Y] = PL_JMP_BOOST;
                return;
            }
            if( *ctrl & CTRL_MOV ){
                if( ( *ctrl & CTRL_LEFT ) != dir ){
                    newstatus = RIGHT_TURN_LEFT | dir;
                    curr->frames = BP_TURN_FRAMES;
                    curr->speed[X] = 0;
                }
                return;
            }
            else
            {
                newstatus = RIGHT_TO_STL | dir;
                curr->frames = BP_STL_FRAMES;
                curr->speed[X] = 0;
            }
            return;
        break;
        case RIGHT_TURN_LEFT:
            newstatus = WALK_RIGHT | !dir;
            curr->speed[X] = dir ? PL_WALKSPEED : -PL_WALKSPEED;
        break;
        case ATTACK_RIGHT_IN:

        break;
        case ATTACK_RIGHT_OUT:

        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                newstatus = dir | STILL_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = 0;
                break;
            }
        break;
        case STILL_RIGHT:
            calc_floor();
            if(fall(floor_ind)){
                newstatus = FALL_RIGHT | dir;
                curr->speed[Y] = FALLSPEED;
                curr->speed[X] = 0;
                return;
            }
            if( *ctrl & CTRL_MOV ){
                if( ( *ctrl & CTRL_LEFT ) != dir ){
                    newstatus = STL_RIGHT_TO_LEFT | dir;
                    curr->frames = BP_STL_TURN_FRAMES;
                }else{
                    newstatus = STL_TO_RIGHT | dir;
                    curr->frames = BP_STL_FRAMES;
                }
                return;
            }
            if( *ctrl & CTRL_JUMP){
                newstatus = JUMP_RIGHT | dir;
                curr->speed[Y] = PL_JMP_BOOST;
            }
            return;
        break;
        case LOW_ATTK_RIGHT_IN:

        break;
        case LOW_ATTK_RIGHT_OUT:

        break;
        case STL_TO_RIGHT:
            newstatus = WALK_RIGHT | dir;
            calc_front(dir);
            calc_front_block();
            if(!crash_into())
                curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
        break;
        case STL_RIGHT_TO_LEFT:
            newstatus = WALK_RIGHT | !dir ;
            curr->speed[X] = dir ? PL_WALKSPEED : -PL_WALKSPEED;
        break;
        case RIGHT_TO_STL:
            newstatus = STILL_RIGHT | dir;
            curr->speed[X] = 0;
        break;
        case JUMP_RIGHT:
            if(curr->speed[Y] <= FALLSPEED)
                curr->speed[Y] += GRAVITY;
            calc_floor();
            if(land(floor_ind)) {
                newstatus = dir | STILL_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = 0;
                return;
            }
            calc_front( *ctrl & CTRL_LEFT );
            calc_front_block();
            if( *ctrl & CTRL_MOV && !crash_into()){
                curr->speed[X] = *ctrl & CTRL_LEFT ? -PL_WALKSPEED : PL_WALKSPEED;
            }else{
                curr->speed[X] = 0;
            }
        break;
        case JUMP_ATTK_RIGHT_IN:

        break;
        case JUMP_ATTK_RIGHT_OUT:

        break;
        case DEAD:

        break;
    }
    return;
}

static inline void big_entity_tree(){
    switch(attr & BIG_ENT_MSK){
        case BLUE_PLAYER:
            ctrl = &bl_ctrl;
            player_tree();
        break;
        case GREEN_PLAYER:
            ctrl = &gr_ctrl;
            player_tree();
        break;
        case KNIGHT:

        break;
        case GARGOYLE:

        break;
    }
}

static inline void class_tree(){
    switch(attr & ENT_CHECK_BITMSK){
        case NASTIE:
            nastie_tree();
        break;
        case BIG_ENTITY:
            big_entity_tree();
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

void PHY_send_inputs(u8 ctrl1, u8 ctrl2){
    bl_ctrl = ctrl1;
    gr_ctrl = ctrl2;
}

u8 PHY_computeStatus(Actor * actor){
    result = 0;
    if(actor->frames > 0){
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
