#include "SOI.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif


enum MainStates mainState;

u16 ind;

void myJoyHandler(u16 joy, u16 changed, u16 state)
{
    switch(mainState){
        case INTRO:

        break;
        case MAIN_MENU:
            MEN_controls(changed, state);
        break;
        case GAMEPLAY:
            game_controls(joy, changed, state);
        break;
    }
}

void game_init(){

    SYS_disableInts();

    JOY_init();
    JOY_setEventHandler( &myJoyHandler );
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
                gameplayLoop(ind);
            break;
        }

		VDP_waitVSync();
	}
	return 0;
}
