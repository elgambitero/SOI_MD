#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <genesis.h>

#include "states.h"
#include "board.h"

#define X 0
#define Y 1

#define SCREEN_WIDTH 40
#define SCREEN_HEIGHT 30

#define MAX_PLAYERS 2

#define PASSING_PLAYER 0x0000

const Board * current_level;
Actor * blue_player;
Actor * green_player;

u8 bl_ctrl, gr_ctrl;

#define CTRL_DIR_MSK 0x03


#define CTRL_LEFT    0x01
#define CTRL_MOV     0x02

#define CTRL_ALT     0x04

#define CTRL_FIRE    0x08
#define CTRL_BLOCK   0x10
#define CTRL_JUMP    0x20



enum GameStates{
    GAMEINIT,
    INITBOARD,
    GAME,
    ENDBOARD,
    AFTERBOARD,
    NEXTBOARD,
    GAMEENDING,
    GAMEEXIT
};

enum GameStates gameState;

static inline void controls_3(u8 * ctrl, u16 changed, u16 state){
    if(changed & BUTTON_LEFT){
        if(state & BUTTON_LEFT) *ctrl |= ( CTRL_MOV | CTRL_LEFT );
        else *ctrl &= ~CTRL_DIR_MSK;
    }
    if(changed & BUTTON_RIGHT){
        if(state & BUTTON_RIGHT) {
            *ctrl |= CTRL_MOV;
            *ctrl &= ~CTRL_LEFT;
        }
        else *ctrl &= ~CTRL_DIR_MSK;
    }
    if(changed & BUTTON_DOWN){
        if(state & BUTTON_DOWN) *ctrl |= CTRL_ALT;
        else *ctrl &= ~CTRL_ALT;
    }
    if(changed & BUTTON_A){
        if(state & BUTTON_A) *ctrl |= CTRL_FIRE;
        else *ctrl &= ~CTRL_FIRE;
    }
    if(changed & BUTTON_B){
        if(state & BUTTON_B) *ctrl |= CTRL_BLOCK;
        else *ctrl &= ~CTRL_BLOCK;
    }
    if(changed & BUTTON_C){
        if(state & BUTTON_C) *ctrl |= CTRL_JUMP;
        else *ctrl &= ~CTRL_JUMP;
    }
    if(changed & BUTTON_START){

    }
}

static inline void game_controls(u16 joy, u16 changed, u16 state){
    switch(joy){
        case JOY_1:
            if(blue_player){
                controls_3(&bl_ctrl, changed, state);
            }
        break;
        case JOY_2:
            if(green_player){
                controls_3(&gr_ctrl, changed, state);
            }
        break;
    }
}

void gameplayLoop();

#endif