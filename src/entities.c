#include "entities.h"

#include "sprites.h"

const Entity blue_player_ent = {
    BLUE_PLAYER,
    (u8) CODE_SIZE(2, 15),
    (u8) CODE_SIZE(7, 15),
    PAL_SYS0,
    &bp_spr
};

const Entity green_player_ent = {
    GREEN_PLAYER,
    (u8) CODE_SIZE(2, 15),
    (u8) CODE_SIZE(7, 15),
    PAL_SYS1,
    &bp_spr
};
const Entity spinner_ent = {
    NASTIE | STILL,
    (u8) CODE_SIZE(6,15),
    (u8) CODE_SIZE(7, 15),
    PAL_SYS0,
    &spinner_spr
};

const Entity robo_ent = {
    NASTIE | WALKS | DIES_ON_LEAP | BREAKS | GOES_THRU,
    (u8) CODE_SIZE(4, 15),
    (u8) CODE_SIZE(7, 15),
    PAL_SYS0,
    &robo_spr
};

const Entity ant_ent = {
    NASTIE | WALKS | LEAPS,
    (u8) CODE_SIZE(7, 8),
    (u8) CODE_SIZE(7, 8),
    PAL_SYS0,
    &ant_spr
};

const Entity piggy_ent = {
    NASTIE | WALKS | LEAPS | DELETES,
    (u8) CODE_SIZE(7,15),
    (u8) CODE_SIZE(7,15),
    PAL_SYS1,
    &piggy_spr
};

const Entity deletor_ent = {
    FX | DELETER,
    (u8) CODE_SIZE(7,15),
    (u8) CODE_SIZE(7,15),
    PAL_SYS0,
    &deletor_spr
};

const Entity blk_debris0_ent = {
    FX | SHRAPNEL,
    (u8) CODE_SIZE(4, 8),
    (u8) CODE_SIZE(4, 4),
    PAL_SYS0,
    &blk_debris0_spr
};

const Entity blk_debris1_ent = {
    FX | SHRAPNEL,
    (u8) CODE_SIZE(4, 8),
    (u8) CODE_SIZE(4, 4),
    PAL_SYS0,
    &blk_debris1_spr
};

const Entity blk_debris2_ent = {
    FX | SHRAPNEL,
    (u8) CODE_SIZE(4, 8),
    (u8) CODE_SIZE(4, 4),
    PAL_SYS0,
    &blk_debris2_spr
};

const Entity blk_debris3_ent = {
    FX | SHRAPNEL,
    (u8) CODE_SIZE(4, 8),
    (u8) CODE_SIZE(4, 4),
    PAL_SYS0,
    &blk_debris3_spr
};