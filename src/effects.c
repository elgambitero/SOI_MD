#include "SOI.h"

#include "sprites.h"
#include "sound.h"


void FX_update();

void FX_hidden_loop();
const Entity FX_hidden = {
    FX,
    {7, 15},
    {8, 7},
    PAL_SYS1,
    &fx_hidden,
    NULL,
    &FX_hidden_loop,
    NULL,
    {.effect =
        {
        }
    }
};

void FX_deletor_loop();
const Entity FX_deletor = {
    FX,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &deletor_spr,
    NULL,
    &FX_deletor_loop,
    NULL,
    {.effect =
        {
        }
    }
};

void FX_shrapnel_loop();
const Entity FX_blk_debris0 = {
    FX,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris0_spr,
    NULL,
    &FX_shrapnel_loop,
    NULL,
    {.effect =
        {
        }
    }
};

const Entity FX_blk_debris1 = {
    FX,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris1_spr,
    NULL,
    &FX_shrapnel_loop,
    NULL,
    {.effect =
        {
        }
    }
};


const Entity FX_blk_debris2 = {
    FX,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris2_spr,
    NULL,
    &FX_shrapnel_loop,
    NULL,
    {.effect =
        {
        }
    }
};


const Entity FX_blk_debris3 = {
    FX,
    {4, 8},
    {4, 4},
    PAL_SYS0,
    &blk_debris3_spr,
    NULL,
    &FX_shrapnel_loop,
    NULL,
    {.effect =
        {
        }
    }
};

void FX_boot_loop();
void FX_wearBootOff();
void FX_restoreSpeed();
const Entity FX_boot_ind = {
    FX,
    {4, 8},
    {4, 24},
    PAL_SYS0,
    &boot_ind_spr,
    NULL,
    &FX_boot_loop,
    &FX_restoreSpeed,
    {.effect =
        {
        }
    }
};

void FX_shield_loop();
void FX_wearShieldOff();
const Entity FX_shield_ind = {
    FX,
    {4, 8},
    {4, 24},
    PAL_SYS0,
    &shield_ind_spr,
    NULL,
    &FX_shield_loop,
    &FX_wearShieldOff,
    {.effect =
        {
        }
    }
};


void FX_turtle_loop();
void FX_turtleWearOff();
const Entity FX_turtle = {
    FX,
    {4, 8},
    {4, 24},
    PAL_SYS0,
    NULL,
    NULL,
    &FX_turtle_loop,
    &FX_turtleWearOff,
    {.effect =
        {
        }
    }
};

void FX_trans_loop();
void FX_trans_finished();
const Entity FX_transporter = {
    FX,
    {7, 15},
    {12, 15},
    PAL_SYS0,
    &transporter_spr,
    NULL,
    &FX_trans_loop,
    &FX_trans_finished,
    {.effect =
        {
        }
    }
};


__attribute__((always_inline)) static inline void FX_despawn(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER){
            result = ACT_DELETION;
            return;
        };
    }
}

void FX_hidden_loop(){
    return;
}

void FX_deletor_loop() {
    if(curr->frames--) return;
    result = ACT_DELETION;
}

void FX_shrapnel_loop(){
    if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
        result = ACT_DELETION;
    }
    curr->speed[Y] += GRAVITY;
}

void FX_boot_loop(){
    FX_despawn();
    if(curr->
        actorData.fxData.following->
        character->
        role.player.statistics->
        effect != SPEEDUP)
            curr->timer = MAX_FRAMES - 1;
    curr->pos[X] = curr->actorData.fxData.following->pos[X];
    curr->pos[Y] = curr->actorData.fxData.following->pos[Y];
}

void FX_shield_loop(){
    FX_despawn();
    if(curr->
        actorData.fxData.following->
        character->
        role.player.statistics->
        effect != SHIELDED)
            curr->timer = MAX_FRAMES - 1;
    curr->pos[X] = curr->actorData.fxData.following->pos[X];
    curr->pos[Y] = curr->actorData.fxData.following->pos[Y];
}

void FX_restoreSpeed(){
    curr->
    actorData.fxData.following->
    character->
    role.player.statistics->
    speed = PL_WALKSPEED;
    FX_wearBootOff();
}

void FX_wearBootOff(){
    if(curr->
    actorData.fxData.following->
    character->
    role.player.statistics->
    effect == SPEEDUP)
        curr->
        actorData.fxData.following->
        character->
        role.player.statistics->
        effect = 0;
}

void FX_wearShieldOff(){
    if(curr->
    actorData.fxData.following->
    character->
    role.player.statistics->
    effect == SHIELDED)
        curr->
        actorData.fxData.following->
        character->
        role.player.statistics->
        effect = 0;
}

void FX_turtle_loop(){
    FX_despawn();
}

void FX_turtleWearOff(){
    nasties.effects &= ~SLOW_MSK;
    projectiles.effects &= ~SLOW_MSK;
}

void FX_trans_loop(){
    FX_despawn();
}

void FX_trans_finished(){
    SPR_setVisibility(curr->
        actorData.fxData.following->sprite, VISIBLE);
    ACT_unfreeze(&projectiles);
    ACT_unfreeze(&players);
    ACT_unfreeze(&nasties);
    ACT_unfreeze(&bp_projectiles);
    ACT_unfreeze(&gp_projectiles);
}


/*
void FX_update(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER){
            result = ACT_DELETION;
            return;
        };
    }
    if(curr->character->role.effect.onProcess){
        curr->character->role.effect.onProcess();
        return;
    }
}
*/