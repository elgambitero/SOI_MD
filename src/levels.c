#include "levels.h"

const SOI_level_set_t demo_levels = {
    "Original Demo",
    13,
    COMPETE
};

const SOI_level_set_t * level_sets[] = {
    &demo_levels
};

SOI_level_set_array_t rom_levels = {
    1,
    level_sets
};