#ifndef NORMAL_LEVEL_OUTRO_H
#define NORMAL_LEVEL_OUTRO_H

#include "cutscene.h"

#include "game_config.h"
#include "game_status.h"

typedef struct normal_outro_t{
    cutscene_t super;
    SOI_game_status_t * status;
    game_config_t * config;
}normal_outro_t

normal_outro_t * NOUT_init(
    normal_outro_t * self,
    SOI_game_status_t * status,
    game_config_t * config
);

extern const struct cutscene_vtable_ BONUS_OUTRO_T[];

#endif