#ifndef BOARD_H

#define BOARD_H

#include "actors.h"
#include "blocks.h"

#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X*BOARD_Y

typedef struct{
    u8 front_blocks[BOARD_BUFFER],
    u8 back_blocks[BOARD_BUFFER],
    Actor * actors
} Board;

#endif