#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include "game_mode.h"

typedef struct game_config_t{
    uint8_t start_level;
    uint8_t start_level_set;
    uint8_t num_players;
    uint8_t seed[2];
}game_config_t;

#endif