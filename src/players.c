#include "players.h"

#include "sprites.h"
#include "sound.h"

#include "physics.h"
#include "gameplay.h"
#include "blocks.h"

//TODO: Fill this!
const Entity PL_blue = {
    BLUE_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS0,
    &bp_spr,
    {.player =
        {
            snd_player_death,
            sizeof(snd_player_death)
        }
    }
};

const Entity PL_green = {
    GREEN_PLAYER,
    {2, 15},
    {7, 15},
    PAL_SYS1,
    &bp_spr,
    {.player =
        {
            snd_player_death,
            sizeof(snd_player_death),
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
        if(front >= BOARD_X_PX || front_ind > BOARD_BUFFER || is_occupied(front_ind)){
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