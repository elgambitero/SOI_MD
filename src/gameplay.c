#include "SOI.h"

#include "palettes.h"
#include "stage.h"

Board board;

u8 colors[4];
u16 ind;
u16 frmInd;

u16 levelInd;

u8 gameType;
u16 bonusCount;

char strBuf[8];

void GAM_gameInit();
void GAM_levelInit();
void GAM_drawFrame();
void VDP_drawNumber(u16 number, u8 chars, u8 xpos, u8 ypos);


void gameplayLoop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();
            GAM_gameInit();

            gameState = INITBOARD;
            SYS_enableInts();
        break;
        case INITBOARD:
            SYS_disableInts();
            GAM_levelInit();

            gameState = GAME;
            SYS_enableInts();
        break;
        case GAME:
            PHY_send_inputs(bl_ctrl, gr_ctrl);
            PHY_update();
            SPR_update();
            //VDP_drawNumber(bonusCount, N_BONUS, X_BONUS, 0);
            if((!blue_player || bl_stat->effect == PASSING) &&
                (!green_player || gr_stat->effect == PASSING)){
                gr_stat->effect = 0;
                bl_stat->effect = 0;
                PAL_fadeOut(0, 63, 60, FALSE);
                gameState = ENDBOARD;
            }
        break;
        case ENDBOARD:
            PHY_end();
            unload_board(&board);
            gameState = AFTERBOARD;
        break;
        case AFTERBOARD:
            gameState = NEXTBOARD;
        break;
        case NEXTBOARD:
            levelInd++;
            if(levelInd == max_levels)
            {
                gameState = GAMEENDING;
                break;
            }
            gameState = INITBOARD;
        break;
        case GAMEENDING:
            //VDP_resetScreen();
            SPR_end();
            VDP_clearPlan(PLAN_A, TRUE);
            VDP_clearPlan(PLAN_B, TRUE);
            XGM_stopPlay();
            PAL_setColor(15, 0x0FFF);
            VDP_drawTextBG(PLAN_A,"Thank you for playing", 5, 10);
            gameState = GAMEEXIT;
        break;
        case GAMEEXIT:
            /*
            VDP_clearPlan(PLAN_A, TRUE);
            VDP_clearPlan(PLAN_B, TRUE);
            VDP_clearPlan(PLAN_WINDOW, TRUE);

            VDP_setHorizontalScroll(PLAN_A, 0);
            VDP_setHorizontalScroll(PLAN_B, 0);
            VDP_setVerticalScroll(PLAN_A, 0);
            VDP_setVerticalScroll(PLAN_B, 0);
            VDP_setBackgroundColor(0);

            gameState = GAMEINIT;
            mainState = MAIN_MENU;
            */
        break;
    }
}

void GAM_gameInit(){
    levelInd = 0;
}

void GAM_levelInit(){

    current_level = levels[levelInd];

    ind = TILE_USERINDEX;
    blue_player = NULL;
    green_player = NULL;
    bl_ctrl = 0;
    gr_ctrl = 0;

    bl_stats.lives = 3;
    bl_stats.balls = 3;
    bl_stats.arrows = 3;
    bl_stats.score = 0;
    bl_stats.speed = PL_WALKSPEED;
    
    gr_stats.lives = 3;
    gr_stats.balls = 3;
    gr_stats.arrows = 3;
    gr_stats.score = 0;
    gr_stats.speed = PL_WALKSPEED;
    
    VDP_setPalette(PAL0, pal_sys0.data);
    VDP_setPalette(PAL1, pal_sys1.data);

    GAM_drawFrame();

    load_blk_tiles(ind);

    SPR_init();
    
    if(!PHY_init(&board, &bl_stats, &gr_stats)) {
        SYS_die("Error when initializing Physics");
    }
    
    if(!load_board(&board, current_level)) {
        SYS_die("Error when loading the Board");
    }

    blue_player = ACT_seek(&PL_blue, &players);
    green_player = ACT_seek(&PL_green, &players);

    if(JOY_getPortType(PORT_2) == PORT_TYPE_UNKNOWN){
        ACT_remove(green_player, &players);
        green_player = 0;
    }

    load_board_palettes(&board);
    draw_board(&board);
    play_board_music(&board);
    bonusCount = board.bonus;

    VDP_drawText("Score", 0, 0);
    VDP_drawText("00000000", X_SCORE, 0);
    VDP_drawText("Bonus", 15, 0);
    VDP_drawNumber(5000, N_BONUS, X_BONUS, 0);
    VDP_drawText("L:", 27, 0);
    VDP_drawText("3", X_LIVES, 0);
    VDP_drawText("Lvl", 33, 0);
    VDP_drawNumber(levelInd, N_LEVEL, X_LEVEL, 0);

}

void GAM_drawFrame(){
    VDP_loadTileSet(main_frame.tileset, ind, DMA);
    frmInd = ind;
    ind += main_frame.tileset->numTile;

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 0, 0, 0, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 0, 3, 0, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 27, 0, 3, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 27, 3, 3, 1, 1);
    
    for(u8 i = 0; i < 19; i++){
        VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                1+i*2, 0, 1, 0, 2, 1);

        VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                1+i*2, 27, 1, 3, 2, 1);
    }

    for(u8 i = 0; i < 13; i++){
        VDP_setMapEx(PLAN_A, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 1 + i*2, 0, 1, 1, 2);

        VDP_setMapEx(PLAN_A, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 1 + i*2, 3, 1, 1, 2);
    }
}


void VDP_drawNumber(u16 number, u8 chars, u8 xpos, u8 ypos){
    sprintf(strBuf,"%d", number);
    VDP_drawText(strBuf, xpos, ypos);
}

void GAM_setGametype(u8 game_type){
    gameType = game_type;
}