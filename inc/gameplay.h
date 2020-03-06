#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "states.h"
#include "board.h"

#define X 0
#define Y 1

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 30

const Board * current_level;
Actor * blue_player;
Actor * green_player;

enum GameStates{
    GAMEINIT,
    GAME,
    GAMEENDING,
    GAMEEXIT
};

enum GameStates gameState;

static inline void gameControls(u16 joy, u16 changed, u16 state){
    switch(joy){
        case JOY_1:
            if(blue_player){
                if(state & BUTTON_LEFT){

                }
                if(state & BUTTON_UP){

                }
                if(state & BUTTON_RIGHT){

                }
                if(state & BUTTON_DOWN){

                }
                if(state & BUTTON_START){
                    
                }
            }
        break;
        case JOY_2:
            if(green_player){
                if(state & BUTTON_LEFT){

                }
                if(state & BUTTON_UP){

                }
                if(state & BUTTON_RIGHT){

                }
                if(state & BUTTON_DOWN){

                }
                if(state & BUTTON_START){
                    
                }
            }
        break;
    }
    
}

void gameplayLoop();

#endif