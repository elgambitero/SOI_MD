#include "SOI.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif


enum MainStates mainState;

u16 ind;

void game_init(){

    SYS_disableInts();

    JOY_init();
    VDP_setScreenWidth320();


    mainState = MAIN_MENU;
    

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
            case MAIN_MENU:
                mainState = MEN_loop();
            break;
            case GAMEPLAY:
                mainState = GAM_loop(ind);
            break;
        }

		VDP_waitVSync();
	}
	return 0;
}
