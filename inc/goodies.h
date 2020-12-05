#ifndef GOODIES_H
#define GOODIES_H

#include "entities.h"

typedef struct Goodie{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    u16 points;

    const SpriteDefinition * sprite_def;
    const u8 * pickup_sound;
    const u16 pickup_sound_size;

    void (*const onPickUp)();
}Goodie;

extern const Entity * const goodies_vector[];

#endif