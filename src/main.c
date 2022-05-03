#include <genesis.h>

#include "frame_state.h"
#include "random.h"

#include "game_config.h"
#include "rom_levels.h"

#include "menu.h"
#include "starter.h"
#include "cutscene.h"
#include "normal_level_outro.h"

#include "test.h"

#define PAL

#ifdef NTSC
    #define FRAMES 60
#else
    #define FRAMES 50
#endif

const frame_t * MAIN_init();
const frame_t * TIT_out_cb();

const frame_t * frame;

int main()
{
    frame = MAIN_init();

    while(1)
	{
        frame = (*frame->calc_frame)();

		VDP_waitVSync();
	}
	return 0;
}

const frame_t * MAIN_init(){

    SYS_disableInts();

    VDP_setScreenWidth320();
    
    cutscene_t title = { TITLE_SCREEN_T };

    SYS_enableInts();

    return CTS_play(
        &title,
        &TIT_out_cb
    );

}

const frame_t * TIT_out_cb(){
    return MEN_begin(&rom_levels);
}

const frame_t * MEN_end_cb(game_config_t config){
    u16 * seedPtr = (u16*) config.seed;
    RNG_seed( *seedPtr );
    //TST_game_config(&config);
    SOI_game_status_t status = STR_create_game_status(
        &config
    );
    //TST_game_status(&status);
    const SOI_level_t * first_level = LVL_get_level_from_indices(
        config.start_level_set,
        config.start_level
    );

    return CTS_play(
        &(first_level->intro),
        &TST_normal_outro
    );
}
