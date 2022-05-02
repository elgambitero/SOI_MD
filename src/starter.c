#include "starter.h"

#include "password.h"

SOI_game_status_t STR_create_game_from_config(game_config_t * config);

SOI_game_status_t STR_create_game_status(game_config_t config){
    if(config.password){
        return PWD_create_game_from_password(config.password);
    }else{
        return STR_create_game_from_config(&config);
    }
}

SOI_game_status_t STR_create_game_from_config(game_config_t * config){
    SOI_game_status_t status;
    status.current_level = config->start_level;
    status.level_set_ind = config->start_level_set;
}