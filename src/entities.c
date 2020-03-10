#include "entities.h"

#include "sprites.h"

const Entity blue_player_ent = {
    BLUE_PLAYER,
    (u8) CODE_SIZE(2, 15),
    (u8) CODE_SIZE(7, 15),
    PAL_SYS0,
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