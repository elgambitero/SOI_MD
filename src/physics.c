#include "physics.h"

#include "board.h"
#include "blocks.h"

#include "globals.h"

Board * env;
u8 status;
u8 newstatus;
u8 front_ind;
u8 back_floor_ind;
u8 front_floor_ind;
u8 floor_ind;
u16 front;
u16 back;
u8 dir;
u16 attr;
Actor * curr;

static inline calc_front_block(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) - 1) );
}

static inline calc_front_floor(){
    front_floor_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) );
}

static inline calc_back_floor(){
    back_floor_ind = XY_TO_IND( PX_TO_BLOCK( back ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) ) ;
}

static inline calc_floor(){
    floor_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y] + 1) ) ) ) ;
}

static inline calc_front(){
    front = dir ? POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size);
}
static inline calc_back(){
    back = dir ? POS_TO_PX(curr->pos[X]) + SIZE_X(curr->character->size) : POS_TO_PX(curr->pos[X]) - SIZE_X(curr->character->size);
}

static inline u8 fall(){
    if( !( SOLID & env->front_blocks[back_floor_ind] ) &&  ( POS_TO_PX(curr->pos[Y]) < BOARD_Y_PX ) ){
        newstatus = dir | FALL_RIGHT;
        curr->speed[Y] = FALLSPEED;
        curr->speed[X] = 0;
        return 1;
    }
    return 0;
}

static inline u8 turn_around(){
    if( !( SOLID & env->front_blocks[front_floor_ind] ) ||  ( front >= BOARD_X_PX ) ){
        newstatus = dir | RIGHT_TURN_LEFT;
        curr->frames = TURN_FRAMES;
        curr->speed[X] = 0;
        return 1;
    }
    return 0;
}

static inline u8 crash_into(){
    return ( SOLID & env->front_blocks[front_ind] ) ||  ( front >= BOARD_X_PX );
}

static inline void nastie_tree(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            switch(attr & MOVT_BITMSK){
                case STILL:
                case WALKS:
                    calc_back();
                    calc_back_floor();
                    if(fall())
                        return;
                    calc_front();
                    calc_front_block();
                    if(crash_into()){
                        switch(attr & BRK_BITMSK){
                            case BREAKS_THRU:
                            case BREAKS:
                                break;
                            default:
                                newstatus = dir | RIGHT_TURN_LEFT;
                                curr->frames = TURN_FRAMES;
                                curr->speed[X] = 0;
                                return;
                                break;
                        }
                    }
                    calc_front_floor();
                    if(!(attr & LEAPS)){
                        if(turn_around())
                            return;
                        }
                break;
            }
            
            curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
        break;
        case RIGHT_TURN_LEFT:
            newstatus = WALK_RIGHT | !dir;
            //if(attr & WALKS)
            curr->speed[X] = dir ? WALKSPEED : -WALKSPEED;
        break;
        case ATTACK_RIGHT:

        break;
        case FALL_RIGHT:
            calc_floor();
            if( (SOLID & env->front_blocks[ floor_ind ] ) ) {
                newstatus = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
                break;
            }
            if(POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX){
                newstatus = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
            }
        break;
        case UP_TURN_DOWN:
        
        break;
        case ATTACK_UP:
        
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
        case SFX:

        break;

    }
}

void PHY_init(Board * board){
    env = board;
}

u8 PHY_computeStatus(Actor * actor){
    if(actor->frames){
        actor->frames--;
        return;
    }
    curr = actor;
    status = curr->status;
    newstatus = status;
    attr = curr->character->attr;
    dir = (status & 0x0001);

    class_tree();
    
    curr->status = newstatus;
    return newstatus != status;
}
