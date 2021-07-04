#include "SOI.h"

#include "sprites.h"
#include "sound.h"


void PR_arrow_fired();
void PR_fly();

void PR_update();

const Entity PR_arrow = {
    PROJECTILE | FLIES,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &arrow_spr,
    NULL,
    &PR_update,
    NULL,
    {.proj =
        {
            &PR_arrow_fired,
            &PR_fly,
            NULL
        }
    }
};

void PR_arrow_fired(){

}

void PR_fly(){
    calc_front(dir);
    calc_front_block();
    u16 attrib = curr->character->attr;
    switch(crash_into()){
        case BLOCK:
            if(breakable(front_ind)){
                if(attrib & BREAKS){
                    brk_debris(front_ind, BRK_SPEED, 0);
                    if(!(attrib & GOES_THRU)){
                        result = ACT_DELETION;
                    }
                }
                result = ACT_DELETION;
            }else{
                result = ACT_DELETION;
                return;
            }
        break;
        case FRAME:
            result = ACT_DELETION;
            return;
        break;
    }
}

void PR_update(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    curr->character->role.proj.travel();
}