#include "SOI.h"

#include "sprites.h"
#include "sound.h"


#define NASTIE_SPEED WALKSPEED

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

void NST_update();

const Entity NST_spinner = {
    NASTIE | STILL,
    {6, 15},
    {7, 15},
    PAL_SYS0,
    &spinner_spr,
    NULL,
    &NST_update,
    NULL,
    {.nastie =
        {
            NULL,
            0,
            0,
            0,
            NULL,
            NULL,
            &NST_still_fall,
            &NST_still_land,
            NULL,
            NULL
        }
    }
};

const Entity NST_robo = {
    NASTIE | WALKS | DIES_ON_LEAP | BREAKS | GOES_THRU,
    {4, 15},
    {7, 15},
    PAL_SYS0,
    &robo_spr,
    NULL,
    &NST_update,
    NULL,
    {.nastie =
        {
            snd_robo,
            sizeof(snd_robo),
            1000,
            NASTIE_SPEED,
            &NST_attack,
            &NST_turn_around,
            &NST_fall,
            &NST_die,
            &NST_breaks,
            &NST_keep_walking
        }
    }
};

const Entity NST_ant = {
    NASTIE | WALKS | LEAPS,
    {7, 8},
    {7, 8},
    PAL_SYS0,
    &ant_spr,
    NULL,
    &NST_update,
    NULL,
    {.nastie =
        {
            snd_ant,
            sizeof(snd_ant),
            50,
            NASTIE_SPEED,
            &NST_turn_around,
            NULL,
            &NST_fall,
            &NST_keep_walking,
            NULL,
            NULL
        }
    }
};

const Entity NST_piggy = {
    NASTIE | WALKS | LEAPS | DELETES,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &piggy_spr,
    NULL,
    &NST_update,
    NULL,
    {.nastie =
        {
            snd_piggy,
            sizeof(snd_piggy),
            250,
            NASTIE_SPEED,
            &NST_attack,
            NULL,
            &NST_fall,
            &NST_keep_walking,
            &NST_deletes,
            &NST_turn_around_fast
        }
    }
};

const Entity NST_teeth = {
    NASTIE | WALKS | LEAPS | DELETES | GOES_THRU,
    {8, 15},
    {8, 15},
    PAL_SYS0,
    &teeth_spr,
    NULL,
    &NST_update,
    NULL,
    {.nastie =
        {
            snd_teeth,
            sizeof(snd_teeth),
            1500,
            NASTIE_SPEED,
            &NST_deletes_and_keeps_going,
            NULL,
            &NST_fall,
            &NST_keep_walking,
            &NST_deletes,
            &NST_keep_walking
        }
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
    curr->speed[X] = dir ? 
        -curr->character->role.nastie.speed : curr->character->role.nastie.speed;
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

void NST_update(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER){
            result = ACT_DELETION;
            return;
        };
    }

    calc_center_block();
    set_presence(center_ind);
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                if(curr->character->role.nastie.onFall){
                    (*curr->character->role.nastie.onFall)();
                    return;
                }
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around(); //why tho.
                    return;
                case BLOCK:
                    if(breakable(front_ind)) (*curr->character->role.nastie.onCrash)();
                    else NST_turn_around();
                    return;
                default:
                    break;
            }
            calc_front_floor();
            if(cliff()){
                if(curr->character->role.nastie.onTrip){
                    (*curr->character->role.nastie.onTrip)();
                    return;
                }
            }
            curr->speed[X] = dir ? 
                -curr->character->role.nastie.speed : curr->character->role.nastie.speed;
        break;
        case RIGHT_TURN_LEFT:
            if(curr->frames--) return;
            newstatus = WALK_RIGHT | !dir;
            curr->speed[X] = dir ? 
                curr->character->role.nastie.speed : -curr->character->role.nastie.speed;
            curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
        break;
        case ATTACK_RIGHT_IN: 
            if(curr->frames--) return;
            if(curr->character->role.nastie.onAttack){
                (*curr->character->role.nastie.onAttack)();
            }
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            (*curr->character->role.nastie.onFinishAttack)();
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                (*curr->character->role.nastie.onLand)();
                break;
            }
        break;
        case DEAD:
            if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
                result = ACT_DELETION;
            }
            curr->speed[Y] += GRAVITY;
        break;
    }

    if(curr->status == DEAD)
        return;
    // TODO: THIS NEEDS A REFACTOR
    if(collided){
        if(blue_player && bl_stat->effect != SHIELDED && ACT_collision(blue_player, curr)){
            kill(blue_player, 0, -2*FALLSPEED);
            blue_player = NULL;
        }
        if(green_player && gr_stat->effect != SHIELDED && ACT_collision(green_player, curr)){
            kill(green_player, 0, -2*FALLSPEED);
            green_player = NULL;
        }
        if(curr->character->attr & MOVT_BITMSK){
            Actor * proj_act = ACT_getFirst(&bp_projectiles);
            while(proj_act){
                if(ACT_collision(proj_act, curr)){
                    kill(curr, 0, -2*FALLSPEED);
                    kill(proj_act, 0, 0);
                    newstatus = DEAD;
                    status = DEAD; //Ugly hack to prevent animation from changing.
                    bl_stat->score += curr->character->role.nastie.points;
                }
                proj_act = proj_act->next;
            }
            proj_act = ACT_getFirst(&gp_projectiles);
            while(proj_act){
                if(ACT_collision(proj_act, curr)){
                    kill(curr, 0, -2*FALLSPEED);
                    kill(proj_act, 0, 0);
                    newstatus = DEAD;
                    status = DEAD; //Ugly hack to prevent animation from changing.
                    gr_stat->score += curr->character->role.nastie.points;
                }
                proj_act = proj_act->next;
            }
        }
    }
}