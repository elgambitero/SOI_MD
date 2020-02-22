#ifndef ACTORS_H

#define ACTORS_H

#include "entities.h"

typedef struct Actor{
    const Entity * character;
    u8 status;
    u16 pos[2];
    u8 speed[2];
    Sprite * sprite;
    struct Actor * next;
}Actor;

u8 initActors();
u8 addActor(Actor * actor);
u8 removeActor(Actor * actor);
u8 updateActors();


#define WALK_RIGHT 0
#define WALK_LEFT 1
#define RIGHT_TURN_LEFT 2
#define LEFT_TURN_RIGHT 3
#define ATTACK_RIGHT 4
#define ATTACK_LEFT 5

#define WALK_UP 6
#define WALK_DOWN 7
#define UP_TURN_DOWN 8
#define DOWN_TURN_UP 9
#define ATTACK_UP 10
#define ATTACK_DOWN 11

#define STILL_RIGHT 6
#define STILL_LEFT 7
#define STL_RIGHT_TO_LEFT 8
#define STL_LEFT_TO_RIGHT 9
#define JUMP_RIGHT 10
#define JUMP_LEFT 11
#define JUMP_ATTK_RIGHT 12
#define JUMP_ATTK_LEFT 13

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif
