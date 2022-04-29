#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

enum SOI_game_mode_t{
    COOPERATE,
    COMPETE
};

typedef struct game_config_t{
    uint8_t first_level;
    uint8_t num_players;
    enum SOI_game_mode_t game_mode;
    uint8_t seed[2];
}game_config_t;

#endif