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
    TITLE_SCREEN_IN,
    TITLE_SCREEN,
    MENU_IN,
    MENU_LOOP,
    MENU_OUT
};


u8 numText[6];
enum MenuStates menuState = TITLE_SCREEN_IN;

u8 firstLevel = 1;
u8 numPlayers = 0;
u8 pressed = 0;
u8 seed[2];

enum MainStates MEN_loop(){
    switch(menuState){
        case TITLE_SCREEN_IN:
            XGM_startPlay(heavy3);
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            VDP_drawImageEx(BG_A, &title_1_img, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, TRUE, TRUE);
            VDP_drawImageEx(BG_B, &title_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + title_1_img.tileset->numTile )), 0, 0, TRUE, TRUE);
            menuState = TITLE_SCREEN;
            return MAIN_MENU;
        case TITLE_SCREEN:

            return MAIN_MENU;
        case MENU_IN:
            VDP_setPalette(PAL0, palette_grey);
            menuState = MENU_LOOP;
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            VDP_drawText("STEP ON IT MD", 13, TITLE_Y);
            VDP_drawText("A -> Weapon, B -> Block, C -> Jump", 3, CONTROLS_Y_BUTTONS);
            VDP_drawText("Left/Right -> Move", 10, CONTROLS_Y_ARROWS);
            VDP_drawText("Down -> Alt. action", 10, CONTROLS_Y_DOWN);
            VDP_drawText("Playable technical demo", 8, SUBTITLE_Y);
            VDP_drawText("< > Set starting board: ", 6, START_BOARD_Y);
            VDP_drawText("Press start button", 11, PRESS_START_Y);
            VDP_drawText("^ v ", 11, PLAYERS_Y);
            seed[0] = 0xFF;
            seed[1] = 0xFF;
            return MAIN_MENU;
        break;
        case MENU_LOOP:
            sprintf(numText, "%03d", firstLevel);
            VDP_drawText(numText, 30, START_BOARD_Y);
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

void MEN_controls(u16 changed, u16 state){
    switch(menuState){
        case TITLE_SCREEN:
            if(changed & BUTTON_START){
                if(state & BUTTON_START){
                    menuState = MENU_IN;
                }
            }
            break;
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
                    u16 seed_in = (seed[1] << 8) | seed[0] ;
                    RNG_seed( seed_in );
                    menuState = MENU_OUT;
                }
            }
            break;
    }
    
}