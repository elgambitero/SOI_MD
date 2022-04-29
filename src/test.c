#include <genesis.h>

#include "test.h"

#define HEADER "SOI_MD test unit"

void TST_lock();
void TST_erase_screen();

const char start_level_txt[10];
const char start_level_set_txt[10];
const char num_players_txt[10];
const char seed_txt[10];

#define GMCFG_INDENT 20

void TST_game_config(game_config_t config){
    TST_erase_screen();

    VDP_drawText("start_level: ", 0, 1);
    VDP_drawText("start_level_set: ", 0, 2);
    VDP_drawText("num_players: ", 0, 3);
    VDP_drawText("seed: ", 0, 4);

    u16 * seedPtr = (u16*) config.seed;

    sprintf(start_level_txt, "%05d", config.start_level);
    sprintf(start_level_set_txt, "%05d", config.start_level_set);
    sprintf(num_players_txt, "%05d", config.num_players);
    sprintf(seed_txt, "%05u", *seedPtr);

    VDP_drawText(start_level_txt, GMCFG_INDENT, 1);
    VDP_drawText(start_level_set_txt, GMCFG_INDENT, 2);
    VDP_drawText(num_players_txt, GMCFG_INDENT, 3);
    VDP_drawText(seed_txt, GMCFG_INDENT, 4);

    TST_lock();
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