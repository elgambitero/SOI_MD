#include "goodies.h"

#include "physics.h"
#include "gameplay.h"
#include "blocks.h"

#include "sound.h"
#include "sprites.h"

void GD_obtain();
void GD_killAll();
void GD_killSpawned();
void GD_openRdDoor();
void GD_enterRdDoor();




//TODO: Fix FX | WAS_GOODIE for something more specific.
const Entity GD_silvCoin = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            500,
            snd_silver_coin,
            sizeof(snd_silver_coin),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_arrow = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_arrow,
            sizeof(snd_arrow),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_clk3h = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_clk6h = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_clk9h = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_clk12h = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_glass = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_glass,
            sizeof(snd_glass),
            NULL,
            NULL
        }
    }
};

const Entity GD_shield = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_shield,
            sizeof(snd_shield),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_boot = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_boot,
            sizeof(snd_boot),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_thnball = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_thunderball,
            sizeof(snd_thunderball),
            &GD_obtain,
            &GD_killSpawned
        }
    }
};

const Entity GD_rdkey = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            &GD_openRdDoor
        }
    }
};

const Entity GD_blkey = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_rddoor = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

const Entity GD_bldoor = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

const Entity GD_rddoor_open = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            &GD_enterRdDoor,
            NULL
        }
    }
};

const Entity GD_bddoor_open = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            NULL,
            NULL
        }
    }
};

const Entity GD_goldCoin = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_gold_coin,
            sizeof(snd_gold_coin),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_1UP = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_1up,
            sizeof(snd_1up),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_2x = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_3x = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_4x = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_5x = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_ball = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_ball,
            sizeof(snd_ball),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_gem = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_gem,
            sizeof(snd_gem),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_gold = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_goldbar,
            sizeof(snd_goldbar),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_turtl = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_turtle,
            sizeof(snd_turtle),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_star = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            0,
            0,
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_grkey = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_grdoor = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

const Entity GD_grdoor_open = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            NULL,
            NULL
        }
    }
};





const Entity * const goodies_vector[] = {
    &GD_silvCoin,
    &GD_arrow,
    &GD_clk3h,
    &GD_clk6h,
    &GD_clk9h,
    &GD_clk12h,
    &GD_glass,
    &GD_shield,
    &GD_boot,
    &GD_thnball,
    &GD_rdkey,
    &GD_blkey,
    &GD_rddoor,
    &GD_bldoor,
    &GD_rddoor_open,
    &GD_bddoor_open,
    &GD_goldCoin,
    &GD_1UP,
    &GD_2x,
    &GD_3x,
    &GD_4x,
    &GD_5x,
    &GD_ball,
    &GD_gem,
    &GD_gold,
    &GD_turtl,
    &GD_star,
    &GD_grkey,
    &GD_grdoor,
    &GD_grdoor_open,
};




void GD_obtain(){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 8;
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind)) + 8;
    fx.frames = 0;
    fx.character = goodies_vector[gd_index];
    fx.speed[X] = 0;
    fx.speed[Y] = -BRK_SPEED;
    Actor * result = ACT_add(&fx, &fx_buf);
    if(result){
        if(gd_index >= GD_GET_INDEX( GDi_GOLDC ) ) gd_index -= GD_GET_INDEX( GDi_GOLDC );
        SPR_setFrame(result->sprite, gd_index);
    }
    break_block_ind(env, front_ind);
}

void GD_killAll(){
    Actor * nastie = ACT_getFirst(&nasties);
    while(nastie){
        kill(nastie, 0, -2*FALLSPEED);
        nastie = nastie->next;
    }
}

void GD_killSpawned(){
    Actor * nastie = ACT_getFirst(&nasties);
    while(nastie){
        if(nastie->timer) kill(nastie, 0, -2*FALLSPEED);
        nastie = nastie->next;
    }
}

void GD_openRdDoor(){
    u16 index = seek_block(env, (GOODIE | GDi_RDDOOR) );
    if(index != BOARD_NOTFOUND){
        set_block(env, (GOODIE | GDi_RDDOOR_open), index);
    }else{
        //this crashes the game on purpose
        SYS_die("Red Door not found");
    }
}

void GD_enterRdDoor(){
    if(curr == blue_player){
        blue_player = PASSING_PLAYER;
        result = ACT_DELETION;
        return;
    }
    if(curr == green_player){
        green_player = PASSING_PLAYER;
        result = ACT_DELETION;
        return;
    }
}