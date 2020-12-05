#ifndef EFFECTS_H
#define EFFECTS_H

typedef struct FX{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    const SpriteDefinition * sprite_def;
}FX;

#endif