#ifndef ENTITIES_H

#define ENTITIES_H

#include <genesis.h>
#include "globals.h"


typedef struct OLDEntity{
    u16 attr;
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    u16 points;
    const SpriteDefinition * sprite_def;
    const u8 * death_sound;
    const u16 death_sound_size;
    void (*const onCrash)();
    void (*const onTrip)();
    void (*const onFall)();
    void (*const onLand)();
    void (*const onAttack)();
    void (*const onFinishAttack)();
}OLDEntity;

#define ENT_CHECK_BITMSK 0x0003

#define BIG_ENTITY   0

#define BIG_ENT_MSK   0x000C

#define BLUE_PLAYER   0x0000 //0b0000000000000000
#define GREEN_PLAYER  0x0004 //0b0000000000000100
#define KNIGHT        0x000C //0b0000000000001100
#define GARGOYLE      0x0008 //0b0000000000001000

#define NASTIE        1

#define MOVT_BITMSK   0x000C //0b0000000000001100

#define STILL         0x0000 //0b0000000000000000
#define WALKS         0x0004 //0b0000000000000100
#define FLIES         0x000C //0b0000000000001100
#define LURKS         0x0008 //0b0000000000001000

#define BRK_BITMSK    0x0030 //B0000000000110000
#define PROJ_BEHAVIOR 0x0070

#define BREAKS        0x0010 //B0000000000010000
#define DELETES       0x0020 //B0000000000100000

#define GOES_THRU     0x0040 //B0000000001000000

#define LEAP_BITMSK   0x0180 //B0000000011000000

#define LEAPS         0x0080 //B0000000010000000
#define DIES_ON_LEAP  0x0100 //B0000000100000000
#define TURNS_ON_LEAP 0x0180 //B0000000110000000

#define CENTERED      0x0200 //B0000001000000000
#define SHOOTS        0x0400 //B0000010000000000
#define NS_FAST       0x0800 //B0000100000000000

#define PROJECTILE     2
#define CREATES_NASTIE 0x0100 //B0000000100000000
#define WHICH_NASTIE(attr) (attr >> 9)

#define FX             3

#define FX_TYP_MSK  0x001C   //B0000000000011100

#define SHRAPNEL    0x0004   //B0000000000000100
#define DELETER     0x0008   //B0000000000001000
#define WAS_GOODIE  0x0010   //B0000000000010000

extern const OLDEntity blue_player_ent;
extern const OLDEntity green_player_ent;

extern const OLDEntity spinner_ent;
extern const OLDEntity robo_ent;
extern const OLDEntity ant_ent;
extern const OLDEntity piggy_ent;
extern const OLDEntity teeth_ent;

extern const OLDEntity ant_spawner_ent;

extern const OLDEntity gd_silvCoin_ent;
extern const OLDEntity gd_arrow_ent;
extern const OLDEntity gd_clk3h_ent;
extern const OLDEntity gd_clk6h_ent;
extern const OLDEntity gd_clk9h_ent;
extern const OLDEntity gd_clk12h_ent;
extern const OLDEntity gd_glass_ent;
extern const OLDEntity gd_shield_ent;
extern const OLDEntity gd_boost_ent;
extern const OLDEntity gd_boot_ent;
extern const OLDEntity gd_thnball_ent;
extern const OLDEntity gd_rdkey_ent;
extern const OLDEntity gd_blkey_ent;
extern const OLDEntity gd_rddoor_ent;
extern const OLDEntity gd_bldoor_ent;
extern const OLDEntity gd_rddoor_open_ent;
extern const OLDEntity gd_bddoor_open_ent;
extern const OLDEntity gd_goldCoin_ent;
extern const OLDEntity gd_1UP_ent;
extern const OLDEntity gd_2x_ent;
extern const OLDEntity gd_3x_ent;
extern const OLDEntity gd_4x_ent;
extern const OLDEntity gd_5x_ent;
extern const OLDEntity gd_ball_ent;
extern const OLDEntity gd_gem_ent;
extern const OLDEntity gd_gold_ent;
extern const OLDEntity gd_turtl_ent;
extern const OLDEntity gd_star_ent;
extern const OLDEntity gd_grkey_ent;
extern const OLDEntity gd_grdoor_ent;
extern const OLDEntity gd_grdoor_open_ent;

extern const OLDEntity arrow_ent;

extern const OLDEntity deletor_ent;
extern const OLDEntity blk_debris0_ent;
extern const OLDEntity blk_debris1_ent;
extern const OLDEntity blk_debris2_ent;
extern const OLDEntity blk_debris3_ent;

extern const OLDEntity * const goodies_vector[];

#endif