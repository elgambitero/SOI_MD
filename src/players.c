#include "SOI.h"

#include "sprites.h"
#include "sound.h"


u8 weap_ctrl(u8 after);
u8 block_ctrl(u8 after);
u8 jump_ctrl(u8 after);

void PL_update();

u8 * pl_act;
u8 bl_act, gr_act;
u8 * ctrl;
u8 bl_after_status, gr_after_status;
u8 * after_status;
u8 bl_after_speed[2], gr_after_speed[2];
u8 * after_speed;

__attribute__((always_inline)) static inline u8 blk_evaluate(u8 ind){
    return BLK_TYPE & env->front_blocks[ind];
}

const Entity PL_blue = {
    BLUE_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS0,
    &bp_spr,
    NULL,
    &PL_update,
    NULL,
    {.player =
        {
            snd_player_death,
            sizeof(snd_player_death),
            &bl_stats,
            &bl_act,
            &bl_after_status,
            &bl_ctrl,
            bl_after_speed
        }
    }
};

const Entity PL_green = {
    GREEN_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS1,
    &bp_spr,
    NULL,
    &PL_update,
    NULL,
    {.player =
        {
            snd_player_death,
            sizeof(snd_player_death),
            &gr_stats,
            &gr_act,
            &gr_after_status,
            &gr_ctrl,
            gr_after_speed
        }
    }
};

u8 weap_ctrl(u8 after){
    if( *ctrl & CTRL_FIRE ){
        *after_status = after;
        memcpy(after_speed, curr->speed, sizeof(curr->speed));
        curr->speed[X] = 0;
        curr->speed[Y] = 0;
        if(*ctrl & CTRL_ALT){
            curr->frames = BP_ATTK_FRAMES;
            newstatus = LOW_ATTK_RIGHT_IN | dir;/*
            if(TRUE){ // ran out of magic balls. Deactivated for now.
                *pl_act = NOTHING;
                return TRUE;
            }
            *pl_act = SHOOT;
            return TRUE;*/
            *pl_act = NOTHING;
            return TRUE;
        }else{
            curr->frames = BP_ATTK_FRAMES;
            newstatus = ATTACK_RIGHT_IN | dir;
            if(!pl_stat->arrows){ // ran out of arrows. Infinite for now for now.
                *pl_act = NOTHING;
                return TRUE;
            }
            pl_stat->arrows--;
            *pl_act = SHOOT;
            return TRUE;
        }
        return TRUE;
    }
    return FALSE;
}

u8 block_ctrl(u8 after){
    if( *ctrl & CTRL_BLOCK ){
        *after_status = after;
        memcpy(after_speed, curr->speed, sizeof(curr->speed));
        curr->speed[X] = 0;
        curr->speed[Y] = 0;
        calc_next(dir);
        if(*ctrl & CTRL_ALT){
            calc_next_floor();
            curr->frames = BP_ATTK_FRAMES;
            newstatus = LOW_ATTK_RIGHT_IN | dir;
        }else{
            calc_front_block();
            curr->frames = BP_ATTK_FRAMES;
            newstatus = ATTACK_RIGHT_IN | dir;
        }
        if(front >= BOARD_X_PX || front_ind > BOARD_BUFFER){
            *pl_act = NOTHING;
            return TRUE;
        }
        if(env->front_blocks[front_ind]){
            if(breakable(front_ind)){
                *pl_act = DEL_BLOCK;
            }else{
                *pl_act = NOTHING;
            }
        }else{
            *pl_act = MK_BLOCK;
        }
        return TRUE;
    }
    return FALSE;
}

u8 jump_ctrl(u8 after){
    if( *ctrl & CTRL_JUMP ){
        calc_top();
        calc_top_block_left();
        if(top >= BOARD_Y_MAX || ( env->front_blocks[top_ind] & SOLID )){
            *after_status = after;
            curr->speed[X] = 0;
            curr->frames = BP_ATTK_FRAMES;
            newstatus = JUMP_ATTK_RIGHT_IN | dir;
            return TRUE;
        }
        calc_top_block_right();
        if(top >= BOARD_Y_MAX || ( env->front_blocks[top_ind] & SOLID )){
            *after_status = after;
            curr->speed[X] = 0;
            curr->frames = BP_ATTK_FRAMES;
            newstatus = JUMP_ATTK_RIGHT_IN | dir;
            return TRUE;
        }
        newstatus = JUMP_RIGHT | dir;
        curr->speed[Y] = PL_JMP_BOOST;
        return TRUE;
    }
    return FALSE;
}

