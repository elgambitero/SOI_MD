#include "SOI.h"

#include "stage.h"

#define BLK_TO_TILE(x) (1 + x*2)
#define FG 0
#define BG 1


//These could be too many bytes.
//Predictable as BLK_load_tiles() is, these could be macros.
u16 clr_blk_bg_ind = TILE_USERINDEX;
u16 clr_blk_sl0_ind = TILE_USERINDEX;
u16 clr_blk_sl1_ind = TILE_USERINDEX;
u16 sp_blk_ind = TILE_USERINDEX;
u16 wt_blk_ind = TILE_USERINDEX;
u16 pl_blk_fg_ind = TILE_USERINDEX;
u16 pl_blk_bg_ind = TILE_USERINDEX;
u16 gd_sys0_ind = TILE_USERINDEX;
u16 gd_sys1_ind = TILE_USERINDEX;
u16 tele_bg_ind = TILE_USERINDEX;
u16 tele_sl0_ind = TILE_USERINDEX;
u16 tele_sl1_ind = TILE_USERINDEX;
u16 tele_sl2_ind = TILE_USERINDEX;
u16 cannon_blk_ind = TILE_USERINDEX;
u16 flop_bg_ind = TILE_USERINDEX;
u16 flop_sl0_ind = TILE_USERINDEX;
u16 flop_sl1_ind = TILE_USERINDEX;
u16 flop_sl2_ind = TILE_USERINDEX;
u16 gate_bg_opn_ind = TILE_USERINDEX;
u16 gate_bg_cls_ind = TILE_USERINDEX;
u16 gate_sl0_ind = TILE_USERINDEX;
u16 gate_sl1_ind = TILE_USERINDEX;
u16 gate_sl2_ind = TILE_USERINDEX;
u16 kn_good_ind = TILE_USERINDEX;
u16 spawners_ind = TILE_USERINDEX;

