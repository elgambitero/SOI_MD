#include "physics.h"

#include "board.h"

#include "globals.h"

Board * env;
u8 status;
u8 newstatus;
u16 attr;
Actor * curr;

static inline void nastie_tree(){
            switch(status & ANIM_MSK){
                case WALK_RIGHT:
                    if(curr->pos[Y] < BOARD_Y_PX){
                        newstatus = (curr->status & 1) | FALL_RIGHT;
                        curr->status = newstatus;
                        curr->speed[Y] = FALLSPEED;
                    }
                break;
                case RIGHT_TURN_LEFT:

                break;
                case ATTACK_RIGHT:

                break;
                case FALL_RIGHT:
                    if(curr->pos[Y] >= BOARD_Y_PX){
                        curr->status = (curr->status & 1) + WALK_RIGHT;
                        curr->speed[Y] = 0;
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
    class_tree(attr);
}