//Why here???
static inline void gd_process(u8 ind){
    gd_index = GD_GET_INDEX( env->front_blocks[ind] );
    const Entity * character = goodies_vector[gd_index];
    if(character->role.goodie.pickup_sound){
        XGM_setPCM(SFX_IND, character->role.goodie.pickup_sound, 
            character->role.goodie.pickup_sound_size);
        XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
    }
    if(character->role.goodie.onCrash) character->role.goodie.onCrash();
    if(character->role.goodie.onPickUp) character->role.goodie.onPickUp();
}

static inline void PL_teleport(u8 from_ind, u16 block){
    u8 exit_ind = 0;
    switch(block){
        case TRI:
            exit_ind = seek_block(env, TRO);
            break;
        case TGI:
            exit_ind = seek_block(env, TGO);
            break;
        case TBI:
            exit_ind = seek_block(env, TBO);
            break;
        case TNI:
            exit_ind = seek_block(env, TNO);
            break;
        case TYI:
            exit_ind = seek_block(env, TYO);
            break;
        case TWI:
            exit_ind = seek_block(env, TWO);
            break;
    }
    if(exit_ind == 0) SYS_die("No teleport output");
    s16 delta[2];
    delta[X] = PX_TO_POS((IND_TO_X(exit_ind) - IND_TO_X(from_ind)) << 4);
    delta[Y] = PX_TO_POS((IND_TO_Y(exit_ind) - IND_TO_Y(from_ind)) << 4);
    curr->pos[X] += delta[X];
    curr->pos[Y] += delta[Y];
}

static inline void summon_arrow(u8 dir, ActorList * list){
    fx.status = dir;
    fx.character = &PR_arrow;
    fx.frames = 0;
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.speed[X] = dir ? -2*WALKSPEED : 2*WALKSPEED;
    fx.speed[Y] = 0;
    ACT_add(&fx, list);
}

static inline void jmp_brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.frames = 0;
    fx.character = &FX_blk_debris0;
    fx.speed[X] = sp_x - BRK_SPEED_2X;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris1;
    fx.speed[X] = sp_x - BRK_SPEED;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris2;
    fx.speed[X] = sp_x + BRK_SPEED;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &FX_blk_debris3;
    fx.speed[X] = sp_x + BRK_SPEED_2X;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
}