void BLK_drawBlock(u8 x, u8 y, u16 block){
    u8 map_ind = 0;
    u8 good_ind;
    u16 tile_index[2] = {0, 0};
    u8 palette[2] = {PAL2, PAL2};
    TileMap * fg_blk_map;
    TileMap * bg_blk_map;
    if(x >= BOARD_X || y >= BOARD_Y || !block)
        return;
    switch(block & BLK_TYPE){
        case NORMAL_BLOCK:
            if( ( NBLK_TYP_MSK & block ) == BLK_PLAYER ){
                fg_blk_map = pl_blk_fg.tilemap;
                bg_blk_map = pl_blk_bg.tilemap;
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
                        bg_blk_map = wt_blk.tilemap;
                        tile_index[FG] = wt_blk_ind;
                        tile_index[BG] = wt_blk_ind;
                        break;
                    case COL_SLOT1:
                        fg_blk_map = clr_blk_sl1.tilemap;
                        bg_blk_map = clr_blk_bg.tilemap;
                        palette[FG] = PAL2;
                        tile_index[FG] = clr_blk_sl1_ind;
                        tile_index[BG] = clr_blk_bg_ind;
                        break;
                    case COL_SLOT2:
                        fg_blk_map = clr_blk_sl0.tilemap;
                        bg_blk_map = clr_blk_bg.tilemap;
                        palette[FG] = PAL3;
                        tile_index[FG] = clr_blk_sl0_ind;
                        tile_index[BG] = clr_blk_bg_ind;
                        break;
                    case COL_SLOT3:
                        fg_blk_map = clr_blk_sl1.tilemap;
                        bg_blk_map = clr_blk_bg.tilemap;
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
                        bg_blk_map = sp_blk.tilemap;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                    case BLK_NET:
                        map_ind = 8;
                        palette[BG] = PAL_SYS0;
                        bg_blk_map = sp_blk.tilemap;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                    case BLK_QUESTION:
                        map_ind = 4;
                        palette[BG] = PAL_SYS0;
                        bg_blk_map = sp_blk.tilemap;
                        fg_blk_map = 0;
                        tile_index[BG] = sp_blk_ind;
                        break;
                }
            }
            if(block & BROKEN) map_ind += 2;
            break;
        case SPECIAL_BLOCK:
            switch(block & SP_TYP_MSK){
                case SP_TRANS:
                    bg_blk_map = tele_bg.tilemap;
                    tile_index[BG] = tele_bg_ind;
                    map_ind = block & TRANS_DIR_MSK ? 0 : 2;
                    switch(block & SP_COL_MSK){
                        case SP_COL_GR:
                            fg_blk_map = tele_sl0.tilemap;
                            tile_index[FG] = tele_sl0_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_PI:
                            fg_blk_map = tele_sl1.tilemap;
                            tile_index[FG] = tele_sl1_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_YL:
                            fg_blk_map = tele_sl2.tilemap;
                            tile_index[FG] = tele_sl2_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_BL:
                            fg_blk_map = tele_sl0.tilemap;
                            tile_index[FG] = tele_sl0_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_R:
                            fg_blk_map = tele_sl1.tilemap;
                            tile_index[FG] = tele_sl1_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_WT:
                            fg_blk_map = tele_sl2.tilemap;
                            tile_index[FG] = tele_sl2_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                    }
                    break;
                case SP_CANNON:
                    bg_blk_map = cannon_blk.tilemap;
                    tile_index[BG] = cannon_blk_ind;
                    map_ind = block & CAN_DIR_MSK ? 2 : 0;
                    break;
                case SP_FLOP:
                    bg_blk_map = flop_bg.tilemap;
                    tile_index[BG] = flop_bg_ind;
                    map_ind = block & FLOP_TOG_MSK ? 0 : 2;
                    switch(block & SP_COL_MSK){
                        case SP_COL_GR:
                            fg_blk_map = flop_sl0.tilemap;
                            tile_index[FG] = flop_sl0_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_PI:
                            fg_blk_map = flop_sl1.tilemap;
                            tile_index[FG] = flop_sl1_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_YL:
                            fg_blk_map = flop_sl2.tilemap;
                            tile_index[FG] = flop_sl2_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_BL:
                            fg_blk_map = flop_sl0.tilemap;
                            tile_index[FG] = flop_sl0_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_R:
                            fg_blk_map = flop_sl1.tilemap;
                            tile_index[FG] = flop_sl1_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_WT:
                            fg_blk_map = flop_sl2.tilemap;
                            tile_index[FG] = flop_sl2_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                    }
                    break;
                case SP_GATE:
                    map_ind = 0;
                    switch(block & GATE_MSK){
                        case GATE_OPEN:
                            bg_blk_map = gate_bg_opn.tilemap;
                            tile_index[BG] = gate_bg_opn_ind;
                            palette[BG] = PAL_SYS1;
                            break;
                        case GATE_CLOSED:
                            bg_blk_map = gate_bg_cls.tilemap;
                            tile_index[BG] = gate_bg_cls_ind;
                            palette[BG] = PAL_SYS0;
                            break;
                    }
                    switch(block & SP_COL_MSK){
                        case SP_COL_GR:
                            fg_blk_map = gate_sl0.tilemap;
                            tile_index[FG] = gate_sl0_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_PI:
                            fg_blk_map = gate_sl1.tilemap;
                            tile_index[FG] = gate_sl1_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_YL:
                            fg_blk_map = gate_sl2.tilemap;
                            tile_index[FG] = gate_sl2_ind;
                            palette[FG] = PAL_SYS1;
                            break;
                        case SP_COL_BL:
                            fg_blk_map = gate_sl0.tilemap;
                            tile_index[FG] = gate_sl0_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_R:
                            fg_blk_map = gate_sl1.tilemap;
                            tile_index[FG] = gate_sl1_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                        case SP_COL_WT:
                            fg_blk_map = gate_sl2.tilemap;
                            tile_index[FG] = gate_sl2_ind;
                            palette[FG] = PAL_SYS0;
                            break;
                    }
                    break;
                case SP_SPAWNER:
                    palette[BG] = PAL_SYS0;
                    bg_blk_map = spawners_blk.tilemap;
                    tile_index[BG] = spawners_ind;
                    map_ind = ((block & NASTIE_MSK) >> NASTIE_SHFT) * 2;
                    break;
            }
            break;
        case GOODIE:
            //goodie index should translate into tile index, SYS0 and SYS1 goodies should be consecutive.
            good_ind = GD_GET_INDEX( block );
            if(good_ind < GD_GET_INDEX( GDi_KNGOOD )){
                map_ind = (good_ind << 1);
                tile_index[FG] = gd_sys0_ind;
                fg_blk_map = gd_sys0.tilemap;
                palette[FG] = PAL_SYS0;
            }else{
                if(good_ind == GD_GET_INDEX( GDi_KNGOOD )){
                    map_ind = 0;
                    tile_index[FG] = kn_good_ind;
                    fg_blk_map = kn_good.tilemap;
                    palette[FG] = PAL_SYS0;
                }else{
                    good_ind -= (GD_GET_INDEX( GDi_KNGOOD ) + 1);
                    map_ind = (good_ind << 1);
                    tile_index[FG] = gd_sys1_ind;
                    fg_blk_map = gd_sys1.tilemap;
                    palette[FG] = PAL_SYS1;
                }
            }
            VDP_setMapEx(BG_B, fg_blk_map, TILE_ATTR_FULL(palette[FG], FALSE, FALSE, FALSE, tile_index[FG]),
                BLK_TO_TILE(x), BLK_TO_TILE(y), map_ind, 0, 2, 2);
            return;
            break;
        default:
            return;
            break;
    }
    
    VDP_setMapEx(BG_A, bg_blk_map, TILE_ATTR_FULL(palette[BG], FALSE, FALSE, FALSE, tile_index[BG]),
            BLK_TO_TILE(x), BLK_TO_TILE(y), map_ind, 0, 2, 2);
    if(fg_blk_map)
        VDP_setMapEx(BG_B, fg_blk_map, TILE_ATTR_FULL(palette[FG], FALSE, FALSE, FALSE, tile_index[FG]),
                BLK_TO_TILE(x), BLK_TO_TILE(y), map_ind, 0, 2, 2);
}

