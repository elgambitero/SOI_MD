#ifndef ENTITIES_H

#define ENTITIES_H

typedef struct Nastie{
    const u8 * death_sound;
    const u16 death_sound_size;
    
    u16 points;

    u8 speed;

}Nastie;

typedef struct FX{
    
}FX;


typedef struct Player{
    const u8 * death_sound;
    const u16 death_sound_size;
    PlayerStat * const statistics;
    u8 * const intent;
    u8 * const future;
    u8 * const ctrl;
    u8 * const future_speed;
    u8 * const anti_bounce;
    Pickups * pickups;
}Player;


typedef struct Projectile{
    
}Projectile;


typedef struct Goodie{
    u16 points;
    const u8 * pickup_sound;
    const u16 pickup_sound_size;

    void (*const onCrash)();
    void (*const onPickUp)();
}Goodie;

typedef struct Spawner{
    u16 timer;
    void (*const onTimeout)();
}Spawner;

typedef struct Entity{
    u16 attr;
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    const SpriteDefinition * sprite_def;

    void (*const onCreate)();

    void (*const update)();
    
    void (*const onDestroy)();

    union Role{
        const Player player;
        const Nastie nastie;
        const Goodie goodie;
        const FX effect;
        const Projectile proj;
        const Spawner spawner;
    }role;
}Entity;


#define ENT_CHECK_BITMSK 0x0007

#define PLAYER   0

#define PLAYER_MSK   0x0018 //B0000000000011000

#define BLUE_PLAYER   0x0000 //B0000000000000000
#define GREEN_PLAYER  0x0008 //B0000000000001000
#define RED_PLAYER        0x0018 //B0000000000011000
#define PINK_PLAYER      0x0010 //B0000000000010000

#define NASTIE        1

#define INVINCIBLE    0x0100

#define PROJECTILE     2
#define CREATES_NASTIE 0x0200 //B0000001000000000
#define WHICH_NASTIE(attr) (attr >> 10)

#define FX             3

#define GOODY          4



#define SPAWNER        5


#endif