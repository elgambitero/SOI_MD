#include "SOI.h"

enum MenuStates{
    MENU_IN,
    MENU_LOOP,
    MENU_OUT
};


u8 numText[6];
enum MenuStates menuState = MENU_IN;

u8 firstLevel = 1;
u8 numPlayers = 0;
u8 pressed = 0;

enum MainStates MEN_loop(){
    switch(menuState){
        case MENU_IN:
            menuState = MENU_LOOP;
            VDP_drawText("STEP ON IT MD alpha4", 10, 3);
            VDP_drawText("Set starting board: ", 10, 14);
            return MAIN_MENU;
        break;
        case MENU_LOOP:
            sprintf(numText, "%03d", firstLevel);
            VDP_drawText(numText, 30, 14);
            //JOY_getPortType(PORT_2) == PORT_TYPE_UNKNOWN
            if(numPlayers){
                VDP_drawText("Two Players", 15, 20);
            }else{
                VDP_drawText("One Player ", 15, 20);
            }
            return MAIN_MENU;
        break;
        case MENU_OUT:
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            gameState = GAMEINIT;
            GAM_setGametype(COOPERATE);
            GAM_setPlayers(numPlayers);
            GAM_setStartingBoard(firstLevel);
            return GAMEPLAY;
        break;
    }
    return MAIN_MENU;
}

void MEN_controls(u16 changed, u16 state){
    if(changed & BUTTON_RIGHT){
        if(state & BUTTON_RIGHT){
            if(!pressed){
                pressed = 1;
                if(firstLevel >= 0 && firstLevel < max_levels - 1){
                    firstLevel++;
                }
            }
        }else{
            pressed = 0;
        }
    }
    if(changed & BUTTON_LEFT){
        if(state & BUTTON_LEFT){
            if(!pressed){
                pressed = 1;
                if(firstLevel > 0 && firstLevel <= max_levels - 1){
                    firstLevel--;
                }
            }
        }else{
            pressed = 0;
        }
    }
    if(JOY_getPortType(PORT_2) != PORT_TYPE_UNKNOWN){
        if(changed & BUTTON_UP){
            if(state & BUTTON_UP){
                if(!pressed){
                    pressed = 1;
                    numPlayers = !numPlayers;
                }
            }else{
                pressed = 0;
            }
        }
        if(changed & BUTTON_DOWN){
            if(state & BUTTON_DOWN){
                if(!pressed){
                    pressed = 1;
                    numPlayers = !numPlayers;
                }
            }else{
                pressed = 0;
            }
        }
    }
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            menuState = MENU_OUT;
        }
    }
}