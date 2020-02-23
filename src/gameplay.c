#include <genesis.h>

#include "gameplay.h"
#include "board.h"

Board board;

void game_init();

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
            SPR_update();
        break;
        case GAMEENDING:

        break;
        case GAMEEXIT:
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
        break;
    }
}

void gameInit(){
    
    if(!ACT_init()) gameState = GAMEEXIT;
    if(!load_board(&board, current_level)) gameState = GAMEEXIT;
    SPR_init();


}