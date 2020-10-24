#include "behavior.h"

#include "physics.h"
#include "sound.h"
#include "blocks.h"

void NST_still_fall(){
    newstatus = FALL_RIGHT;
    status = FALL_RIGHT; //Ugly hack
    curr->speed[Y] = FALLSPEED;
    curr->speed[X] = 0;
}

void NST_still_land(){
    curr->speed[Y] = 0;
    curr->speed[X] = 0;
}

void NST_fall(){
    newstatus = dir | FALL_RIGHT;
    curr->speed[Y] = FALLSPEED;
    curr->speed[X] = 0;
}

void NST_turn_around(){
    newstatus = dir | RIGHT_TURN_LEFT;
    curr->frames = TURN_FRAMES;
    curr->speed[X] = 0;
}

void NST_attack(){
    newstatus = dir | ATTACK_RIGHT_IN;
    curr->frames = ATTK_FRAMES;
    curr->speed[X] = 0;
}

void NST_breaks(){
    calc_front(dir);
    calc_front_block();
    break_block_ind(env, front_ind);
    brk_debris(front_ind, BRK_SPEED, 0);
    XGM_setPCM(SFX_IND, blk_phy_break, sizeof(blk_phy_break));
    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
}

void NST_deletes(){
    calc_front(dir);
    calc_front_block();
    break_block_ind(env, front_ind);
    summon_deletor(front_ind, TRUE);
}

void NST_keep_walking(){
    newstatus = WALK_RIGHT | dir;
    curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
}

void NST_turn_around_fast(){
    newstatus = WALK_RIGHT | !dir;
}

void NST_die(){
    kill(curr, WALKSPEED, -2*FALLSPEED);
    newstatus = DEAD;
    status = DEAD;
}

void NST_deletes_and_keeps_going(){
    NST_deletes();
    NST_keep_walking();
}

void GD_obtain(){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 8;
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind)) + 8;
    fx.frames = 0;
    fx.character = goodies_vector[gd_index];
    fx.speed[X] = 0;
    fx.speed[Y] = -BRK_SPEED;
    Actor * result = ACT_add(&fx, &fx_buf);
    if(result){
        if(gd_index >= GD_GET_INDEX( GD_GOLDC ) ) gd_index -= GD_GET_INDEX( GD_GOLDC );
        SPR_setFrame(result->sprite, gd_index);
    }
    break_block_ind(env, front_ind);
}

void GD_killAll(){
    Actor * nastie = ACT_getFirst(&nasties);
    while(nastie){
        kill(nastie, 0, -2*FALLSPEED);
        nastie = nastie->next;
    }
}

void GD_openRdDoor(){
    u16 index = seek_block(env, (GOODIE | GD_RDDOOR) );
    if(index != BOARD_NOTFOUND){
        set_block(env, (GOODIE | GD_RDDOOR_open), index);
    }else{
        //this crashes the game on purpose
        SYS_die("Red Door not found");
    }
}