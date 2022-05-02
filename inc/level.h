#ifndef LEVEL_H
#define LEVEL_H

#include <genesis.h>

#include "cutscene.h"

#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X * BOARD_Y

typedef struct SOI_level_t{
    uint16_t front_blocks[BOARD_BUFFER];
    uint16_t back_blocks[BOARD_BUFFER];
    uint8_t colors[3];
    uint16_t bonus;
    cutscene_t intro;
}SOI_level_t;

#endif