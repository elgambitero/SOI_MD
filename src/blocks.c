#include <genesis.h>

#include "blocks.h"

#include "board.h"
#include "stage.h"

#define BLK_TO_TILE(x) (1 + x*2)
#define FG 0
#define BG 1

u16 clr_blk_bg_ind = TILE_USERINDEX;
u16 clr_blk_sl0_ind = TILE_USERINDEX;
u16 clr_blk_sl1_ind = TILE_USERINDEX;
u16 sp_blk_ind = TILE_USERINDEX;
u16 wt_blk_ind = TILE_USERINDEX;
u16 pl_blk_fg_ind = TILE_USERINDEX;
u16 pl_blk_bg_ind = TILE_USERINDEX;

void drawBlock(u8 x, u8 y, u16 block){
    u8 map_ind = 0;
    u16 tile_index[2] = {0, 0};
    u8 palette[2] = {PAL2, PAL2};
    Map * fg_blk_map;
    Map * bg_blk_map;
    if(x >= BOARD_X || y >= BOARD_Y || !block)
        return;
    switch(block & 0x0003){
        case NORMAL_BLOCK:
            if( ( NBLK_TYP_MSK & block ) == BLK_PLAYER ){
                fg_blk_map = pl_blk_fg.map;
                bg_blk_map = pl_blk_bg.map;
                tile_index[FG] = pl_blk_fg_ind;
                tile_index[BG] = pl_blk_bg_ind;
                palette[BG] = PAL_SYS0;
                if( ( NBLK_COL_MSK & block ) == PL_GREEN){
                    palette[FG] = PAL_SYS1;
                }else{
                    palette[FG] = PAL_SYS0;
                }
            }else{
                switch(NBLK_COL_MSK & block){
                    case COL_WHITE:
                        fg_blk_map = 0;
                        bg_blk_map = wt_blk.map;
                        tile_index[FG] = wt_blk_ind;
                        tile_index[BG] = wt_blk_ind;
                        break;
                    case COL_SLOT1:
                        fg_blk_map = clr_blk_sl1.map;
                        bg_blk_map = clr_blk_bg.map;
                        palette[FG] = PAL2;
                        tile_index[FG] = clr_blk_sl1_ind;
                        tile_index[BG] = clr_blk_bg_ind;
                        break;
                    case COL_SLOT2:
                        fg_blk_map = clr_blk_sl0.map;
                        bg_blk_map = clr_blk_bg.map;
                        palette[FG] = PAL3;
                        tile_index[FG] = clr_blk_sl0_ind;
                        tile_index[BG] = clr_blk_bg_ind;
                        break;
                    case COL_SLOT3:
                        fg_blk_map = clr_blk_sl1.map;
                        bg_blk_map = clr_blk_bg.map;
                        palette[FG] = PAL3;
                        tile_index[FG] = clr_blk_sl1_ind;
                        tile_index[BG] = clr_blk_bg_ind;
                        break;
                }
                switch(block & NBLK_TYP_MSK){
                    case BLK_NOTHING:
                        return;
                        break;
                    case BLK_FLAT:
                        map_ind = 0;
                        break;
                    case BLK_DOT:
                        map_ind = 4;
                        break;
                    case BLK_DONUT:
                        map_ind = 8;
                        break;
                    case BLK_CHISEL:
                        map_ind = 0;
                        palette[BG] = PAL_SYS0;
                        bg_blk_map = sp_blk.map;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                    case BLK_NET:
                        map_ind = 8;
                        palette[BG] = PAL_SYS0;
                        bg_blk_map = sp_blk.map;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                    case BLK_QUESTION:
                        map_ind = 4;
                        palette[BG] = PAL_SYS0;
                        bg_blk_map = sp_blk.map;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                }
            }
            if(block & BROKEN) map_ind += 2;
            break;
        case SPECIAL_BLOCK:
            break;
        case GOODIE:
            break;
    }
    /*
    VDP_setMapEx(PLAN_A, bg_blk_map, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX),
            1, 1, 0, 0, 2, 2);
            */
    
    VDP_setMapEx(PLAN_A, bg_blk_map, TILE_ATTR_FULL(palette[BG], FALSE, FALSE, FALSE, tile_index[BG]),
            BLK_TO_TILE(x), BLK_TO_TILE(y), map_ind, 0, 2, 2);
            //1, 1, 2, 0, 2, 2);
    if(fg_blk_map)
        VDP_setMapEx(PLAN_B, fg_blk_map, TILE_ATTR_FULL(palette[FG], FALSE, FALSE, FALSE, tile_index[FG]),
                BLK_TO_TILE(x), BLK_TO_TILE(y), map_ind, 0, 2, 2);
                
}

void eraseBlock(u8 x, u8 y){
    VDP_clearTileMapRect(PLAN_A, BLK_TO_TILE(x), BLK_TO_TILE(y), 2, 2);
    VDP_clearTileMapRect(PLAN_B, BLK_TO_TILE(x), BLK_TO_TILE(y), 2, 2);
}

void load_blk_tiles(u16 ind){
    VDP_loadTileSet(clr_blk_bg.tileset, ind, DMA);
    clr_blk_bg_ind = ind;
    ind += clr_blk_bg.tileset->numTile;
    VDP_loadTileSet(clr_blk_sl0.tileset, ind, DMA);
    clr_blk_sl0_ind = ind;
    ind += clr_blk_sl0.tileset->numTile;
    VDP_loadTileSet(clr_blk_sl1.tileset, ind, DMA);
    clr_blk_sl1_ind = ind;
    ind += clr_blk_sl1.tileset->numTile;
    VDP_loadTileSet(sp_blk.tileset, ind, DMA);
    sp_blk_ind = ind;
    ind += sp_blk.tileset->numTile;
    VDP_loadTileSet(wt_blk.tileset, ind, DMA);
    wt_blk_ind = ind;
    ind += wt_blk.tileset->numTile;
    VDP_loadTileSet(pl_blk_bg.tileset, ind, DMA);
    pl_blk_bg_ind = ind;
    ind += pl_blk_bg.tileset->numTile;
    VDP_loadTileSet(pl_blk_fg.tileset, ind, DMA);
    pl_blk_fg_ind = ind;
    ind += pl_blk_fg.tileset->numTile;
}