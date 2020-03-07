#include "physics.h"

#include "board.h"
#include "blocks.h"

#include "globals.h"

Board * env;
u8 status;
u8 newstatus;
u8 block_ind;
u8 dir;
u16 attr;
Actor * curr;

static inline void nastie_tree(){
            switch(status & ANIM_MSK){
                case WALK_RIGHT:
                    block_ind = XY_TO_IND( PX_TO_BLOCK(curr->pos[X] ), (PX_TO_BLOCK(curr->pos[Y]) ) );
                    if( !( SOLID & env->front_blocks[block_ind] ) &&  curr->pos[Y] < BOARD_Y_PX ){
                        newstatus = dir | FALL_RIGHT;
                        curr->status = newstatus;
                        curr->speed[Y] = FALLSPEED;
                        break;
                    }
                break;
                case RIGHT_TURN_LEFT:

                break;
                case ATTACK_RIGHT:

                break;
                case FALL_RIGHT:
                    block_ind = XY_TO_IND( PX_TO_BLOCK(curr->pos[X] ), (PX_TO_BLOCK(curr->pos[Y]) ) );
                    if( (SOLID & env->front_blocks[ block_ind ] ) ) {
                        curr->status = dir + WALK_RIGHT;
                        curr->speed[Y] = 0;
                        curr->pos[Y] = ( IND_TO_Y(block_ind) << 4);
                        break;
                    }
                    if(curr->pos[Y] >= BOARD_Y_PX){
                        curr->status = dir + WALK_RIGHT;
                        curr->speed[Y] = 0;
                        curr->pos[Y] = BOARD_Y_PX;
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
    curr = actor;
    status = curr->status;
    attr = curr->character->attr;
    dir = (status & 1);
    class_tree(attr);
}
