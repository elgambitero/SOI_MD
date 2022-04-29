#include <genesis.h>

#include "frame_state.h"

#include "game_config.h"

#include "title.h"
#include "menu.h"
#include "levels.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif

void MAIN_init();

const frame_t * frame;

int main()
{
    MAIN_init();

    while(1)
	{
        frame = (*frame->calc_frame)();

		VDP_waitVSync();
	}
	return 0;
}

void MAIN_init(){

    SYS_disableInts();

    VDP_setScreenWidth320();

    frame = TIT_begin();

    SYS_enableInts();
}

const frame_t * TIT_out_cb(){
    return MEN_begin(MAX_LEVELS);
}

const frame_t * MEN_end_cb(game_config_t config){
    return TIT_begin();
}
