#include "SOI.h"

#include "sound.h"
#include "sprites.h"

void SPW_spawn_ant();

void SPW_update();

const Entity SPW_ant = {
    SPAWNER,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    &ant_spawner_spr,
    NULL,
    &SPW_update,
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
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.frames = 0;
    fx.timer = MAX_TIMER - STAY_TIME;
    fx.character = &NST_ant;
    fx.speed[X] = dir ? -WALKSPEED : WALKSPEED;
    fx.speed[Y] = 0;
    ACT_add(&fx, &nasties);
    curr->timer = MAX_TIMER - SPAWN_TIME;
}

void SPW_update(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER) {
            curr->character->role.spawner.onTimeout();
        }
    }
}