#include "players.h"

#include "sprites.h"
#include "sound.h"


//TODO: Fill this!
const Entity PL_blue = {
    BLUE_PLAYER,
    {
        {2, 15},
        {7, 15},
        PAL_SYS0,

        &bp_spr,
        snd_player_death,
        sizeof(snd_player_death),

        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,

        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,

        NULL,
        NULL,
        NULL,
    }
};

const Entity PL_green = {
    GREEN_PLAYER,
    {
        {2, 15},
        {7, 15},
        PAL_SYS1,

        &bp_spr,
        snd_player_death,
        sizeof(snd_player_death),

        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,

        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,

        NULL,
        NULL,
        NULL,
    }
};
