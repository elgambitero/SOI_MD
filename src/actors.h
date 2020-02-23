#ifndef ACTORS_H

#define ACTORS_H

#include "entities.h"

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
void ACT_update();
void ACT_end();


#define WALK_RIGHT 0
#define WALK_LEFT 1
#define RIGHT_TURN_LEFT 2
#define LEFT_TURN_RIGHT 3
#define ATTACK_RIGHT 4
#define ATTACK_LEFT 5
#define FALL_RIGHT 6
#define FALL_LEFT 7

#define WALK_UP 6
#define WALK_DOWN 7
#define UP_TURN_DOWN 8
#define DOWN_TURN_UP 9
#define ATTACK_UP 10
#define ATTACK_DOWN 11

#define STILL_RIGHT 6
#define STILL_LEFT 7
#define STL_TO_RIGHT 8
#define STL_TO_LEFT 9
#define STL_RIGHT_TO_LEFT 10
#define STL_LEFT_TO_RIGHT 11
#define RIGHT_TO_STL 12
#define LEFT_TO_STL 13
#define JUMP_RIGHT 14
#define JUMP_LEFT 15
#define JUMP_ATTK_RIGHT 16
#define JUMP_ATTK_LEFT 17

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif
