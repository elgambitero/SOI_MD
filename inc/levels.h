#ifndef LEVELS_H
#define LEVELS_H

#include "level_set.h"

typedef struct{
    uint8_t max_level_sets;
    SOI_level_set_t * level_sets;
}SOI_level_set_array_t;

SOI_level_set_array_t rom_levels;

#endif