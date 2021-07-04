#include "SOI.h"

#include "sprites.h"
#include "sound.h"


void PR_arrow_fired();

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

            NULL
        }
    }
};

void PR_arrow_fired(){

}

void PR_update(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    //TODO: GET RID OF ATTRS
    switch(attr & MOVT_BITMSK){
        case FLIES:
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case BLOCK:
                    if(breakable(front_ind)){
                        if(attr & BREAKS){
                            brk_debris(front_ind, BRK_SPEED, 0);
                            if(!(attr & GOES_THRU)){
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
        break;
        case LURKS:

        break;
    }
}