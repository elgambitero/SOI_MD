#include <genesis.h>

#include "states.h"
#include "gameplay.h"
#include "levels.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif

u16 palette[64];
u16 ind;

void myJoyHandler(u16 joy, u16 changed, u16 state)
{
    if(joy == JOY_1){
        switch(mainState){
            case INTRO:

            break;
            case MAIN_MENU:

            break;
            case GAMEPLAY:

            break;
        }
    }
}

void game_init(){

    SYS_disableInts();

    JOY_init();
    JOY_setEventHandler( &myJoyHandler );
    VDP_setScreenWidth320();

    current_level = &test_level;

    mainState = GAMEPLAY;
    gameState = GAMEINIT;
    

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

            break;
            case GAMEPLAY:
                gameplayLoop(ind);
            break;
        }

		VDP_waitVSync();
	}
	return 0;
}
