#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "states.h"

#define X 0
#define Y 1

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 30

enum GameStates{
    GAMEINIT,
    GAME,
    GAMEENDING,
    GAMEEXIT
};

enum GameStates gameState;

static inline void gameControls(u16 joy, u16 changed, u16 state){
    if(joy == JOY_1){
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
}

void gameplayLoop();

#endif