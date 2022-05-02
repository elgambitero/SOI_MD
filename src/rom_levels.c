#include "rom_levels.h"

#include "test_levels.h"

const SOI_level_set_t * level_sets[] = {
    &test_levels
};

SOI_level_set_array_t rom_levels = {
    1,
    level_sets
};

const SOI_level_t * LVL_get_level_from_indices(
    uint8_t level_set_index,
    uint8_t level_index
){
    const SOI_level_set_t * level_set_ptr =
        rom_levels.level_sets[level_set_index];
    const SOI_level_t * first_level_ptr =
        level_set_ptr->levels + level_index;
    return first_level_ptr;
}