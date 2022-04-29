#include <genesis.h>

#include "frame_state.h"
#include "game_modes.h"

#include "title.h"
#include "menu.h"
#include "levels.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif

const frame_t * frame;

void MAIN_init(){

    SYS_disableInts();

    VDP_setScreenWidth320();

    frame = &TIT_begin_s;
    
    SYS_enableInts();
}

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

const frame_t * TIT_out_cb(){
    return MEN_begin(MAX_LEVELS);
}

const frame_t * MEN_end_cb(MEN_config_t config){
    return &TIT_begin_s;
}
