#include <genesis.h>

#include "test.h"

#define HEADER "SOI_MD test unit"

#define FIELD_SIZE 10

void TST_lock();
void TST_erase_screen();

const char text_buffer[FIELD_SIZE];

#define GMCFG_INDENT 20
#define GMSTS_INDENT 15

void TST_game_config(game_config_t * config){
    TST_erase_screen();

    VDP_drawText("start_level: ", 0, 1);
    VDP_drawText("start_level_set: ", 0, 2);
    VDP_drawText("additional_players: ", 0, 3);
    VDP_drawText("seed: ", 0, 4);

    u16 * seedPtr = (u16*) config->seed;

    sprintf(text_buffer, "%05u", config->start_level);
    VDP_drawText(text_buffer, GMCFG_INDENT, 1);

    sprintf(text_buffer, "%05u", config->start_level_set);
    VDP_drawText(text_buffer, GMCFG_INDENT, 2);

    sprintf(text_buffer, "%05u", config->additional_players);
    VDP_drawText(text_buffer, GMCFG_INDENT, 3);

    sprintf(text_buffer, "%05u", *seedPtr);
    VDP_drawText(text_buffer, GMCFG_INDENT, 4);

    TST_lock();
}

void TST_print_game_status_header();
void TST_print_player_game_status(
    SOI_game_status_t * status,
    uint8_t player_index
);

void TST_game_status(SOI_game_status_t * status){
    TST_erase_screen();

    TST_print_game_status_header();

    sprintf(text_buffer, "%05d", status->current_level);
    VDP_drawText(text_buffer, GMSTS_INDENT, 1);

    sprintf(text_buffer, "%05d", status->level_set_ind);
    VDP_drawText(text_buffer, GMSTS_INDENT, 2);

    TST_print_player_game_status(status, 0);
    TST_print_player_game_status(status, 1);

    TST_lock();
}

void TST_print_game_status_header(){
    VDP_drawText("current_level: ", 0, 1);
    VDP_drawText("level_set_ind: ", 0, 2);
    VDP_drawText("Player stats: ", 0, 3);
}

void TST_print_player_game_status(
    SOI_game_status_t * status,
    uint8_t player_index
)
{
    VDP_drawText("score: " , 0, 4 + player_index * 6);
    VDP_drawText("bonus: " , 0, 5 + player_index * 6);
    VDP_drawText("mult: " , 0, 6 + player_index * 6);
    VDP_drawText("arrows: " , 0, 7 + player_index * 6);
    VDP_drawText("balls: " , 0, 8 + player_index * 6);
    VDP_drawText("lives: " , 0, 9 + player_index * 6);

    sprintf(text_buffer, "%08u" , status->player_stat[player_index].score);
    VDP_drawText(text_buffer, GMSTS_INDENT, 4 + player_index * 6);

    sprintf(text_buffer, "%05u" , status->player_stat[player_index].bonus);
    VDP_drawText(text_buffer, GMSTS_INDENT, 5 + player_index * 6);

    sprintf(text_buffer, "%05u" , status->player_stat[player_index].mult);
    VDP_drawText(text_buffer, GMSTS_INDENT, 6 + player_index * 6);

    sprintf(text_buffer, "%05u" , status->player_stat[player_index].arrows);
    VDP_drawText(text_buffer, GMSTS_INDENT, 7 + player_index * 6);

    sprintf(text_buffer, "%05u" , status->player_stat[player_index].balls);
    VDP_drawText(text_buffer, GMSTS_INDENT, 8 + player_index * 6);

    sprintf(text_buffer, "%05u" , status->player_stat[player_index].lives);
    VDP_drawText(text_buffer, GMSTS_INDENT, 9 + player_index * 6);

}

void TST_erase_screen(){
    SPR_end();
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawText(HEADER, 0, 0);
}

void TST_lock(){
    while(1){
		VDP_waitVSync();
    }
}

const game_config_t passing_config = {
    12,
    1,
    1,
    {42, 42},
    NULL
};

const SOI_game_status_t passing_status = {
    12,
    1,
    {
        {
            0,
            1500,
            1,
            3,
            3,
            3
        },
        {
            0,
            1500,
            1,
            3,
            3,
            3
        }
    }
};