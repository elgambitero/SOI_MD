#include "SOI.h"

//TODO: Organize. Make more understandable
u8 bl_ctrl;
u8 gr_ctrl;


//Time modification methods.
void PHY_stop_time(u16 frames){
    u16 time = frames;
    while(time){
        time--;
        VDP_waitVSync();
    }
}

//Presence and collision system.
u8 pres_frame = 0;
u16 board_presence[19];
u16 board_presence1[19];

void PHY_clean_presence(){
    if(pres_frame)
        memset(board_presence1, 0x0000, sizeof(board_presence));
    else
        memset(board_presence, 0x0000, sizeof(board_presence1));
    pres_frame = !pres_frame;
}
void PHY_set_presence(u8 ind){
    register u8 slot = IND_TO_X(ind);
    register u8 shift = IND_TO_Y(ind);
    //u8 err[16];
    //sprintf(err, "%d, %d", slot, shift);
    //VDP_drawText(err, 20, 27);
    if(pres_frame)
        board_presence[slot] |= (1 << shift);
    else
        board_presence1[slot] |= (1 << shift);
}
u16 PHY_is_occupied(u8 ind){
    register u8 slot = IND_TO_X(ind);
    register u8 shift = IND_TO_Y(ind);
    u16 result;
    if(pres_frame)
        result = (board_presence1[slot] & (1 << shift));
    else
        result = (board_presence[slot] & (1 << shift));
    //u8 err[16];
    //sprintf(err, "%d, %d, %d", slot, shift, board_presence[slot]);
    //VDP_drawText(err, 0, 27);
    return result;
}


//Special effects based on environment modification.
void PHY_brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
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

void PHY_summon_deletor(u8 front_ind, u8 deletes){
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
void PHY_kill(Actor * act, u8 speed_x, u8 speed_y){
    u16 attrib = act->character->attr;
    if(attrib & INVINCIBLE) return;
    
    //This works as it is because nastie and player union members 
    //have the same byte alignment for death_sound
    //Hopefully...
    SFX_playSound(act->character->role.nastie.death_sound);

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
    //SYS_setHIntCallback(&spr_collision); // set sprite collision checking as target callback.
    //VDP_setHIntCounter(1); //check every two lines.
    //VDP_setHInterrupt(1);
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
    //VDP_setHInterrupt(0);
    //SYS_setHIntCallback(0);
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

void PHY_kill_withPoints(Actor * a, Actor * b){
    if(b->status == DEAD || b->character->attr & INVINCIBLE)
        return;
    PHY_kill(b, 0, -2 * WALKSPEED);
    if(GAM_gameType == COOPERATE){
        bl_stats.score += b->character->role.nastie.points;
        gr_stats.score += b->character->role.nastie.points;
        if(ACT_contains(a, &bp_projectiles)){
            if(a->character == &PR_arrow)
                ACT_remove(a, &bp_projectiles);
        }
        if(ACT_contains(a, &gp_projectiles)){
            if(a->character == &PR_arrow)
                ACT_remove(a, &gp_projectiles);
        }
    }else{
        if(ACT_contains(a, &bp_projectiles)){
            bl_stats.score += b->character->role.nastie.points;
            if(a->character == &PR_arrow)
                ACT_remove(a, &bp_projectiles);
        }
        if(ACT_contains(a, &gp_projectiles)){
            gr_stats.score += b->character->role.nastie.points;
            if(a->character == &PR_arrow)
                ACT_remove(a, &gp_projectiles);
        }
    }
    GAM_updateScore();
}

void PHY_kill_player(Actor * a, Actor * b){
    if(((b == blue_player) && (bl_stat->effect != SHIELDED)) ||
        ((b == green_player) && (gr_stat->effect != SHIELDED))){
        if((a->character->attr & ENT_CHECK_BITMSK) == SPAWNER) return;
        PHY_kill(b, 0, -2 * WALKSPEED);
    }
}

void PHY_update(){
    PHY_clean_presence(); //clears the presence from last frame after players have been evaluated.
    ACT_update(&players);
    ACT_update(&nasties);
    ACT_update(&projectiles);
    ACT_update(&bp_projectiles);
    ACT_update(&gp_projectiles);
    ACT_update(&fx_buf);
    //if(collided){
        ACT_collide_lists(&nasties, &players, &PHY_kill_player);
        ACT_collide_lists(&projectiles, &players, &PHY_kill_player);
        ACT_collide_lists(&bp_projectiles, &nasties, &PHY_kill_withPoints);
        ACT_collide_lists(&gp_projectiles, &nasties, &PHY_kill_withPoints);
    //}
    collided = FALSE;
}
