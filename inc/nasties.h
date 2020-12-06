#ifndef NASTIES_H
#define NASTIES_H

#include <genesis.h>

#include "entities.h"

typedef struct Nastie{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;

    const SpriteDefinition * sprite_def;
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

extern const Entity NST_spinner;
extern const Entity NST_robo;
extern const Entity NST_ant;
extern const Entity NST_piggy;
extern const Entity NST_teeth;

#endif