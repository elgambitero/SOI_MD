#include "entities.h"

#include "sprites.h"
#include "sound.h"
#include "behavior.h"

const Entity blue_player_ent = {
    BLUE_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &bp_spr,
    snd_player_death,
    sizeof(snd_player_death),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity green_player_ent = {
    GREEN_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &bp_spr,
    snd_player_death,
    sizeof(snd_player_death),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity ant_spawner_ent = {
    NASTIE | STILL | CREATES_NASTIE,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    0,
    0,
    0,
    0,
    NULL,
    NULL,
    NST_still_fall,
    NST_still_land,
    NULL,
    NULL
};

const Entity spinner_ent = {
    NASTIE | STILL,
    {6, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &spinner_spr,
    0,
    0,
    NULL,
    NULL,
    &NST_still_fall,
    &NST_still_land,
    NULL,
    NULL
};

const Entity robo_ent = {
    NASTIE | WALKS | DIES_ON_LEAP | BREAKS | GOES_THRU,
    {4, 15},
    {7, 15},
    PAL_SYS0,
    1000,
    &robo_spr,
    snd_robo,
    sizeof(snd_robo),
    &NST_attack,
    &NST_turn_around,
    &NST_fall,
    &NST_die,
    &NST_breaks,
    &NST_keep_walking
};

const Entity ant_ent = {
    NASTIE | WALKS | LEAPS,
    {7, 8},
    {7, 8},
    PAL_SYS0,
    50,
    &ant_spr,
    snd_ant,
    sizeof(snd_ant),
    &NST_turn_around,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    NULL,
    NULL
};

const Entity piggy_ent = {
    NASTIE | WALKS | LEAPS | DELETES,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    250,
    &piggy_spr,
    snd_piggy,
    sizeof(snd_piggy),
    &NST_attack,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    &NST_deletes,
    &NST_turn_around_fast
};

const Entity teeth_ent = {
    NASTIE | WALKS | LEAPS | DELETES | GOES_THRU,
    {8, 15},
    {8, 15},
    PAL_SYS0,
    1500,
    &teeth_spr,
    snd_teeth,
    sizeof(snd_teeth),
    &NST_deletes_and_keeps_going,
    NULL,
    &NST_fall,
    &NST_keep_walking,
    &NST_deletes,
    &NST_keep_walking
};

const Entity arrow_ent = {
    PROJECTILE | FLIES ,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &arrow_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_silvCoin_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    500,
    &gd_sys0_spr,
    snd_silver_coin,
    sizeof(snd_silver_coin),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_arrow_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_arrow,
    sizeof(snd_arrow),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_clk3h_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_clock,
    sizeof(snd_clock),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_clk6h_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_clock,
    sizeof(snd_clock),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_clk9h_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_clock,
    sizeof(snd_clock),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_clk12h_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_clock,
    sizeof(snd_clock),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_glass_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_glass,
    sizeof(snd_glass),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_shield_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_shield,
    sizeof(snd_shield),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_boot_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_boot,
    sizeof(snd_boot),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_thnball_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_thunderball,
    sizeof(snd_thunderball),
    &GD_obtain,
    &GD_killSpawned,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_rdkey_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_key,
    sizeof(snd_key),
    &GD_obtain,
    &GD_openRdDoor,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_blkey_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_key,
    sizeof(snd_key),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_rddoor_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_bldoor_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_rddoor_open_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_door_exit,
    sizeof(snd_door_exit),
    &GD_enterRdDoor,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_bddoor_open_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &gd_sys0_spr,
    snd_door_exit,
    sizeof(snd_door_exit),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_goldCoin_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_gold_coin,
    sizeof(snd_gold_coin),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_1UP_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_1up,
    sizeof(snd_1up),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_2x_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_multiplier,
    sizeof(snd_multiplier),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_3x_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_multiplier,
    sizeof(snd_multiplier),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_4x_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_multiplier,
    sizeof(snd_multiplier),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_5x_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_multiplier,
    sizeof(snd_multiplier),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_ball_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_ball,
    sizeof(snd_ball),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_gem_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_gem,
    sizeof(snd_gem),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_gold_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_goldbar,
    sizeof(snd_goldbar),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_turtl_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_turtle,
    sizeof(snd_turtle),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_star_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    0,
    0,
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_grkey_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_key,
    sizeof(snd_key),
    &GD_obtain,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_grdoor_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity gd_grdoor_open_ent = {
    FX | WAS_GOODIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    0,
    &gd_sys1_spr,
    snd_door_exit,
    sizeof(snd_door_exit),
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};


const Entity deletor_ent = {
    FX | DELETER,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    0,
    &deletor_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris0_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris0_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris1_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris1_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris2_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris2_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity blk_debris3_ent = {
    FX | SHRAPNEL,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    0,
    &blk_debris3_spr,
    0,
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

const Entity * const goodies_vector[] = {
    &gd_silvCoin_ent,
    &gd_arrow_ent,
    &gd_clk3h_ent,
    &gd_clk6h_ent,
    &gd_clk9h_ent,
    &gd_clk12h_ent,
    &gd_glass_ent,
    &gd_shield_ent,
    &gd_boot_ent,
    &gd_thnball_ent,
    &gd_rdkey_ent,
    &gd_blkey_ent,
    &gd_rddoor_ent,
    &gd_bldoor_ent,
    &gd_rddoor_open_ent,
    &gd_bddoor_open_ent,
    &gd_goldCoin_ent,
    &gd_1UP_ent,
    &gd_2x_ent,
    &gd_3x_ent,
    &gd_4x_ent,
    &gd_5x_ent,
    &gd_ball_ent,
    &gd_gem_ent,
    &gd_gold_ent,
    &gd_turtl_ent,
    &gd_star_ent,
    &gd_grkey_ent,
    &gd_grdoor_ent,
    &gd_grdoor_open_ent,
};