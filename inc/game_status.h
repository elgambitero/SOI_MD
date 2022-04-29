#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#define MAX_PLAYERS 2

typedef struct SOI_game_status_t{
    uint8_t current_level;
    SOI_player_status_t player_stat[MAX_PLAYERS];
    const SOI_level_set_t * level_set;
}SOI_game_status_t;

#endif