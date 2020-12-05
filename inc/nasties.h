#ifndef NASTIES_H
#define NASTIES_H

#include <genesis.h>

typedef struct Nastie{
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
}Nastie;

#endif