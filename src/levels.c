#include "rom_levels.h"


const SOI_level_set_t test_levels = {
    "Test Levels",
    1,
    COOPERATE,
    NULL
};

const SOI_level_set_t * level_sets[] = {
    &test_levels
};

SOI_level_set_array_t rom_levels = {
    1,
    level_sets
};