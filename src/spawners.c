#include "SOI.h"

#include "sound.h"
#include "sprites.h"

void SPW_update();

void SPW_spawn_ant();
const Entity SPW_ant = {
    SPAWNER | INVINCIBLE,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
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

void SPW_spawn_piggy();
const Entity SPW_piggy = {
    SPAWNER | INVINCIBLE,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
    NULL,
    &SPW_update,
    NULL,
    {.spawner =
        {
            STAY_TIME,
            &SPW_spawn_piggy
        }
    }
};

void SPW_spawn_hippo();
const Entity SPW_hippo = {
    SPAWNER | INVINCIBLE,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
    NULL,
    &SPW_update,
    NULL,
    {.spawner =
        {
            STAY_TIME,
            &SPW_spawn_hippo
        }
    }
};

void SPW_spawn_ostrich();
const Entity SPW_ostrich = {
    SPAWNER | INVINCIBLE,
    {8, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
    NULL,
    &SPW_update,
    NULL,
    {.spawner =
        {
            STAY_TIME,
            &SPW_spawn_ostrich
        }
    }
};

void SPW_cannon_loop();
const Entity SPW_cannon = {
    SPAWNER | INVINCIBLE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    NULL,
    NULL,
    &SPW_cannon_loop,
    NULL,
    {.spawner =
        {
            NULL,
            NULL
        }
    }
};

__attribute__((always_inline)) static inline void NST_spawn(Entity * character){
    switch(curr->actorData.spwData.mode){
        case ALTERNATE:
            fx.status = curr->actorData.spwData.tick;
            curr->actorData.spwData.tick = !(curr->actorData.spwData.tick);
            break;
        case SEEK_PLAYER:
            break;
        default:
            fx.status = curr->status;
            break;
    }
    u8 dir = fx.status & 0x01;
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.frames = 0;
    fx.timer = MAX_TIMER - STAY_TIME;
    fx.character = character;
    fx.speed[X] = dir ? 
        -fx.character->role.nastie.speed : fx.character->role.nastie.speed;
    fx.speed[Y] = 0;
    ACT_add(&fx, &nasties);
    if(curr->actorData.spwData.interval)
        curr->timer = MAX_TIMER - curr->actorData.spwData.interval;
    else
        curr->timer = MAX_TIMER - SPAWN_TIME;
}

void SPW_spawn_ant(){
    NST_spawn(&NST_ant);
}

void SPW_spawn_piggy(){
    NST_spawn(&NST_piggy);
}

void SPW_spawn_hippo(){
    NST_spawn(&NST_hippo);
}

void SPW_spawn_ostrich(){
    NST_spawn(&NST_ostrich);
}

void SPW_update(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER) {
            curr->character->role.spawner.onTimeout();
        }
    }
}


void SPW_cannon_loop(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER){
            fx.status = dir;
            fx.character = &PR_cannonball;
            fx.speed[Y] = 0;
            fx.pos[Y] = POS_TO_PX(curr->pos[Y]) - 4;
            if(dir){
                fx.pos[X] = POS_TO_PX(curr->pos[X]) - 9;
                fx.speed[X] = -CANBALL_SPEED;
            }else{
                fx.pos[X] = POS_TO_PX(curr->pos[X]) + 9;
                fx.speed[X] = CANBALL_SPEED;
            }
            ACT_add(&fx, &projectiles);
            XGM_setPCM(SFX_IND, snd_cannon_fire, sizeof(snd_cannon_fire));
            XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
            curr->timer = MAX_TIMER - CANNON_TIME;
            return;
        };
    }
}