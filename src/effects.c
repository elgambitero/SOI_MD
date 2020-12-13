#include "effects.h"

#include "sprites.h"
#include "sound.h"

#include "physics.h"
#include "gameplay.h"
#include "blocks.h"

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
            NULL,
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
            NULL,
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
            NULL,
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
            NULL,
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
            NULL,
            NULL
        }
    }
};

const Entity boot_ind_bp = {
    FX,
    {4, 8},
    {4, 3},
    PAL_SYS1,
    &boot_ind_spr,
    NULL,
    NULL,
    {.effect =
        {
            NULL,
            NULL
        }
    }
};