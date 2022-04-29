#include "title.h"

#include <genesis.h>

#include "music.h"
#include "images.h"

void TIT_control(u16 joy, u16 changed, u16 state);
const frame_t * TIT_fade_in();
const frame_t * TIT_screen();
const frame_t * TIT_fade_out();

const frame_t TIT_fade_in_s = {
    &TIT_fade_in
};

const frame_t TIT_fade_out_s = {
    &TIT_fade_out
};

const frame_t TIT_screen_s = {
    &TIT_screen
};

const frame_t TIT_begin_s = {
    &TIT_fade_in
};

const frame_t * TIT_fade_in(){

    JOY_init();
    JOY_setEventHandler( &TIT_control );

    VDP_setPaletteColors(32, (u16*) palette_black, 32);
    u16 palette[32];
    memcpy(&palette[0], title_1_img.palette->data, 16 * 2);
    memcpy(&palette[16], title_2_img.palette->data, 16 * 2);
    XGM_startPlay(heavy3);
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawImageEx(BG_A, &title_1_img, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, FALSE, TRUE);
    VDP_drawImageEx(BG_B, &title_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + title_1_img.tileset->numTile )), 0, 0, FALSE, TRUE);
    // fade in
    VDP_fadeIn(32, 63 , palette, 20, FALSE);
    return &TIT_screen_s;
}

const frame_t * TIT_screen(){
    return &TIT_screen_s;
}

const frame_t * TIT_fade_out(){
    VDP_fadeOut(32, 63, 20, FALSE);
    return TIT_out();
}

void TIT_control(u16 joy, u16 changed, u16 state){
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            //title_frame = &TIT_fade_out_s;
        }
    }
}