#include "SOI.h"

#include "sprites.h"
#include "sound.h"

void PR_arrow_loop();
const Entity PR_arrow = {
    PROJECTILE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &arrow_spr,
    NULL,
    &PR_arrow_loop,
    NULL,
    {.proj =
        {
        }
    }
};

void PR_canb_loop();
const Entity PR_cannonball = {
    PROJECTILE,
    {3, 7},
    {3, 7},
    PAL_SYS0,
    &cannonball_spr,
    NULL,
    &PR_canb_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_arrow_loop(){
    calc_front(dir);
    calc_front_block();
    switch(crash_into()){
        case BLOCK:
        case FRAME:
            result = ACT_DELETION;
            return;
    }
}

void PR_canb_loop(){
    calc_front(dir);
    calc_front_block();
    if(crash_into()){
        result = ACT_DELETION;
        if(breakable(front_ind)){
            break_block_ind(env, front_ind);
            if(dir)
                brk_debris(front_ind, -CANBALL_SPEED, 0);
            else
                brk_debris(front_ind,  CANBALL_SPEED, 0);
        }
    }
}

/*
void PR_update(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    curr->character->role.proj.travel();
}
*/