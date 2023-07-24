#include "SOI.h"

const Board * levels[] = {
    &test_level,
    &level1,
    &level2,
    &level3,
    &level4,
    &level5,
    &level6,
    &level7,
    &level8,
    &level9,
    &level10
};

const u8 max_levels = 11; //Not dynamic. Should be calculated upon compiling.