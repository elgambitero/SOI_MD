#include <genesis.h>

#include "menu.h"

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

void MEN_controls(u16 joy, u16 changed, u16 state)
const frame_t * MEN_init();
const frame_t * MEN_loop();
const frame_t * MEN_out();

const frame_t MEN_in_s = {
    &MEN_init
};
const frame_t MEN_loop_s = {
    &MEN_loop
};
const frame_t MEN_out_s = {
    &MEN_out
};

const frame_t * frame;

MEN_config_t config;

u8 numText[6];

u8 pressed;

u8 max_levels;

const frame_t * MEN_begin(uint8_t max){
    max_levels = max;
    return &MEN_in_s
}

const frame_t * MEN_init(){
    JOY_setEventHandler( &MEN_controls );

    VDP_setPalette(PAL0, palette_grey);

    MEN_canvas_init();
    MEN_seed_init();
    MEN_config_init();

    pressed = 0;

    frame = MEN_loop_s;
    return frame;
}

const frame_t * MEN_loop(){
    MEN_seed_update();

    MEN_canvas_update();

    return frame;
}

const frame_t * MEN_out(){
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    gameState = GAMEINIT;
    GAM_setGametype(COOPERATE);
    GAM_setPlayers(config.num_players);
    GAM_setStartingBoard(config.first_level);
    return MEN_out(config);
}

void MEN_controls(u16 joy, u16 changed, u16 state){
    if(changed & BUTTON_RIGHT){
        if(state & BUTTON_RIGHT){
            if(!pressed){
                pressed = 1;
                if(config.first_level >= 0 && config.first_level < max_levels - 1){
                    config.first_level++;
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
                if(config.first_level > 0 && config.first_level <= max_levels - 1){
                    config.first_level--;
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
                    config.num_players = !config.num_players;
                }
            }else{
                pressed = 0;
            }
        }
        if(changed & BUTTON_DOWN){
            if(state & BUTTON_DOWN){
                if(!pressed){
                    pressed = 1;
                    config.num_players = !config.num_players;
                }
            }else{
                pressed = 0;
            }
        }
    }
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            XGM_stopPlay();
            frame = &MEN_out_s;
        }
    }
    break;
}

void MEN_canvas_init(){
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawText("STEP ON IT MD", 13, TITLE_Y);
    VDP_drawText("A -> Weapon, B -> Block, C -> Jump", 3, CONTROLS_Y_BUTTONS);
    VDP_drawText("Left/Right -> Move", 10, CONTROLS_Y_ARROWS);
    VDP_drawText("Down -> Alt. action", 10, CONTROLS_Y_DOWN);
    VDP_drawText("Shareware version", 11, SUBTITLE_Y);
    VDP_drawText("< > Set starting board: ", 6, START_BOARD_Y);
    VDP_drawText("Press start button", 11, PRESS_START_Y);
    VDP_drawText("^ v ", 11, PLAYERS_Y);
}

void MEN_canvas_update(){
    sprintf(numText, "%03d", config.first_level);

    VDP_drawText(numText, 30, START_BOARD_Y);
    
    if(config.num_players){
        VDP_drawText("Two Players", 15,PLAYERS_Y);
    }else{
        VDP_drawText("One Player ", 15,PLAYERS_Y);
    }
}

void MEN_seed_init(){
    seed[0] = 0xFF;
    seed[1] = 0xFF;
}

void MEN_seed_update(){
    seed[0] -= 3;
    seed[1] -= 5;
}

void MEN_config_init(){
    config.first_level = 1;
    config.num_players = 0;
    config.seed[0] = 0;
    config.seed[1] = 1;

}