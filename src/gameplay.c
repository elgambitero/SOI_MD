#include <genesis.h>

#include "gameplay.h"
#include "board.h"

Board board;

void gameInit();

void gameplayLoop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();
            gameInit();


            gameState = GAME;
            SYS_enableInts();

        break;
        case GAME:
            ACT_update();
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
    
    SPR_init();
    if(!ACT_init()) gameState = GAMEEXIT;
    if(!load_board(&board, current_level)) gameState = GAMEEXIT;

    VDP_drawText("Score", 0, 0);
    VDP_drawText("00000000", 6, 0);
    VDP_drawText("Bonus", 15, 0);
    VDP_drawText("00000", 21, 0);
    VDP_drawText("L:", 27, 0);
    VDP_drawText("3", 29, 0);
    VDP_drawText("Lvl", 33, 0);
    VDP_drawText("001", 37, 0);


}