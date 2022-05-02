#include "test_levels.h"

#include "game_mode.h"
#include "level.h"

const SOI_level_set_t test_levels = {
    "Test Levels",
    1,
    COOPERATE,
    {
        &test_level0
    }
};