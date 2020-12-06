#ifndef ENTITIES_H

#define ENTITIES_H

#include <genesis.h>

#include "states.h"

typedef struct Nastie{
    const u8 * death_sound;
    const u16 death_sound_size;
    
    u16 points;

    void (*const onCrash)();
    void (*const onTrip)();
    void (*const onFall)();
    void (*const onLand)();
    void (*const onAttack)();
    void (*const onFinishAttack)();
}Nastie;

typedef struct FX{
}FX;


typedef struct Player{
    const u8 * death_sound;
    const u16 death_sound_size;
    PlayerStat * const statistics;
}Player;


typedef struct Projectile{

    void (*const onFire)();

    void (*const onCrash)();
}Projectile;


typedef struct Goodie{
    u16 points;
    const u8 * pickup_sound;
    const u16 pickup_sound_size;

    void (*const onCrash)();
    void (*const onPickUp)();
}Goodie;



typedef struct Entity{
    u16 attr;
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    const SpriteDefinition * sprite_def;

    union Role{
        const Player player;
        const Nastie nastie;
        const Goodie goodie;
        const FX effect;
        const Projectile proj;
    }role;
}Entity;

#include "globals.h"

#define ENT_CHECK_BITMSK 0x0003

#define BIG_ENTITY   0

#define PLAYER_MSK   0x0018 //B0000000000011000

#define BLUE_PLAYER   0x0000 //B0000000000000000
#define GREEN_PLAYER  0x0008 //B0000000000001000
#define RED_PLAYER        0x0018 //B0000000000011000
#define PINK_PLAYER      0x0010 //B0000000000010000

#define NASTIE        1

#define MOVT_BITMSK   0x0018 //B0000000000011000

#define STILL         0x0000 //B0000000000000000
#define WALKS         0x0008 //B0000000000001000
#define FLIES         0x0018 //B0000000000011000
#define LURKS         0x0010 //B0000000000010000

#define BRK_BITMSK    0x00C0 //B0000000001100000
#define PROJ_BEHAVIOR 0x01C0 //B0000000111000000

#define BREAKS        0x0020 //B0000000000100000
#define DELETES       0x0040 //B0000000001000000

#define GOES_THRU     0x0080 //B0000000010000000

#define LEAP_BITMSK   0x0300 //B0000000110000000

#define LEAPS         0x0100 //B0000000100000000
#define DIES_ON_LEAP  0x0200 //B0000001000000000
#define TURNS_ON_LEAP 0x0300 //B0000001100000000

#define CENTERED      0x0400 //B0000010000000000
#define SHOOTS        0x0800 //B0000100000000000
#define NS_FAST       0x1000 //B0001000000000000

#define PROJECTILE     2
#define CREATES_NASTIE 0x0200 //B0000001000000000
#define WHICH_NASTIE(attr) (attr >> 10)

#define FX             3

#define FX_TYP_MSK  0x0038   //B0000000000111000

#define SHRAPNEL    0x0008   //B0000000000001000
#define DELETER     0x0010   //B0000000000010000
#define WAS_GOODIE  0x0020   //B0000000000100000

#define GOODY          4



#define SPAWNER        5


#endif