void BLK_eraseBlock(u8 x, u8 y){
    VDP_clearTileMapRect(BG_A, BLK_TO_TILE(x), BLK_TO_TILE(y), 2, 2);
    VDP_clearTileMapRect(BG_B, BLK_TO_TILE(x), BLK_TO_TILE(y), 2, 2);
}

void BLK_eraseBlock_ind(u8 ind){
    VDP_clearTileMapRect(BG_A, BLK_TO_TILE(IND_TO_X(ind)), BLK_TO_TILE(IND_TO_Y(ind)), 2, 2);
    VDP_clearTileMapRect(BG_B, BLK_TO_TILE(IND_TO_X(ind)), BLK_TO_TILE(IND_TO_Y(ind)), 2, 2);
}

void BLK_load_tiles(u16 ind){
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
    VDP_loadTileSet(gd_sys0.tileset, ind, DMA);
    gd_sys0_ind = ind;
    ind += gd_sys0.tileset->numTile;
    VDP_loadTileSet(gd_sys1.tileset, ind, DMA);
    gd_sys1_ind = ind;
    ind += gd_sys1.tileset->numTile;
    VDP_loadTileSet(tele_bg.tileset, ind, DMA);
    tele_bg_ind = ind;
    ind += tele_bg.tileset->numTile;
    VDP_loadTileSet(tele_sl0.tileset, ind, DMA);
    tele_sl0_ind = ind;
    ind += tele_sl0.tileset->numTile;
    VDP_loadTileSet(tele_sl1.tileset, ind, DMA);
    tele_sl1_ind = ind;
    ind += tele_sl1.tileset->numTile;
    VDP_loadTileSet(tele_sl2.tileset, ind, DMA);
    tele_sl2_ind = ind;
    ind += tele_sl2.tileset->numTile;
    VDP_loadTileSet(cannon_blk.tileset, ind, DMA);
    cannon_blk_ind = ind;
    ind += cannon_blk.tileset->numTile;
    VDP_loadTileSet(flop_bg.tileset, ind, DMA);
    flop_bg_ind = ind;
    ind += flop_bg.tileset->numTile;
    VDP_loadTileSet(flop_sl0.tileset, ind, DMA);
    flop_sl0_ind = ind;
    ind += flop_sl0.tileset->numTile;
    VDP_loadTileSet(flop_sl1.tileset, ind, DMA);
    flop_sl1_ind = ind;
    ind += flop_sl1.tileset->numTile;
    VDP_loadTileSet(flop_sl2.tileset, ind, DMA);
    flop_sl2_ind = ind;
    ind += flop_sl2.tileset->numTile;
    VDP_loadTileSet(gate_bg_opn.tileset, ind, DMA);
    gate_bg_opn_ind = ind;
    ind += gate_bg_opn.tileset->numTile;
    VDP_loadTileSet(gate_bg_cls.tileset, ind, DMA);
    gate_bg_cls_ind = ind;
    ind += gate_bg_cls.tileset->numTile;
    VDP_loadTileSet(gate_sl0.tileset, ind, DMA);
    gate_sl0_ind = ind;
    ind += gate_sl0.tileset->numTile;
    VDP_loadTileSet(gate_sl1.tileset, ind, DMA);
    gate_sl1_ind = ind;
    ind += gate_sl1.tileset->numTile;
    VDP_loadTileSet(gate_sl2.tileset, ind, DMA);
    gate_sl2_ind = ind;
    ind += gate_sl2.tileset->numTile;
    VDP_loadTileSet(kn_good.tileset, ind, DMA);
    kn_good_ind = ind;
    ind += kn_good.tileset->numTile;
    VDP_loadTileSet(spawners_blk.tileset, ind, DMA);
    spawners_ind = ind;
    ind += spawners_blk.tileset->numTile;
}