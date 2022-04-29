#ifndef MENU_H
#define MENU_H

#include "frame_state.h"

#include "game_config.h"
#include "levels.h"

const frame_t * MEN_begin(SOI_level_set_array_t * rom_levelsets);

const frame_t * MEN_end_cb(game_config_t config);

#endif