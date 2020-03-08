#include "physics.h"

#include "board.h"
#include "blocks.h"

#include "globals.h"

Board * env;
u8 status;
u8 newstatus;
u8 back_floor_ind;
u8 front_floor_ind;
u16 front;
u8 dir;
u16 attr;
Actor * curr;

static inline u8 fall(){
    if( !( SOLID & env->front_blocks[back_floor_ind] ) &&  curr->pos[Y] < BOARD_Y_PX ){
        newstatus = dir | FALL_RIGHT;
        curr->status = newstatus;
        curr->speed[Y] = FALLSPEED;
        return 1;
    }
    return 0;
}

static inline u8 turn_around(){
    if( !( SOLID & env->front_blocks[front_floor_ind] ) &&  front < BOARD_X_PX ){
        newstatus = dir | RIGHT_TURN_LEFT;
        curr->status = newstatus;
        curr->frames = TURN_FRAMES;
        curr->speed[X] = 0;
        return 1;
    }
    return 0;
}

static inline void nastie_tree(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            switch(status & MOVT_BITMSK){
                case STILL:
                case WALKS:
                    back_floor_ind = dir ? XY_TO_IND( PX_TO_BLOCK(curr->pos[X] + SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) ) :
                            XY_TO_IND( PX_TO_BLOCK(curr->pos[X] - SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) );
                    if(fall())
                        return;
                break;
            }
            front_floor_ind = !dir ? XY_TO_IND( PX_TO_BLOCK(curr->pos[X] + SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) ) :
                        XY_TO_IND( PX_TO_BLOCK(curr->pos[X] - SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) );
            front = dir ? curr->pos[X] - SIZE_X(curr->character->size) : curr->pos[X] + SIZE_X(curr->character->size);
            if(!(status & LEAPS)){
                if(turn_around())
                    return;
            }
            curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
        break;
        case RIGHT_TURN_LEFT:
            newstatus = WALK_RIGHT | dir;
            if(status & WALKS)
                curr->speed[X] = WALKSPEED;
        break;
        case ATTACK_RIGHT:

        break;
        case FALL_RIGHT:
            back_floor_ind = dir ? XY_TO_IND( PX_TO_BLOCK(curr->pos[X] + SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) ) :
                                XY_TO_IND( PX_TO_BLOCK(curr->pos[X] - SIZE_X(curr->character->size) ), (PX_TO_BLOCK(curr->pos[Y]) ) );
            if( (SOLID & env->front_blocks[ back_floor_ind ] ) ) {
                curr->status = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                //curr->pos[Y] = ( IND_TO_Y(back_floor_ind) << 4);
                break;
            }
            if(curr->pos[Y] >= BOARD_Y_PX){
                curr->status = dir + WALK_RIGHT;
                curr->speed[Y] = 0;
                //curr->pos[Y] = BOARD_Y_PX;
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

void PHY_computeStatus(Actor * actor){
    if(actor->frames)
        actor->frames--;
        return;
    curr = actor;
    status = curr->status;
    attr = curr->character->attr;
    dir = (status & 1);
    class_tree(attr);
}
