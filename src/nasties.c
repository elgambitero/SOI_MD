#include "nasties.h"

#include "physics.h"
#include "gameplay.h"
#include "sound.h"
#include "blocks.h"

void NST_still_fall();
void NST_still_land();
void NST_fall();
void NST_turn_around();
void NST_attack();
void NST_breaks();
void NST_deletes();
void NST_keep_walking();
void NST_turn_around_fast();
void NST_die();
void NST_deletes_and_keeps_going();





const Entity ant_spawner_ent = {
    NASTIE | STILL | CREATES_NASTIE,
    {
        {8, 15},
        {7, 15},
        PAL_SYS0,
        0,
        0,
        0,
        0,
        NULL,
        NULL,
        NST_still_fall,
        NST_still_land,
        NULL,
        NULL
    }
};

const Entity spinner_ent = {
    NASTIE | STILL,
    {
        {6, 15},
        {7, 15},
        PAL_SYS0,
        0,
        &spinner_spr,
        0,
        0,
        NULL,
        NULL,
        &NST_still_fall,
        &NST_still_land,
        NULL,
        NULL
    }
};

const Entity robo_ent = {
    NASTIE | WALKS | DIES_ON_LEAP | BREAKS | GOES_THRU,
    {
        {4, 15},
        {7, 15},
        PAL_SYS0,
        1000,
        &robo_spr,
        snd_robo,
        sizeof(snd_robo),
        &NST_attack,
        &NST_turn_around,
        &NST_fall,
        &NST_die,
        &NST_breaks,
        &NST_keep_walking
    }
};

const Entity ant_ent = {
    NASTIE | WALKS | LEAPS,
    {
        {7, 8},
        {7, 8},
        PAL_SYS0,
        50,
        &ant_spr,
        snd_ant,
        sizeof(snd_ant),
        &NST_turn_around,
        NULL,
        &NST_fall,
        &NST_keep_walking,
        NULL,
        NULL
    }
};

const Entity piggy_ent = {
    NASTIE | WALKS | LEAPS | DELETES,
    {
        {7, 15},
        {7, 15},
        PAL_SYS1,
        250,
        &piggy_spr,
        snd_piggy,
        sizeof(snd_piggy),
        &NST_attack,
        NULL,
        &NST_fall,
        &NST_keep_walking,
        &NST_deletes,
        &NST_turn_around_fast
    }
};

const Entity teeth_ent = {
    NASTIE | WALKS | LEAPS | DELETES | GOES_THRU,
    {
        {8, 15},
        {8, 15},
        PAL_SYS0,
        1500,
        &teeth_spr,
        snd_teeth,
        sizeof(snd_teeth),
        &NST_deletes_and_keeps_going,
        NULL,
        &NST_fall,
        &NST_keep_walking,
        &NST_deletes,
        &NST_keep_walking
    }
};





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
    XGM_setPCM(SFX_IND, snd_metal_bonk, sizeof(snd_metal_bonk));
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
