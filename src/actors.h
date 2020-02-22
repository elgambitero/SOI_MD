#ifndef ACTORS_H

#define ACTORS_H

#include "entities.h"

enum Status{
    IDLE,
    WALKING,
    ATTACKING,
    JUMPING,
    FALLING,
    DYING
};

typedef struct Actor{
    const Entity * character;
    enum Status status;
    u16 pos[2];
    u8 speed[2];
    Sprite * sprite;
    struct Actor * next;
}Actor;

u8 initActors();
u8 addActor(Actor * actor);
u8 removeActor(Actor * actor);
u8 updateActors();

#define STILL_RIGHT 0
#define STILL_LEFT 1
#define WALK_RIGHT 2
#define WALK_LEFT 3
#define RIGHT_TURN_LEFT 4
#define LEFT_TURN_RIGHT 5
#define ATTACK_RIGHT 6
#define ATTACK_LEFT 7

#define JUMP_RIGHT 8
#define JUMP_LEFT 9

#define WALK_UP 8
#define WALK_DOWN 9
#define UP_TURN_DOWN 10
#define DOWN_TURN_UP 11
#define ATTACK_UP 12
#define ATTACK_DOWN 13

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif
