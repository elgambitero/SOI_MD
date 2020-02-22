#ifndef ENTITIES_H

#define ENTITIES_H

#include <genesis.h>
#include "sprites.h"

#define SIZE_X(size) (size && B00001111)
#define SIZE_Y(size) (size >> 4)

typedef struct Entity{
    u16 attr;
    u8 size;
    Palette * palette;
    SpriteDefinition * sprite_def;
}Entity;

#define ENT_CHECK_BITMSK B0000000000000011

#define BIG_ENTITY   0

#define BLUE_PLAYER   B0000000000000000
#define GREEN_PLAYER  B0000000000000100
#define KNIGHT        B0000000000001100
#define GARGOYLE      B0000000000001000

#define NASTIE        1

#define MOVT_BITMSK   B0000000000001100

#define STILL         B0000000000000000
#define WALKS         B0000000000000100
#define FLIES         B0000000000001100
#define LURKS         B0000000000001000

#define BRK_BITMSK    B0000000000110000

#define BREAKS        B0000000000010000
#define BREAKS_THRU   B0000000000110000

#define LEAP_BITMSK   B0000000011000000

#define LEAPS         B0000000001000000
#define DIES_ON_LEAP  B0000000011000000
#define TURNS_ON_LEAP B0000000010000000

#define CENTERED      B0000000100000000
#define SHOOTS        B0000001000000000

#define PROJECTILE     2
#define CREATES_NASTIE B0000000100000000
#define WHICH_NASTIE(attr) (attr >> 9)


#endif