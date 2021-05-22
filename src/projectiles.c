#include "SOI.h"

#include "sprites.h"
#include "sound.h"


void PR_arrow_fired();

const Entity PR_arrow = {
    PROJECTILE | FLIES,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &arrow_spr,
    NULL,
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