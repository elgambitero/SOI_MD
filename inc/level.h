#ifndef LEVEL_H
#define LEVEL_H

#include <genesis.h>

#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X * BOARD_Y

typedef struct SOI_level_t{
    u16 front_blocks[BOARD_BUFFER];
    u16 back_blocks[BOARD_BUFFER];
    u8 colors[3];
    u16 bonus;

}SOI_level_t;

#endif