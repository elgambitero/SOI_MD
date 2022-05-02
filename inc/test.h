#ifndef TEST_H
#define TEST_H

#include "game_config.h"
#include "game_status.h"

const game_config_t passing_config;
void TST_game_config(game_config_t config);

const SOI_game_status_t passing_status;
void TST_game_status(SOI_game_status_t * status);

#endif