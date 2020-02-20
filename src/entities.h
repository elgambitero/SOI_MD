#ifndef ENTITIES_H

#define ENTITIES_H

#include <genesis.h>
#include "sprites.h"

#define SIZE_X(size) (size && B00001111)
#define SIZE_Y(size) (size >> 4)

typedef struct{
    u8 attributes,
    u8 size,
    Palette * palette,
    SpriteDefinition * sprite_def
}Entity;

#define PLAYER       0
#define BLUE_PLAYER  B00000000
#define GREEN_PLAYER B00000100

#define NASTIE       1
#define BREAKS       B00000100
#define BREAKS_THRU  B00001100
#define LEAPS        B00010000
#define DIES_ON_LEAP B00110000
#define LURKS        B00100000
#define IS_FAST      B01000000
#define SHOOTS       B10000000
#define INMOVILE     B00101000
#define IS_BLOCK     B00111000

#define NASTIE(attr) (attr >> 4)

#define PROJECTILE     2
#define CREATES_NASTIE B00001000

#define LURKS          B00010000
#define FLIES          B00100000


#endif