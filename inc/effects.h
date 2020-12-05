#ifndef EFFECTS_H
#define EFFECTS_H

#include "entities.h"

typedef struct FX{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    const SpriteDefinition * sprite_def;
}FX;

extern const Entity FX_deletor;
extern const Entity FX_blk_debris0;
extern const Entity FX_blk_debris1;
extern const Entity FX_blk_debris2;
extern const Entity FX_blk_debris3;

#endif