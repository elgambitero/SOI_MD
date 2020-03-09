#ifndef ACTORS_H

#define ACTORS_H

#include "entities.h"

#define DECIMALS 2

#define PX_TO_POS(x) (x << DECIMALS)
#define POS_TO_PX(x) (x >> DECIMALS)

typedef struct Actor{
    const Entity * character;
    u8 status;
    u8 frames;
    u16 pos[2];
    s8 speed[2];
    Sprite * sprite;
    struct Actor * next;
}Actor;

u8 ACT_init();
Actor * ACT_add(Actor * actor);
u8 ACT_remove(Actor * actor);
Actor * ACT_getFirst();
void ACT_update();
void ACT_end();

#define ANIM_MSK 0xFE
#define DIR_MSK ¬ANIM_MSK

#define WALK_RIGHT 0
#define WALK_LEFT 1
#define RIGHT_TURN_LEFT 2
#define LEFT_TURN_RIGHT 3
#define ATTACK_RIGHT_IN 4
#define ATTACK_LEFT_IN 5
#define ATTACK_RIGHT_OUT 6
#define ATTACK_LEFT_OUT 7
#define FALL_RIGHT 8
#define FALL_LEFT 9

#define WALK_DOWN 8
#define WALK_UP 9
#define DOWN_TURN_UP 10
#define UP_TURN_DOWN 11
#define ATTACK_DOWN 12
#define ATTACK_UP 13

#define STILL_RIGHT 8
#define STILL_LEFT 9
#define STL_TO_RIGHT 10
#define STL_TO_LEFT 11
#define STL_RIGHT_TO_LEFT 11
#define STL_LEFT_TO_RIGHT 12
#define RIGHT_TO_STL 13
#define LEFT_TO_STL 14
#define JUMP_RIGHT 15
#define JUMP_LEFT 16
#define JUMP_ATTK_RIGHT 17
#define JUMP_ATTK_LEFT 18

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif
