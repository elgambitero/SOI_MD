#ifndef PLAYER_H

#define PLAYER_H

#include <genesis.h>

#include "entities.h"

typedef struct Player{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;

    const SpriteDefinition * sprite_def;
    const u8 * death_sound;
    const u16 death_sound_size;
}Player;

typedef struct PlayerStat{
    u32 score;
    u8 arrows;
    u8 balls;
    u8 lives;
}PlayerStat;

u8 weap_ctrl(u8 after);
u8 block_ctrl(u8 after);
u8 jump_ctrl(u8 after);

extern const Entity PL_blue;
extern const Entity PL_green;

#endif