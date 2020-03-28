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
    u16 pos[2]; //px when declared, px/DECIMALS when in use.
    s8 speed[2];
    Sprite * sprite;
    struct Actor * next;
}Actor;

u8 ACT_init();
Actor * ACT_add(Actor * actor);
u8 ACT_remove(Actor * actor);
Actor * ACT_getFirst();
Actor * ACT_seek(const Entity * ent);
void ACT_update();
void ACT_end();

#define ANIM_MSK 0xFE
#define DIR_MSK ~ANIM_MSK

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

#define WALK_DOWN             8
#define WALK_UP               9
#define DOWN_TURN_UP         10
#define UP_TURN_DOWN         11
#define ATTACK_DOWN_IN       12
#define ATTACK_UP_IN         13
#define ATTACK_DOWN_OUT      14
#define ATTACK_UP_OUT        15

#define STILL_RIGHT          10
#define STILL_LEFT           11
#define LOW_ATTK_RIGHT_IN    12
#define LOW_ATTK_LEFT_IN     13
#define LOW_ATTK_RIGHT_OUT   14
#define LOW_ATTK_LEFT_OUT    15
#define STL_TO_RIGHT         16
#define STL_TO_LEFT          17
#define STL_RIGHT_TO_LEFT    18
#define STL_LEFT_TO_RIGHT    19
#define RIGHT_TO_STL         20
#define LEFT_TO_STL          21
#define JUMP_RIGHT           22
#define JUMP_LEFT            23
#define JUMP_ATTK_RIGHT_IN   24
#define JUMP_ATTK_LEFT_IN    25
#define JUMP_ATTK_RIGHT_OUT  26
#define JUMP_ATTK_LEFT_OUT   27

#define DEAD                 28

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif
