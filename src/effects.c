#include "entities.h"



extern const Entity FX_deletor = {
    FX | DELETER,
    {
        {7, 15},
        {7, 15},
        PAL_SYS0,
        &deletor_spr
    }
};

extern const Entity FX_blk_debris0 = {
    FX | SHRAPNEL,
    {
        {4, 8},
        {4, 4},
        PAL_SYS0,
        &blk_debris0_spr
    }
};

extern const Entity FX_blk_debris1 = {
    FX | SHRAPNEL,
    {
        {4, 8},
        {4, 4},
        PAL_SYS0,
        &blk_debris1_spr
    }
};


extern const Entity FX_blk_debris2 = {
    FX | SHRAPNEL,
    {
        {4, 8},
        {4, 4},
        PAL_SYS0,
        &blk_debris2_spr
    }
};


extern const Entity FX_blk_debris3 = {
    FX | SHRAPNEL,
    {
        {4, 8},
        {4, 4},
        PAL_SYS0,
        &blk_debris3_spr
    }
};