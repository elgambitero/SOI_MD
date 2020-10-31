#include "levels.h"

const Board * levels[] = {
    &test_level,
    &level1
};

const u8 max_levels = 2; //Not dynamic. Should be calculated upon compiling.