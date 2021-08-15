#include "SOI.h"

#include "sound.h"

//TODO: Organize. Make more understandable
u8 bl_ctrl;
u8 gr_ctrl;


//Time modification methods.
void stop_time(u16 frames){
    u16 time = frames;
    while(time){
        time--;
        VDP_waitVSync();
    }
}

//Special effects based on environment modification.
void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.frames = 0;
    fx.character = &FX_blk_debris0;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED_2X;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris1;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris2;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris3;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED_2X;
    ACT_add(&fx, &fx_buf);
}

void summon_deletor(u8 front_ind, u8 deletes){
    fx.status = deletes ? 1 : 0;
    fx.character = &FX_deletor;
    fx.frames = DELETOR_FRAMES;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 7;
    fx.pos[Y] = BLOCK_TO_PX( (IND_TO_Y(front_ind) + 1) );
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    ACT_add(&fx, &fx_buf);
}

//To be moved.
void kill(Actor * act, u8 speed_x, u8 speed_y){
    u16 attrib = act->character->attr;
    if(attrib & INVINCIBLE) return;
    //switch(attrib & ENT_CHECK_BITMSK){
    //    case NASTIE:
    //This works as it is because nastie and player union members have the same byte alignment for death_sound and death_sound_size
    //Hopefully...
            XGM_setPCM(SFX_IND, act->character->role.nastie.death_sound,
                act->character->role.nastie.death_sound_size);
            XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
    //        break;
    //    case PLAYER: //TODO: THIS VIOLATES THE CURRENT STUCTURE!!! FIX!!!
    //        XGM_setPCM(SFX_IND, act->character->role.player.death_sound,
    //            act->character->role.player.death_sound_size);
    //        XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
    //        break;
    //}
    act->status = DEAD;
    act->pos[Y] -= COLL_CORR;
    act->speed[Y] = speed_y;
    act->speed[X] = speed_x;
}

void spr_collision(){
    if(GET_VDPSTATUS(VDP_SPRCOLLISION_FLAG)) {
        collided = TRUE;
    }
}

//PHY module lifecycle.
u8 PHY_init(Board * board, PlayerStat * bl_stats, PlayerStat * gr_stats){
    env = board;
    SYS_setHIntCallback(&spr_collision); // set sprite collision checking as target callback.
    VDP_setHIntCounter(1); //check every two lines.
    VDP_setHInterrupt(1);
    bl_stat = bl_stats;
    gr_stat = gr_stats;
    if(!ACT_init(&nasties, MAX_NASTIES)) return FALSE;
    if(!ACT_init(&fx_buf, MAX_FX)) return FALSE;
    if(!ACT_init(&players, MAX_PLAYERS)) return FALSE;
    if(!ACT_init(&projectiles, MAX_PROJ)) return FALSE;
    if(!ACT_init(&bp_projectiles, MAX_PROJ)) return FALSE;
    if(!ACT_init(&gp_projectiles, MAX_PROJ)) return FALSE;
    return TRUE;
}

void PHY_end(){
    ACT_end(&nasties);
    ACT_end(&fx_buf);
    ACT_end(&players);
    ACT_end(&projectiles);
    ACT_end(&bp_projectiles);
    ACT_end(&gp_projectiles);
    VDP_setHInterrupt(0);
    SYS_setHIntCallback(0);
}

void PHY_send_inputs(u8 ctrl1, u8 ctrl2){
    bl_ctrl = ctrl1;
    gr_ctrl = ctrl2;
}

u8 PHY_computeStatus(Actor * actor){
    result = 0;
    curr = actor;
    status = curr->status;
    newstatus = status;
    dir = (status & 0x0001);

    (*curr->character->update)(); //Update according to pointer function.

    curr->status = newstatus;
    if(status != newstatus) result = ACT_CHANGED;
    return result;
}


void PHY_update(){
    ACT_update(&players);
    ACT_update(&nasties);
    ACT_update(&projectiles);
    ACT_update(&bp_projectiles);
    ACT_update(&gp_projectiles);
    ACT_update(&fx_buf);
    if(TRUE){
        ACT_collide_lists(&nasties, &players);
        ACT_collide_lists(&projectiles, &players);
        ACT_collide_lists(&bp_projectiles, &nasties);
        ACT_collide_lists(&gp_projectiles, &nasties);
    }
    collided = FALSE;
}
