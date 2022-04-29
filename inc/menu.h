#ifndef MENU_H
#define MENU_H

#include "frame_state.h"

#include "game_config.h"

const frame_t * MEN_begin(uint8_t max_levels);

const frame_t * MEN_end_cb(game_config_t config);

#endif