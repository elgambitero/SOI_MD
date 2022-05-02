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
#define WEAP_TEXT_Y    2

#define MULT_X         7

#define SCORE_SPACE   18
#define BONUS_SPACE   21
#define WEAPONS_SPACE 22

#define PL_SPR_MIN_X     128
#define PL_SPR_Y         80
#define PL_SPR_MAX_X     176

#define STEP_FRAMES 30
#define MULTI_FRAMES 15

#define NOWEAP_BONUS 5000


void NOUT_control(u16 joy, u16 changed, u16 state);
const frame_t * NOUT_fade_in();
const frame_t * NOUT_loop_step_1();
const frame_t * NOUT_loop_step_2();
const frame_t * NOUT_loop_step_3();
const frame_t * NOUT_loop_step_4();
const frame_t * NOUT_loop_step_5();
const frame_t * NOUT_loop_step_6();
const frame_t * NOUT_loop_step_7();
const frame_t * NOUT_loop_step_8();
const frame_t * NOUT_loop_step_9();
const frame_t * NOUT_loop_final();
const frame_t * NOUT_fade_out();

const frame_t NOUT_begin_s = {
    &NOUT_fade_in
};

const frame_t NOUT_fade_in_s = {
    &NOUT_fade_in
};

const frame_t NOUT_loop_step_1_s = {
    &NOUT_loop_step_1
};

const frame_t NOUT_loop_step_2_s = {
    &NOUT_loop_step_2
};

const frame_t NOUT_loop_step_3_s = {
    &NOUT_loop_step_3
};

const frame_t NOUT_loop_step_4_s = {
    &NOUT_loop_step_4
};

const frame_t NOUT_loop_step_5_s = {
    &NOUT_loop_step_5
};

const frame_t NOUT_loop_step_6_s = {
    &NOUT_loop_step_6
};

const frame_t NOUT_loop_step_7_s = {
    &NOUT_loop_step_7
};

const frame_t NOUT_loop_step_8_s = {
    &NOUT_loop_step_8
};

const frame_t NOUT_loop_step_9_s = {
    &NOUT_loop_step_9
};

const frame_t NOUT_loop_final_s = {
    &NOUT_loop_final
};

const frame_t NOUT_fade_out_s = {
    &NOUT_fade_out
};

const frame_t * frame;

cutscene_cb callback;

normal_outro_t * NOUT_self;
SOI_game_status_t NOUT_game_status;

uint16_t frame_time;

char NOUT_text_buffer[15];

normal_outro_t * NOUT_init(
    normal_outro_t * self,
    SOI_game_status_t * status,
    game_config_t * config
)
{
    self->super.vtable_ = BONUS_OUTRO_T;
    self->status = status;
    NOUT_game_status = *status;
    self->config = config;
    NOUT_self = self;
    return self;
}

const frame_t * NOUT_begin(
    cutscene_cb exit_callback
)
{
    callback = exit_callback;
    return &NOUT_fade_in_s;
}

void NOUT_load_palettes(uint16_t * palette);
void NOUT_draw_borders();
void NOUT_draw_lettering();
uint32_t NOUT_gather_score_from_static();
void NOUT_draw_player_sprites();

const frame_t * NOUT_fade_in(){
    VDP_setPaletteColors(32, (u16*) palette_black, 32);

    u16 palette[64];
    NOUT_load_palettes(palette);

    NOUT_draw_borders();

    NOUT_draw_lettering();

    uint32_t score_count = NOUT_gather_score_from_static();

    sprintf(NOUT_text_buffer, "%08lu", score_count);
    VDP_drawText(NOUT_text_buffer, SCORE_COUNT_X + SCORE_SPACE, SCORE_COUNT_Y + SCORE_TEXT_Y);

    NOUT_draw_player_sprites();

    VDP_fadeIn(0, 63, palette, 20, FALSE);

    JOY_setEventHandler(&NOUT_control);

    frame_time = STEP_FRAMES;
    frame = &NOUT_loop_step_1_s;
    return frame;
}

