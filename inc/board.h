#ifndef BOARD_H

#define BOARD_H

#include "actors.h"

#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X * BOARD_Y

#define BOARD_X_PX BOARD_X * 16
#define BOARD_Y_PX BOARD_Y * 16

#define BOARD_X_MAX PX_TO_POS(BOARD_X_PX)
#define BOARD_Y_MAX PX_TO_POS(BOARD_Y_PX)

#define IND_TO_X(ind)   (ind % BOARD_X)
#define IND_TO_Y(ind)   (ind / BOARD_X)
#define XY_TO_IND(x ,y) ((y * BOARD_X) + x)

typedef struct Board{
    u16 front_blocks[BOARD_BUFFER];
    u16 back_blocks[BOARD_BUFFER];
    u8 colors[3];
    u8 music;
    Actor * actors;
} Board;

u8 load_board(Board * board, const Board * level);
void load_board_palettes(Board * board);
void draw_board(Board * board);
void play_board_music(Board * board);
u16 getBlock(Board * board, u8 x, u8 y);
void create_block(Board * board, u16 block, u8 x, u8 y);
void create_block_ind(Board * board, u16 block, u8 ind);
void break_block(Board * board, u8 x, u8 y);
void break_block_ind(Board * board, u8 ind);

#endif