#ifndef ENTITIES_H

#define ENTITIES_H

#include <genesis.h>
#include "globals.h"

#define SIZE_X(size) (size & 0x0F)
#define SIZE_Y(size) (size >> 4)
#define CODE_SIZE(x, y) (x + (y << 4))

typedef struct Entity{
    u16 attr;
    u8 size;
    u8 spr_pos;
    u8 palette;
    const SpriteDefinition * sprite_def;
}Entity;

#define ENT_CHECK_BITMSK 0x0003

#define BIG_ENTITY   0

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

#define FX_TYP_MSK  0x000C   //B0000000100000000

#define SHRAPNEL    0x0004   //B0000000000000100
#define DELETER     0x0008   //B0000000000001000
#define CREATOR     0x000C   //B0000000000001100

extern const Entity blue_player_ent;
extern const Entity spinner_ent;
extern const Entity robo_ent;
extern const Entity ant_ent;

extern const Entity blk_debris0_ent;
extern const Entity blk_debris1_ent;
extern const Entity blk_debris2_ent;
extern const Entity blk_debris3_ent;

#endif