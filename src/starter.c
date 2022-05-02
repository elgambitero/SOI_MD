#include "starter.h"

#include "password.h"
#include "rom_levels.h"

SOI_game_status_t STR_create_game_from_config(game_config_t * config);
void STR_initialize_player_stats(
    SOI_game_status_t * status,
    SOI_level_t * first_level,
    uint8_t player_index
);

SOI_game_status_t STR_create_game_status(game_config_t * config){
    //if(config->password){
    //    return PWD_create_game_from_password(config->password);
    //}else{
        return STR_create_game_from_config(config);
    //}
}

SOI_game_status_t STR_create_game_from_config(game_config_t * config){
    SOI_game_status_t status;
    status.current_level = config->start_level;
    status.level_set_ind = config->start_level_set;

    SOI_level_t first_level =
        rom_levels
            .level_sets[status.level_set_ind]->
                levels[status.current_level];

    for(uint8_t i = 0; i < config->num_players; i++){
        STR_initialize_player_stats(
            &status,
            &first_level,
            i
        );
    }

    return status;
}

void STR_initialize_player_stats(
    SOI_game_status_t * status,
    SOI_level_t * first_level,
    uint8_t player_index
)
{
    status->player_stat[player_index].score     = 0;
    status->player_stat[player_index].bonus     = first_level->bonus;
    status->player_stat[player_index].mult      = START_MULT;
    status->player_stat[player_index].arrows    = START_ARROWS;
    status->player_stat[player_index].balls     = START_BALLS;
    status->player_stat[player_index].lives     = START_LIVES;
}