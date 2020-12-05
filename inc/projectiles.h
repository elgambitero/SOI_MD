#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "entities.h"

typedef struct Projectile{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;

    const SpriteDefinition * sprite_def;

    void (*const onCrash)();
}Projectile;

extern const Entity PR_arrow;

#endif