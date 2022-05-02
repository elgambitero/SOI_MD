#ifndef LEVEL_SET_H
#define LEVEL_SET_H

#include <genesis.h>

#include "game_mode.h"
#include "level.h"

typedef struct{
    const char * name;
    uint8_t max_levels;
    enum SOI_game_mode_t game_mode;
    SOI_level_t * levels;
}SOI_level_set_t;

#endif