#include "board.h"

u8 load_board(Board * board, const Board * level){
    for(u8 i = 0; i < BOARD_BUFFER; i++){
        board->front_blocks[i] = level->front_blocks[i];
        board->back_blocks[i] = level->back_blocks[i];
    }
    board->actors = level->actors;
    //memcpy(board, level, sizeof(Board));
    Actor * actor = board->actors;
    while(actor){
        ACT_add(actor);
        actor = actor->next;
    }
    return 1;
}