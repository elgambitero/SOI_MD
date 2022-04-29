#ifndef MENU_H
#define MENU_H

#include "frame_state.h"

typedef struct MEN_config_t{
    uint8_t first_level,
    uint8_t num_players,
    uint8_t seed[2]
}MEN_config_t;

const frame_t * MEN_begin(uint8_t max_levels);

const frame_t * MEN_out(MEN_config_t config);

#endif