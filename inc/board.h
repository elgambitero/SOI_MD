#ifndef BOARD_H

#define BOARD_H

#include "actors.h"

#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X * BOARD_Y

#define BOARD_X_PX BOARD_X * 16
#define BOARD_Y_PX BOARD_Y * 16

#define IND_TO_X(ind)   (ind % BOARD_X)
#define IND_TO_Y(ind)   (ind / BOARD_X)
#define XY_TO_IND(x ,y) ((y * BOARD_X) + x)

typedef struct Board{
    u16 front_blocks[BOARD_BUFFER];
    u16 back_blocks[BOARD_BUFFER];
    u8 colors[3];
    Actor * actors;
} Board;

u8 load_board(Board * board, const Board * level);
void load_board_palettes(Board * board);
void draw_board(Board * board);

#endif