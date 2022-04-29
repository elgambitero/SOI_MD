#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "player_status.h"

#define MAX_PLAYERS 2

typedef struct SOI_game_status_t{
    SOI_player_status_t player_stat[MAX_PLAYERS];
}SOI_game_status_t;

#endif