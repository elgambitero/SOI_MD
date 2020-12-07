#include "spawners.h"

#include "actors.h"
#include "nasties.h"

#include "physics.h"
#include "gameplay.h"
#include "blocks.h"

#include "sound.h"
#include "sprites.h"

void SPW_spawn_ant();

const Entity SPW_ant = {
    SPAWNER,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
    {.spawner =
        {
            STAY_TIME,
            &SPW_spawn_ant
        }
    }
};

void SPW_spawn_ant(){
    fx.status = curr->status;
    u8 dir = fx.status & 0x01;
    fx.pos[X] = curr->pos[X];
    fx.pos[Y] = curr->pos[Y];
    fx.frames = 0;
    fx.character = &NST_ant;
    fx.speed[X] = dir ? -WALKSPEED : WALKSPEED;
    fx.speed[Y] = 0;
    ACT_add(&fx, &nasties);
    curr->timer = MAX_TIMER - STAY_TIME;
}