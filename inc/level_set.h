#ifndef LEVEL_SET_H
#define LEVEL_SET_H

#include "board.h"

typedef struct{
    uint8_t max_levels;
    SOI_board_t * levels;
}SOI_level_set_t

#endif