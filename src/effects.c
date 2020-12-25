#include "effects.h"

#include "sprites.h"
#include "sound.h"

#include "physics.h"
#include "gameplay.h"
#include "blocks.h"

void FX_follow();
void FX_restoreSpeed();
void FX_deletor_process();
void FX_shrapnel_process();

const Entity FX_hidden = {
    FX,
    {7, 15},
    {8, 7},
    PAL_SYS1,
    &fx_hidden,
    NULL,
    NULL,
    {.effect =
        {
            NULL,
            NULL
        }
    }
};

const Entity FX_deletor = {
    FX | DELETER,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &deletor_spr,
    NULL,
    NULL,
    {.effect =
        {
            &FX_deletor_process,
            NULL
        }
    }
};

const Entity FX_blk_debris0 = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris0_spr,
    NULL,
    NULL,
    {.effect =
        {
            &FX_shrapnel_process,
            NULL
        }
    }
};

const Entity FX_blk_debris1 = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris1_spr,
    NULL,
    NULL,
    {.effect =
        {
            &FX_shrapnel_process,
            NULL
        }
    }
};


const Entity FX_blk_debris2 = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris2_spr,
    NULL,
    NULL,
    {.effect =
        {
            &FX_shrapnel_process,
            NULL
        }
    }
};


const Entity FX_blk_debris3 = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris3_spr,
    NULL,
    NULL,
    {.effect =
        {
            &FX_shrapnel_process,
            NULL
        }
    }
};

const Entity FX_boot_ind = {
    FX,
    {4, 8},
    {4, 24},
    PAL_SYS0,
    &boot_ind_spr,
    NULL,
    &FX_restoreSpeed,
    {.effect =
        {
            &FX_follow,
            NULL
        }
    }
};

void FX_deletor_process() {
    if(curr->frames--) return;
    result = ACT_DELETION;
}

void FX_shrapnel_process(){
    if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
        result = ACT_DELETION;
    }
    curr->speed[Y] += GRAVITY;
}

void FX_follow(){
    curr->pos[X] = curr->actorData.fxData.following->pos[X];
    curr->pos[Y] = curr->actorData.fxData.following->pos[Y];
}

void FX_restoreSpeed(){
    curr->
    actorData.fxData.following->
    character->
    role.player.statistics->
    speed = PL_WALKSPEED;
}