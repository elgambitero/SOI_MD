#include <genesis.h>

#include "frame_state.h"

#include "title.h"

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

const frame_t * TIT_out(){
    return &TIT_begin_s;
}
