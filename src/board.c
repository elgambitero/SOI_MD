#include "SOI.h"

#include "palettes.h"
#include "music.h"

#define XOFF 1
#define YOFF 1

u8 BRD_load(Board * board, const Board * level){
    memcpy(board, level, sizeof(Board));
    Actor * actor = board->actors;
    while(actor){
        if(!ACT_add(actor, &nasties))
            return 0; //0
        actor = actor->next;
    }
    actor = board->players;
    while(actor){
        if(!ACT_add(actor, &players))
            return 0; //0
        actor = actor->next;
    }
    return 1;
}

void BRD_unload(Board * board){
    memset(board, 0, sizeof(board));
    for(u8 i = 0; i<BOARD_BUFFER; i++){
        BLK_eraseBlock_ind(i);
    }
}

void BRD_load_palettes(Board * board){
    u16 white[8];
    u16 slot0[8];
    u16 slot1[8];
    u16 slot2[8];
    memcpy(white, pal_src_wg.data, 8 * sizeof(u16));
    switch(board->colors[0]){
        case PAL_GR:
            memcpy(slot0, pal_src_wg.data + 8, 8 * sizeof(u16));
            break;
        case PAL_R:
            memcpy(slot0, pal_src_rb.data, 8 * sizeof(u16));
            break;
        case PAL_BL:
            memcpy(slot0, pal_src_rb.data + 8, 8 * sizeof(u16));
            break;
        case PAL_PI:
            memcpy(slot0, pal_src_yp.data + 8, 8 * sizeof(u16));
            break;
        case PAL_YL:
            memcpy(slot0, pal_src_yp.data, 8 * sizeof(u16));
            break;
        case PAL_BK:
            memcpy(slot0, pal_src_bl.data, 8 * sizeof(u16));
            break;
            
    }
    switch(board->colors[1]){
        case PAL_GR:
            memcpy(slot1, pal_src_wg.data + 8, 8 * sizeof(u16));
            break;
        case PAL_R:
            memcpy(slot1, pal_src_rb.data, 8 * sizeof(u16));
            break;
        case PAL_BL:
            memcpy(slot1, pal_src_rb.data + 8, 8 * sizeof(u16));
            break;
        case PAL_PI:
            memcpy(slot1, pal_src_yp.data + 8, 8 * sizeof(u16));
            break;
        case PAL_YL:
            memcpy(slot1, pal_src_yp.data, 8 * sizeof(u16));
            break;
        case PAL_BK:
            memcpy(slot1, pal_src_bl.data, 8 * sizeof(u16));
            break;
    }
    switch(board->colors[2]){
        case PAL_GR:
            memcpy(slot2, pal_src_wg.data + 8, 8 * sizeof(u16));
            break;
        case PAL_R:
            memcpy(slot2, pal_src_rb.data, 8 * sizeof(u16));
            break;
        case PAL_BL:
            memcpy(slot2, pal_src_rb.data + 8, 8 * sizeof(u16));
            break;
        case PAL_PI:
            memcpy(slot2, pal_src_yp.data + 8, 8 * sizeof(u16));
            break;
        case PAL_YL:
            memcpy(slot2, pal_src_yp.data, 8 * sizeof(u16));
            break;
        case PAL_BK:
            memcpy(slot2, pal_src_bl.data, 8 * sizeof(u16));
            break;
            
    }

    VDP_setPaletteColors(32, white, 8);
    VDP_setPaletteColors(40, slot0, 8);
    VDP_setPaletteColors(48, slot1, 8);
    VDP_setPaletteColors(56, slot2, 8);
}

void BRD_draw(Board * board){
    for(u8 i = 0; i < BOARD_BUFFER; i++){
        BLK_drawBlock(IND_TO_X(i), IND_TO_Y(i), *(board->front_blocks + i));
    }
}

u16 BRD_get_block(Board * board, u8 x, u8 y){
    return board->front_blocks[XY_TO_IND(x, y)];
}

void BRD_set_block(Board * board, u16 block, u16 ind){
    if(ind < BOARD_BUFFER){
        board->front_blocks[ind] = block;
        BLK_drawBlock(IND_TO_X(ind), IND_TO_Y(ind), block);
    }else{
        board->back_blocks[ind - BOARD_BUFFER] = block;
    }
}

void BRD_create_block(Board * board, u16 block, u8 x, u8 y){
    u8 ind = XY_TO_IND(x, y);
    board->front_blocks[ind] = block;
    BLK_drawBlock(x, y, block);
}

void BRD_create_block_ind(Board * board, u16 block, u8 ind){
    board->front_blocks[ind] = block;
    BLK_drawBlock(IND_TO_X(ind), IND_TO_Y(ind), block);
}

void BRD_break_block(Board * board, u8 x, u8 y){
    u8 ind = XY_TO_IND(x, y);
    BLK_eraseBlock(x, y);
    board->front_blocks[ind] = 0;
    if(board->back_blocks[ind]){
        board->front_blocks[ind] = board->back_blocks[ind];
        board->back_blocks[ind] = 0;
        BLK_drawBlock(x, y, (*(board->front_blocks + ind)));
        return;
    }
    return;
}

void BRD_break_block_ind(Board * board, u8 ind){
    board->front_blocks[ind] = 0;
    BLK_eraseBlock(IND_TO_X(ind), IND_TO_Y(ind));
    if(board->back_blocks[ind]){
        board->front_blocks[ind] = board->back_blocks[ind];
        board->back_blocks[ind] = 0;
        BLK_drawBlock(IND_TO_X(ind), IND_TO_Y(ind), (*(board->front_blocks + ind)));
        return;
    }
    return;
}

void BRD_play_music(Board * board){
    //This is ugly.
    switch(board->music){
        case MUS_HEAVY1:
            XGM_startPlay(heavy1);
            break;
        case MUS_HEAVY2:
            XGM_startPlay(heavy2);
            break;
        case MUS_HEAVY3:
            XGM_startPlay(heavy3);
            break;
        case MUS_BONUSHEAVY:
            XGM_startPlay(bonusHeavy);
            break;
        default:
            XGM_startPlay(heavy1);
            break;
    }
}

u16 BRD_seek_block(Board * board, u16 block){
    
    for(u8 i = 0; i<BOARD_BUFFER; i++){
        if(board->front_blocks[i] == block){
            return i;
        }
    }

    for(u8 i = 0; i<BOARD_BUFFER; i++){
        if(board->back_blocks[i] == block){
            return i + BOARD_BUFFER;
        }
    }

    return BOARD_NOTFOUND;;
}

u8 BRD_seek_block_front_msk(Board * board, u16 block, u8 from, u16 msk){
    for(u8 i = from; i<BOARD_BUFFER; i++ ){
        if((board->front_blocks[i] & msk) == (block & msk)){
            return i;
        }
    }
    return BOARD_NOTFOUND;
}