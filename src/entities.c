#include "entities.h"

#include "sprites.h"

const Entity blue_player_ent = {
    BLUE_PLAYER,
    (u8) CODE_SIZE(2, 15),
    (u8) CODE_SIZE(7, 15),
    PAL_RGB,
    &bp_spr
};

const Entity spinner_ent = {
    NASTIE | STILL,
    (u8) CODE_SIZE(6,15),
    (u8) CODE_SIZE(7, 15),
    PAL_RGB,
    &spinner_spr
};