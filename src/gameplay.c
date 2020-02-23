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

    VDP_drawText("SOI test", 7, 5);


}