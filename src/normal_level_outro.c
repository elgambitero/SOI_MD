#include "normal_level_outro.h"

#include <genesis.h>

#include "sfx.h"
#include "player.h"

#include "sprites.h"
#include "images.h"
#include "palettes.h"

#define SCORE_COUNT_X  7
#define SCORE_COUNT_Y  13

#define SCORE_TEXT_Y   4
#define BONUS_TEXT_Y   0
#define WEAP_TEXT_Y 2

#define SCORE_SPACE   18

#define PL_SPR_MIN_X     128
#define PL_SPR_Y         80
#define PL_SPR_MAX_X     176


void NOUT_control(u16 joy, u16 changed, u16 state);
const frame_t * NOUT_fade_in();
const frame_t * NOUT_screen();
const frame_t * NOUT_fade_out();

const frame_t NOUT_fade_in_s = {
    &NOUT_fade_in
};

const frame_t NOUT_fade_out_s = {
    &NOUT_fade_out
};

const frame_t NOUT_screen_s = {
    &NOUT_screen
};

const frame_t NOUT_begin_s = {
    &NOUT_fade_in
};

const frame_t * frame;

cutscene_cb callback;

normal_outro_t * static_self;

normal_outro_t * NOUT_init(
    normal_outro_t * self,
    SOI_game_status_t * status,
    game_config_t * config
)
{
    self->super.vtable_ = BONUS_OUTRO_T;
    self->status = status;
    self->config = config;
    static_self = self;
}

const frame_t * NOUT_begin(
    cutscene_cb exit_callback
)
{
    callback = exit_callback;
    return &NOUT_fade_in_s;
}

void NOUT_prepare_palettes();
void NOUT_draw_borders();
void NOUT_draw_lettering();
uint32_t NOUT_gather_score_from_self()
void NOUT_draw_player_sprites();

const frame_t * NOUT_fade_in(){
    VDP_setPaletteColors(32, (u16*) palette_black, 32);

    u16 palette[64];
    NOUT_load_palettes(palette);

    NOUT_draw_borders();

    NOUT_draw_lettering();

    uint32_t scoreCount = NOUT_gather_score_from_self();

    sprintf(scoreText, "%08lu", scoreCount);
    VDP_drawText(scoreText, SCORE_COUNT_X + SCORE_SPACE, SCORE_COUNT_Y + SCORE_TEXT_Y);

    NOUT_draw_player_sprites();

    VDP_fadeIn(0, 63, palette, 20, FALSE);

}

void NOUT_load_palettes(uint8_t * palette){
    memcpy(&palette[0], pal_sys0.data, 16 * 2);
    memcpy(&palette[16], pal_sys1.data, 16 * 2);

    memcpy(&palette[32], brd_end_1_img.palette->data, 16 * 2);
    memcpy(&palette[48], brd_end_2_img.palette->data, 16 * 2);
}

void NOUT_draw_borders(){
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawImageEx(BG_A, &brd_end_1_img, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, FALSE, TRUE);
    VDP_drawImageEx(BG_B, &brd_end_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + brd_end_1_img.tileset->numTile )), 0, 0, FALSE, TRUE);
}

void NOUT_draw_lettering(){
    VDP_drawText("Bonus", SCORE_COUNT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);
    VDP_drawText("No Weapons Reward", SCORE_COUNT_X, SCORE_COUNT_Y + WEAP_TEXT_Y);
    VDP_drawText("Score", SCORE_COUNT_X, SCORE_COUNT_Y + SCORE_TEXT_Y);
}

uint32_t NOUT_gather_score_from_self(){
    uint32_t score_count = 0;
    for(
        uint8_t i = 0;
        i <= static_self->config->additional_players;
        i++
    )
    {
        uint32_t pl_score = static_self->status->player_stat[i].score;
        score_count += pl_score;
    }
    return score_count;
}

void NOUT_draw_player_sprites(){
    uint8_t players = static_self->config->additional_players + 1;
    uint8_t palette_ind = 0;
    SPR_init();

    for(uint8_t i = 0; i < players; i++){
        uint16_t x_pos = PL_SPR_MIN_X + i * ( PL_SPR_MAX_X - PL_SPR_MIN_X ) / players;
        Sprite * pl = SPR_addSprite(
            &bp_spr, x_pos, PL_SPR_Y,
            TITE_ATTR_FULL(palette_ind, TRUE, FALSE, FALSE, TILE_USERINDEX)
        );
        SPR_setAnim(pl, PL_WALK_RIGHT);
        palette_ind++;
    }
}

const struct cutscene_vtable_ BONUS_OUTRO_T[] = { { &NOUT_begin } };