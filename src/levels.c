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
    &level10,
    &level11,
    &level12,
    &level43, // TO BE REPLACED BY 13
    &level14,
    &level15,
    &level16,
    &level17,
    &level18,
    &level19,
    &level20,
    &level21,
    &level22,
    &level23,
    &level24,
    &level53, // TO BE REPLACED BY 25
    &level26,
    &level27,
    &level28,
    &level29,
    &level30,
};

const u8 max_levels = 31; //Not dynamic. Should be calculated upon compiling.