void PL_update(){
    pl_stat = curr->character->role.player.statistics;
    pl_act = curr->character->role.player.intent;
    after_status = curr->character->role.player.future;
    ctrl = curr->character->role.player.ctrl;
    after_speed = curr->character->role.player.future_speed;
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_front_margin(dir);
            calc_front_block();
            switch(crash_into()){
                //onWalkInto
                case FRAME:
                case BLOCK:
                    curr->speed[X] = 0;
                    curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
                    break;
                default:
                    curr->speed[X] = dir ? -pl_stat->speed : pl_stat->speed;
                    break;
            }
            calc_front(dir);
            calc_back(dir);
            calc_front_floor();
            calc_back_floor();
            if(fall(front_floor_ind) && fall(back_floor_ind)){
                //onFall
                newstatus = FALL_RIGHT | dir;
                curr->speed[Y] = FALLSPEED;
                curr->speed[X] = 0;
                return;
            }
            calc_center_block();
            switch(blk_evaluate(center_ind)){
                case SPECIAL_BLOCK:
                    switch(SP_TYP_MSK & env->front_blocks[center_ind]){
                        case SP_TRANS:
                            if(env->front_blocks[center_ind] & TRANS_DIR_MSK){
                                PL_teleport(center_ind, env->front_blocks[center_ind]);
                                return;
                            }
                            break;
                    }
                    break;
                case GOODIE:
                    gd_process(center_ind);
            }
            if(jump_ctrl(status)) return; //TODO: DECIPHER THIS.
            if( *ctrl & CTRL_MOV ){
                if( ( *ctrl & CTRL_LEFT ) != dir ){
                    //onTurnAround
                    newstatus = RIGHT_TURN_LEFT | dir;
                    curr->frames = BP_TURN_FRAMES;
                    curr->speed[X] = 0;
                    return;
                }
            }
            else
            {
                //onStopWalking
                newstatus = RIGHT_TO_STL | dir;
                curr->frames = BP_STL_FRAMES;
                curr->speed[X] = 0;
                return;
            }
            block_ctrl(STILL_RIGHT | dir);
            weap_ctrl(STILL_RIGHT | dir);
            return;
        break;
        case RIGHT_TURN_LEFT:
            if(curr->frames--) return;
            newstatus = WALK_RIGHT | !dir;
            curr->speed[X] = dir ? PL_WALKSPEED : -PL_WALKSPEED;
        break;
        case ATTACK_RIGHT_IN:
            if(curr->frames--) return;
            switch(*pl_act){
                case MK_BLOCK:
                    calc_next(dir);
                    calc_front_block();
                    if(pl_act == &bl_act)
                        create_block_ind(env, BP, front_ind);
                    else
                        create_block_ind(env, GP, front_ind);
                    XGM_setPCM(SFX_IND, snd_block_create, sizeof(snd_block_create));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, FALSE);
                break;
                case DEL_BLOCK:
                    calc_next(dir);
                    calc_front_block();
                    break_block_ind(env, front_ind);
                    XGM_setPCM(SFX_IND, snd_block_delete, sizeof(snd_block_delete));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, TRUE);
                break;
                case SHOOT:
                    XGM_setPCM(SFX_IND, snd_arrow_fire, sizeof(snd_arrow_fire));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    if(pl_act == &bl_act)
                        summon_arrow(dir, &bp_projectiles);
                    else
                        summon_arrow(dir, &gp_projectiles);
                break;
                default:
                break;
            }
            newstatus = ATTACK_RIGHT_OUT | dir;
            curr->frames = BP_ATTK_FRAMES;
        break;
        case ATTACK_RIGHT_OUT:
            if(curr->frames--) return;
            newstatus = *after_status;
            memcpy(curr->speed, after_speed, sizeof(curr->speed));
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                //onLand
                curr->pos[Y] &= FLOOR_CORR;
                newstatus = dir | STILL_RIGHT;
                curr->speed[Y] = 0;
                curr->speed[X] = 0;
                break;
            }
            block_ctrl(FALL_RIGHT | dir);
            weap_ctrl(FALL_RIGHT | dir);
        break;
        case STILL_RIGHT:
            curr->speed[X] = 0;
            calc_front(dir);
            calc_back(dir);
            calc_front_floor();
            calc_back_floor();
            if(fall(front_floor_ind) && fall(back_floor_ind)){
                //onFall
                newstatus = FALL_RIGHT | dir;
                curr->speed[Y] = FALLSPEED;
                return;
            }
            if(jump_ctrl(status)) return;
            if( *ctrl & CTRL_MOV ){
                if( ( *ctrl & CTRL_LEFT ) != dir ){
                    newstatus = STL_RIGHT_TO_LEFT | dir;
                    curr->frames = BP_STL_TURN_FRAMES;
                }else{
                    newstatus = STL_TO_RIGHT | dir;
                    curr->frames = BP_STL_FRAMES;
                }
                return;
            }
            block_ctrl(status);
            weap_ctrl(status);
            return;
        break;
        case LOW_ATTK_RIGHT_IN:
            if(curr->frames--) return;
            switch(*pl_act){
                case MK_BLOCK:
                    calc_next(dir);
                    calc_next_floor();
                    if(pl_act == &bl_act)
                        create_block_ind(env, BP, front_ind);
                    else
                        create_block_ind(env, GP, front_ind);
                    XGM_setPCM(SFX_IND, snd_block_create, sizeof(snd_block_create));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, FALSE);
                break;
                case DEL_BLOCK:
                    calc_next(dir);
                    calc_next_floor();
                    break_block_ind(env, front_ind);
                    XGM_setPCM(SFX_IND, snd_block_delete, sizeof(snd_block_delete));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, TRUE);
                break;

                default:
                break;
            }
            newstatus = LOW_ATTK_RIGHT_OUT | dir;
            curr->frames = BP_ATTK_FRAMES;
        break;
        case LOW_ATTK_RIGHT_OUT:
            if(curr->frames--) return;
            newstatus = *after_status;
            memcpy(curr->speed, after_speed, sizeof(curr->speed));
        break;
        case STL_TO_RIGHT:
            if(curr->frames--) return;
            newstatus = WALK_RIGHT | dir;
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){//is this even correct?
                case FRAME:
                case BLOCK:
                //Should be onStopWalking
                    break;
                case GOODIE:
                    gd_process(front_ind);
                default:
                    curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
                    break;
            }
        break;
        case STL_RIGHT_TO_LEFT:
            if(curr->frames--) return;
            newstatus = WALK_RIGHT | !dir ;
            calc_front_margin(!dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                case BLOCK:
                    //onWalkInto
                    curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
                    break;
                case GOODIE:
                    gd_process(front_ind);
                default:
                    curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
                    break;
            }
        break;
        case RIGHT_TO_STL:
            if(curr->frames--) return;
            newstatus = STILL_RIGHT | dir;
            curr->speed[X] = 0;
        break;
        case JUMP_RIGHT:
            if(curr->speed[Y] <= FALLSPEED)
                curr->speed[Y] += GRAVITY;
            calc_center_block();
            switch(blk_evaluate(center_ind)){
                case SPECIAL_BLOCK:
                    switch(SP_TYP_MSK & env->front_blocks[center_ind]){
                        case SP_TRANS:
                            if(env->front_blocks[center_ind] & TRANS_DIR_MSK){
                                PL_teleport(center_ind, env->front_blocks[center_ind]);
                                return;
                            }
                            break;
                    }
                    break;
                case GOODIE:
                    gd_process(center_ind);
            }
            if( *ctrl & CTRL_MOV){
                register u8 push = *ctrl & CTRL_LEFT;
                curr->speed[X] = push ? -PL_WALKSPEED : PL_WALKSPEED;
                calc_front_margin( push );
                calc_front_block_hi();
                if(crash_into()){
                    curr->pos[X] += push ? COLL_CORR : -COLL_CORR;
                    curr->speed[X] = 0;
                }
                calc_front_block_lo();
                if(crash_into()){
                    curr->pos[X] += push ? COLL_CORR : -COLL_CORR;
                    curr->speed[X] = 0;
                }
            }else{
                curr->speed[X] = 0;
            }
            block_ctrl(JUMP_RIGHT | dir);
            weap_ctrl(JUMP_RIGHT | dir);
            if(curr->speed[Y] > 0){
                calc_front(dir);
                calc_back(dir);
                calc_front_floor();
                calc_back_floor();
                if(land(back_floor_ind) || land(front_floor_ind)) {
                    //onJumpLands
                    curr->pos[Y] &= FLOOR_CORR;
                    curr->speed[Y] = 0;
                    curr->speed[X] = 0;
                    if(jump_ctrl(status)) return;
                    if(*ctrl & CTRL_MOV){
                        if( ( *ctrl & CTRL_LEFT ) != dir ){
                            newstatus = STL_RIGHT_TO_LEFT | dir;
                            curr->frames = BP_STL_TURN_FRAMES;
                            return;
                        }else{
                            newstatus = WALK_RIGHT | dir;
                            curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
                            return;
                        }
                    }
                    newstatus = dir | STILL_RIGHT;
                    return;
                }
            }
        break;
        case JUMP_ATTK_RIGHT_IN:
            if(curr->frames--) return;
            curr->frames = BP_ATTK_FRAMES;
            newstatus = JUMP_ATTK_RIGHT_OUT | dir;
            calc_top();
            calc_top_block();
            if(top < BOARD_X_PX && ( env->front_blocks[top_ind] & BREAKABLE )){
                if(env->front_blocks[top_ind] & BROKEN){
                    XGM_setPCM(SFX_IND, snd_block_break, sizeof(snd_block_break));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    //play snap sound
                    break_block_ind(env, top_ind);
                    jmp_brk_debris(top_ind, 0, -BRK_SPEED);
                }else{
                    XGM_setPCM(SFX_IND, snd_block_crack, sizeof(snd_block_crack));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    create_block_ind(env, env->front_blocks[top_ind] | BROKEN, top_ind);
                }
            }
        break;
        case JUMP_ATTK_RIGHT_OUT:
            if(curr->frames--) return;
            newstatus = *after_status;
        break;
        case DEAD:
            SPR_setAnim(curr->sprite, curr->status);
            if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
                result = ACT_DELETION;
            }
            curr->speed[Y] += GRAVITY;
        break;
    }
    return;
}