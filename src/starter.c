#include "starter.h"

#include "password.h"
#include "rom_levels.h"

SOI_game_status_t status;

SOI_game_status_t STR_create_game_from_config(game_config_t * config);
void STR_initialize_player_stats(
    SOI_game_status_t * status,
    const SOI_level_t * first_level,
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
    status.current_level = config->start_level;
    status.level_set_ind = config->start_level_set;

    const SOI_level_set_t * level_set_ptr = rom_levels.level_sets[status.level_set_ind];
    const SOI_level_t * first_level_ptr = level_set_ptr->levels + status.current_level;

    for(uint8_t i = 0; i <= config->additional_players; i++){
        STR_initialize_player_stats(
            &status,
            first_level_ptr,
            i
        );
    }

    return status;
}

void STR_initialize_player_stats(
    SOI_game_status_t * status,
    const SOI_level_t * first_level,
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