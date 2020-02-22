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

#define STILL_LEFT 0
#define STILL_RIGHT 1
#define WALK_RIGHT 1
#define WALK_LEFT 2
#define RIGHT_TURN_LEFT 3
#define LEFT_TURN_RIGHT 4
#define ATTACK_LEFT 5
#define ATTACK_RIGHT 6

#define SLOW 4
#define NORMAL 2
#define FAST 1

#endif