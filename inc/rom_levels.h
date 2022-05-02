#ifndef LEVELS_H
#define LEVELS_H

#include "level_set.h"

typedef struct{
    uint8_t max_level_sets;
    const SOI_level_set_t ** level_sets;
}SOI_level_set_array_t;

SOI_level_set_array_t rom_levels;

const SOI_level_t * LVL_get_level_from_indices(
    uint8_t level_set_index,
    uint8_t level_index
);

#endif