void NOUT_load_palettes(uint16_t * palette){
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

uint32_t NOUT_gather_score_from_static(){
    uint32_t score_count = 0;
    for(
        uint8_t i = 0;
        i <= NOUT_self->config->additional_players;
        i++
    )
    {
        uint32_t pl_score = NOUT_game_status.player_stat[i].score;
        score_count += pl_score;
    }
    return score_count;
}

void NOUT_draw_player_sprites(){
    uint8_t players = NOUT_self->config->additional_players + 1;
    uint8_t palette_ind = 0;
    SPR_init();

    for(uint8_t i = 0; i < players; i++){
        uint16_t x_pos = PL_SPR_MIN_X + i * ( PL_SPR_MAX_X - PL_SPR_MIN_X ) / players;
        Sprite * pl = SPR_addSprite(
            &bp_spr, x_pos, PL_SPR_Y,
            TILE_ATTR_FULL(palette_ind, TRUE, FALSE, FALSE, TILE_USERINDEX)
        );
        SPR_setAnim(pl, PL_WALK_RIGHT);
        palette_ind++;
    }
}

uint32_t NOUT_gather_bonus_from_static();

const frame_t * NOUT_loop_step_1(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = STEP_FRAMES;

    SFX_playSound(snd_hait_ID);

    uint32_t bonus_count = NOUT_gather_bonus_from_static();
    sprintf(NOUT_text_buffer, "%05lu", bonus_count);
    VDP_drawText(NOUT_text_buffer, SCORE_COUNT_X + BONUS_SPACE, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = &NOUT_loop_step_2_s;
    return frame;
}

uint32_t NOUT_gather_bonus_from_static(){
    uint32_t bonus_count = 0;
    for(
        uint8_t i = 0;
        i <= NOUT_self->config->additional_players;
        i++
    )
    {
        uint32_t pl_bonus = NOUT_game_status.player_stat[i].score;
        bonus_count += pl_bonus;
    }
    return bonus_count;
}

uint8_t NOUT_advance_bonus_count(){

    uint8_t players = NOUT_self->config->additional_players + 1;
    uint32_t score_count = 0;
    uint8_t finished = FALSE;

    for(uint8_t i = 0; i < players; i++){
        SOI_player_status_t * player = NOUT_game_status.player_stat + i;
        player->score += player->mult ? player->bonus : 0;
        score_count += player->score;
        player->mult--;
        if(!player->mult){
            finished = TRUE;
        }
    }

    sprintf(NOUT_text_buffer, "%08lu", score_count);
    VDP_drawText(NOUT_text_buffer, SCORE_COUNT_X + SCORE_SPACE, SCORE_COUNT_Y + SCORE_TEXT_Y);

    return finished;
}

const frame_t * NOUT_loop_step_2(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    SFX_playSound(snd_huoh_ID);
    frame_time = STEP_FRAMES;

    frame = NOUT_advance_bonus_count() ? &NOUT_loop_step_3_s : &NOUT_loop_step_8_s;
    return frame;
}

const frame_t * NOUT_loop_step_3(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = MULTI_FRAMES;

    SFX_playSound(snd_one_ID);

    VDP_drawText("1x", SCORE_COUNT_X + MULT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = &NOUT_loop_step_4_s;
    return frame;
}

const frame_t * NOUT_loop_step_4(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = MULTI_FRAMES;

    SFX_playSound(snd_two_ID);

    VDP_drawText("2x", SCORE_COUNT_X + MULT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = NOUT_advance_bonus_count() ? &NOUT_loop_step_5_s : &NOUT_loop_step_8_s;
    return frame;
}

const frame_t * NOUT_loop_step_5(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = MULTI_FRAMES;

    SFX_playSound(snd_three_ID);

    VDP_drawText("3x", SCORE_COUNT_X + MULT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = NOUT_advance_bonus_count() ? &NOUT_loop_step_6_s : &NOUT_loop_step_8_s;
    return frame;
}

const frame_t * NOUT_loop_step_6(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = MULTI_FRAMES;

    SFX_playSound(snd_four_ID);

    VDP_drawText("4x", SCORE_COUNT_X + MULT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = NOUT_advance_bonus_count() ? &NOUT_loop_step_7_s : &NOUT_loop_step_8_s;
    return frame;
}

const frame_t * NOUT_loop_step_7(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = MULTI_FRAMES;

    SFX_playSound(snd_five_ID);

    VDP_drawText("5x", SCORE_COUNT_X + MULT_X, SCORE_COUNT_Y + BONUS_TEXT_Y);

    frame = NOUT_advance_bonus_count() ? &NOUT_loop_step_8_s : &NOUT_loop_step_8_s;
    return frame;
}

uint8_t NOUT_check_noweap_from_static();

const frame_t * NOUT_loop_step_8(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = STEP_FRAMES;
    SFX_playSound(snd_hait_ID);

    sprintf(
        NOUT_text_buffer,
        "%04u",
        NOUT_check_noweap_from_static() ? NOWEAP_BONUS : 0000
    );

    VDP_drawText(NOUT_text_buffer, SCORE_COUNT_X + WEAPONS_SPACE, SCORE_COUNT_Y + WEAP_TEXT_Y);

    frame = &NOUT_loop_step_9_s;
    return frame;
}

uint8_t NOUT_check_noweap_from_static(){
    uint8_t players = NOUT_self->config->additional_players + 1;
    for(uint8_t i = 0; i < players; i++){
        SOI_player_status_t * player = NOUT_game_status.player_stat + i;
        if(player->noweap)
            return TRUE;
    }
    return FALSE;
}

uint32_t NOUT_add_noweap_bonus_to_score();

const frame_t * NOUT_loop_step_9(){
    SPR_update();

    if(frame_time){
        frame_time--;
        return frame;
    }

    frame_time = STEP_FRAMES;

    SFX_playSound(snd_huoh_ID);

    if(NOUT_check_noweap_from_static()){
        uint32_t score_count = NOUT_add_noweap_bonus_to_score();

        sprintf(NOUT_text_buffer, "%08lu", score_count);
        VDP_drawText(NOUT_text_buffer, SCORE_COUNT_X + SCORE_SPACE, SCORE_COUNT_Y + SCORE_TEXT_Y);
    }

    frame = &NOUT_loop_final_s;
    return frame;
}

uint32_t NOUT_add_noweap_bonus_to_score(){
    uint32_t score_count = NOUT_gather_score_from_static();
    uint8_t players = NOUT_self->config->additional_players + 1;
    score_count += players * NOWEAP_BONUS;
    return score_count;
}

const frame_t * NOUT_loop_final(){
    SPR_update();
    return frame;
}

const frame_t * NOUT_fade_out(){
    VDP_fadeOut(0, 63, 20, FALSE);
    SPR_end();
    return (*callback)();
}

void NOUT_control(u16 joy, u16 changed, u16 state){
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            frame = &NOUT_fade_out_s;
        }
    }
}

const struct cutscene_vtable_ BONUS_OUTRO_T[] = { { &NOUT_begin } };