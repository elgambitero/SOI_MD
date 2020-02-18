#include <genesis.h>

#include "gameplay.h"
#include "sprites.h"

Sprite* spinner;
Sprite* smiley;

u16 ind = TILE_USERINDEX;

u8 sm_pos = 160;

void gameplayLoop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();

            gameState = GAME;
            SPR_init(0, 0, 0);

            spinner = SPR_addSprite(&spinner_spr, 160, 100, TILE_ATTR_FULL(PAL2, TRUE, FALSE, FALSE,ind));
            VDP_setPalette(PAL2, spinner_spr.palette->data);

            smiley = SPR_addSprite(&smiley_spr, 160, 116, TILE_ATTR_FULL(PAL3, TRUE, FALSE, FALSE,ind));
            VDP_setPalette(PAL3, smiley_spr.palette->data);

            SPR_setAnim(spinner, 0);
            SPR_setAnim(smiley, 0);

            SYS_enableInts();
        break;
        case GAME:
            SPR_update();
            sm_pos += 1;
            SPR_setPosition(smiley, sm_pos, 116);
        break;
        case GAMEENDING:

        break;
        case GAMEEXIT:
            VDP_clearPlan(PLAN_A, TRUE);
            VDP_clearPlan(PLAN_B, TRUE);
            VDP_clearPlan(PLAN_WINDOW, TRUE);

            VDP_setHorizontalScroll(PLAN_A, 0);
            VDP_setHorizontalScroll(PLAN_B, 0);
            VDP_setVerticalScroll(PLAN_A, 0);
            VDP_setVerticalScroll(PLAN_B, 0);
            VDP_setBackgroundColor(0);

            gameState = GAMEINIT;
            mainState = MAIN_MENU;
        break;
    }
}