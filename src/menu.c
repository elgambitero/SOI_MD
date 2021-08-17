#include "SOI.h"

enum MenuStates{
    MENU_IN,
    MENU_LOOP,
    MENU_OUT
};

enum MenuStates state = MENU_IN;

enum MainStates MEN_loop(){
    switch(state){
        case MENU_IN:
            state = MENU_OUT;
            return MAIN_MENU;
        break;
        case MENU_LOOP:
            return MAIN_MENU;
        break;
        case MENU_OUT:
            gameState = GAMEINIT;
            GAM_setGametype(COOPERATE);
            return GAMEPLAY;
        break;
    }
}