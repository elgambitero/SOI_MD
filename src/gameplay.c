#include <genesis.h>

#include "gameplay.h"
#include "board.h"
#include "stage.h"
#include "physics.h"
#include "palettes.h"

Board board;

u8 colors[4];
u16 ind;

void gameInit();
void drawFrame();

void gameplayLoop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();
            gameInit();


            gameState = GAME;
            SYS_enableInts();

        break;
        case GAME:
            //ACT_update();
        break;
        case GAMEENDING:

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

void gameInit(){
    ind = TILE_USERINDEX;
    
    VDP_setPalette(PAL0, pal_sys0.data);
    VDP_setPalette(PAL1, pal_sys1.data);

    drawFrame();

    //SPR_init();
    //PHY_init(&board);
    //if(!ACT_init()) gameState = GAMEEXIT;
    //if(!load_board(&board, current_level)) gameState = GAMEEXIT;

    VDP_drawText("Score", 0, 0);
    VDP_drawText("00000000", 6, 0);
    VDP_drawText("Bonus", 15, 0);
    VDP_drawText("00000", 21, 0);
    VDP_drawText("L:", 27, 0);
    VDP_drawText("3", 29, 0);
    VDP_drawText("Lvl", 33, 0);
    VDP_drawText("001", 37, 0);



}

void drawFrame(){
    VDP_loadTileSet(main_frame.tileset, ind, DMA);

    ind += main_frame.tileset->numTile;

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                0, 0, 0, 0, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                39, 0, 3, 0, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                0, 27, 0, 3, 1, 1);

    VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                39, 27, 3, 3, 1, 1);
    
    for(u8 i = 0; i < 19; i++){
        VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                1+i*2, 0, 1, 0, 2, 1);

        VDP_setMapEx(PLAN_B, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                1+i*2, 27, 1, 3, 2, 1);
    }

    for(u8 i = 0; i < 13; i++){
        VDP_setMapEx(PLAN_A, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                0, 1 + i*2, 0, 1, 1, 2);

        VDP_setMapEx(PLAN_A, main_frame.map, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USERINDEX),
                39, 1 + i*2, 3, 1, 1, 2);
    }

}