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

/*
void PR_update(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    curr->character->role.proj.travel();
}
*/