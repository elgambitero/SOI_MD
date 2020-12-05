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

extern const Entity GD_silvCoin;
extern const Entity GD_arrow;
extern const Entity GD_clk3h;
extern const Entity GD_clk6h;
extern const Entity GD_clk9h;
extern const Entity GD_clk12h;
extern const Entity GD_glass;
extern const Entity GD_shield;
extern const Entity GD_boost;
extern const Entity GD_boot;
extern const Entity GD_thnball;
extern const Entity GD_rdkey;
extern const Entity GD_blkey;
extern const Entity GD_rddoor;
extern const Entity GD_bldoor;
extern const Entity GD_rddoor_open;
extern const Entity GD_bddoor_open;
extern const Entity GD_goldCoin;
extern const Entity GD_1UP;
extern const Entity GD_2x;
extern const Entity GD_3x;
extern const Entity GD_4x;
extern const Entity GD_5x;
extern const Entity GD_ball;
extern const Entity GD_gem;
extern const Entity GD_gold;
extern const Entity GD_turtl;
extern const Entity GD_star;
extern const Entity GD_grkey;
extern const Entity GD_grdoor;
extern const Entity GD_grdoor_open;

//extern const Entity * const goodies_vector[];

#endif