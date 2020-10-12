#include "entities.h"

#include "sprites.h"
#include "sound.h"
#include "behavior.h"

const Entity blue_player_ent = {
    BLUE_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &bp_spr,
    moon_blast,
    sizeof(moon_blast),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity green_player_ent = {
    GREEN_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &bp_spr,
    moon_blast,
    sizeof(moon_blast),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity spinner_ent = {
    NASTIE | STILL,
    {6, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &spinner_spr,
    0,
    0,
    NULL,
    NULL,
    &NST_still_fall,
    &NST_still_land,
    NULL,
    NULL
};

const Entity robo_ent = {
    NASTIE | WALKS | DIES_ON_LEAP | BREAKS | GOES_THRU,
    {4, 15},
    {7, 15},
    PAL_SYS0,
    1000,
    &robo_spr,
    bell,
    sizeof(bell),
    &NST_attack,
    &NST_turn_around,
    &NST_fall,
    &NST_die,
    &NST_breaks,
    &NST_keep_walking
};

const Entity ant_ent = {
    NASTIE | WALKS | LEAPS,
    {7, 8},
    {7, 8},
    PAL_SYS0,
    50,
    &ant_spr,
    0,
    0,
    &NST_turn_around,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    NULL,
    NULL
};

const Entity piggy_ent = {
    NASTIE | WALKS | LEAPS | DELETES,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    250,
    &piggy_spr,
    0,
    0,
    &NST_attack,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    &NST_deletes,
    &NST_turn_around_fast
};

const Entity teeth_ent = {
    NASTIE | WALKS | LEAPS | DELETES | GOES_THRU,
    {8, 15},
    {8, 15},
    PAL_SYS0,
    1500,
    &teeth_spr,
    0,
    0,
    &NST_attack,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    &NST_deletes,
    &NST_keep_walking
};

const Entity arrow_ent = {
    PROJECTILE | FLIES ,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &arrow_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity deletor_ent = {
    FX | DELETER,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &deletor_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris0_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris0_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris1_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris1_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris2_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris2_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris3_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris3_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};