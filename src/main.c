#include "SOI.h"

#include "music.h"
#include "images.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif


enum MainStates mainState;

void MAIN_titleControl(u16 joy, u16 changed, u16 state){
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            mainState = TITLE_SCREEN_OUT;
        }
    }
}

void game_init(){

    SYS_disableInts();

    JOY_init();
    JOY_setEventHandler( &MAIN_titleControl );
    VDP_setScreenWidth320();


    mainState = TITLE_SCREEN_IN;
    

    SYS_enableInts();
}

int main()
{
    game_init();

    while(1)
	{
        switch(mainState){
            case INTRO:

            break;
            case TITLE_SCREEN_IN:
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
                mainState = TITLE_SCREEN;
                break;
            case TITLE_SCREEN:

                break;
            case TITLE_SCREEN_OUT:
                VDP_fadeOut(32, 63, 20, FALSE);
                mainState = MEN_init();
                break;
            case MAIN_MENU:
                mainState = MEN_loop();
            break;
            case GAMEPLAY:
                mainState = GAM_loop();
            break;
        }

		VDP_waitVSync();
	}
	return 0;
}
