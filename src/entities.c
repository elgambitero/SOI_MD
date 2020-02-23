#include "entities.h"

#include "sprites.h"

Entity blue_player_ent = {
    BLUE_PLAYER,
    (u8) CODE_SIZE(2, 15),
    PAL1,
    &bp_spr
};

Entity spinner_ent = {
    NASTIE | STILL,
    (u8) CODE_SIZE(6,15),
    PAL2,
    &spinner_spr
};