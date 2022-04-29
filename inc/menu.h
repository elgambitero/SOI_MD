#ifndef MENU_H
#define MENU_H

#include "frame_state.h"

#include "game_modes.h"

typedef struct MEN_config_t{
    uint8_t first_level;
    uint8_t num_players;
    enum game_mode_t game_mode;
    uint8_t seed[2];
}MEN_config_t;

const frame_t * MEN_begin(uint8_t max_levels);

const frame_t * MEN_end_cb(MEN_config_t config);

#endif