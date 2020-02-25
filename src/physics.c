#include "physics.h"

#include "board.h"

#include "globals.h"

void PHY_computeStatus(Actor * actor){
    u8 newstatus;
    if(actor->pos[Y] < BOARD_Y_PX){
        //newstatus = (actor->status & 1) + FALL_RIGHT;
        //actor->status = newstatus;
        actor->speed[Y] = FALLSPEED;
    }else{
        //actor->status = (actor->status & 1) + WALK_RIGHT;
        actor->speed[Y] = 0;
    }
}
