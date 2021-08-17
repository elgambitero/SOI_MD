#ifndef BOARD_H

#define BOARD_H


#define BOARD_X 19
#define BOARD_Y 13
#define BOARD_BUFFER BOARD_X * BOARD_Y
#define BOARD_NOTFOUND 0xFF

#define BOARD_X_PX BOARD_X * 16
#define BOARD_Y_PX BOARD_Y * 16

#define BOARD_X_MAX PX_TO_POS(BOARD_X_PX)
#define BOARD_Y_MAX PX_TO_POS(BOARD_Y_PX)

#define IND_TO_X(ind)   (ind % BOARD_X)
#define IND_TO_Y(ind)   (ind / BOARD_X)
#define XY_TO_IND(x ,y) ((y * BOARD_X) + x)

#define IS_COMPETITIVE   0x01

typedef struct Board{
    u16 front_blocks[BOARD_BUFFER];
    u16 back_blocks[BOARD_BUFFER];
    u8 colors[3];
    u8 music;
    u8 attributes;
    u16 bonus;
    Actor * actors;
    Actor * players;
} Board;

u8 BRD_load(Board * board, const Board * level);
void BRD_unload(Board * board);
void BRD_load_palettes(Board * board);
void BRD_draw(Board * board);
void BRD_play_music(Board * board);
u16 BRD_get_block(Board * board, u8 x, u8 y);
void BRD_set_block(Board * board, u16 block, u16 ind);
void BRD_create_block(Board * board, u16 block, u8 x, u8 y);
void BRD_create_block_ind(Board * board, u16 block, u8 ind);
void BRD_break_block(Board * board, u8 x, u8 y);
void BRD_break_block_ind(Board * board, u8 ind);
u16 BRD_seek_block(Board * board, u16 block);
u8 BRD_seek_block_front_msk(Board * board, u16 block, u8 from, u16 msk);

#endif