#include "SOI.h"

#include "images.h"
#include "music.h"
#include "palettes.h"

#define TITLE_Y 3
#define SUBTITLE_Y 5
#define CONTROLS_Y_ARROWS  10
#define CONTROLS_Y_BUTTONS 8
#define CONTROLS_Y_DOWN    12
#define START_BOARD_Y 18
#define PLAYERS_Y    20
#define PRESS_START_Y 24

enum MenuStates{
    MENU_IN,
    MENU_LOOP,
    MENU_OUT
};


u8 numText[6];
enum MenuStates menuState = MENU_IN;

u8 firstLevel;
u8 numPlayers;
u8 pressed;
u8 seed[2];

enum MainStates MEN_init(){
    firstLevel = 1;
    numPlayers = 0;
    pressed = 0;
    seed[0] = 0;
    seed[1] = 1;
    menuState = MENU_IN;
    return MAIN_MENU;
}

enum MainStates MEN_loop(){
    switch(menuState){
        case MENU_IN:
            JOY_setEventHandler( &MEN_controls );
            VDP_setPalette(PAL0, palette_grey);
            menuState = MENU_LOOP;
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            VDP_drawText("STEP ON IT MD", 13, TITLE_Y);
            VDP_drawText("A -> Weapon, B -> Block, C -> Jump", 3, CONTROLS_Y_BUTTONS);
            VDP_drawText("Left/Right -> Move", 10, CONTROLS_Y_ARROWS);
            VDP_drawText("Down -> Alt. action", 10, CONTROLS_Y_DOWN);
            VDP_drawText("60 levels version", 11, SUBTITLE_Y);
            VDP_drawText("< > B C Set starting board: ", 4, START_BOARD_Y);
            VDP_drawText("Press start button", 11, PRESS_START_Y);
            VDP_drawText("^ v ", 11, PLAYERS_Y);
            seed[0] = 0xFF;
            seed[1] = 0xFF;
            return MAIN_MENU;
        break;
        case MENU_LOOP:
            sprintf(numText, "%03d", firstLevel);
            VDP_drawText(numText, 32, START_BOARD_Y);
            seed[0] -= 3;
            seed[1] -= 5;
            if(numPlayers){
                VDP_drawText("Two Players", 15,PLAYERS_Y);
            }else{
                VDP_drawText("One Player ", 15,PLAYERS_Y);
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

void MEN_controls(u16 joy, u16 changed, u16 state){
    switch(menuState){
        case MENU_LOOP:
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
            if(changed & BUTTON_C){
                if(state & BUTTON_C){
                    if(!pressed){
                        pressed = 1;
                        if(firstLevel >= 0 && firstLevel < max_levels - 10){
                            firstLevel += 10;
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
            if(changed & BUTTON_B){
                if(state & BUTTON_B){
                    if(!pressed){
                        pressed = 1;
                        if(firstLevel > 10 && firstLevel <= max_levels - 1){
                            firstLevel -= 10;
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
                    u16 seed_in = (seed[1] << 8) | seed[0] ;
                    RNG_seed( seed_in );
                    XGM_stopPlay();
                    menuState = MENU_OUT;
                }
            }
            break;
    }
    
}