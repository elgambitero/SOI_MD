#include "behavior.h"

#include "physics.h"
#include "sound.h"

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