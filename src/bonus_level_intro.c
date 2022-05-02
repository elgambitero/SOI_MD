#include "cutscene.h"

#include <genesis.h>

#include "sfx.h"

#include "images.h"

const frame_t * frame;

cutscene_cb callback;

void BNS_control(uint16_t joy, uint16_t changed, uint16_t state);
const frame_t * BNS_fade_in();
const frame_t * BNS_screen();
const frame_t * BNS_fade_out();

const frame_t BNS_fade_in_s = {
    &BNS_fade_in
};

const frame_t BNS_fade_out_s = {
    &BNS_fade_out
};

const frame_t BNS_screen_s = {
    &BNS_screen
};

static const frame_t * begin(
    cutscene_cb exit_callback
)
{
    callback = exit_callback;
    return &BNS_fade_in_s;
}

const frame_t * BNS_fade_in(){
    XGM_stopPlay();

    VDP_setPaletteColors(32, (u16*) palette_black, 32);
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    //Dangerous underflow.
    VDP_drawImageEx(
        BG_A,
        &bns_begin_1_img,
        TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX + IMAGE_OFFSET),
        0, -1, FALSE, TRUE
    );
    VDP_drawImageEx(BG_B, &bns_begin_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + IMAGE_OFFSET + bns_begin_1_img.tileset->numTile )), 0, -1, FALSE, TRUE);

    u16 palette[32];
    memcpy(&palette[0], bns_begin_1_img.palette->data, 16 * 2);
    memcpy(&palette[16], bns_begin_2_img.palette->data, 16 * 2);
    VDP_fadeIn(32, 63 , palette, 20, FALSE);

    SFX_playSound(snd_bonus_start_ID);

    JOY_setEventHandler(&BNS_control);

    frame = &BNS_screen_s;
    return frame;
}

const frame_t * BNS_screen(){
    return frame;
}

const frame_t * BNS_fade_out(){
    VDP_fadeOut(32, 63, 20, FALSE);
    return (*callback)();
}

void BNS_control(uint16_t joy, uint16_t changed, uint16_t state){
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            frame = &BNS_fade_out_s;
        }
    }
}

const struct cutscene_vtable_ BONUS_STAGE_T[] = { { &begin } };