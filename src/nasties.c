#include "SOI.h"

#include "sprites.h"
#include "sound.h"



void NST_spinner_loop();
const Entity NST_spinner = {
    NASTIE,
    {6, 15},
    {7, 15},
    PAL_SYS0,
    &spinner_spr,
    NULL,
    &NST_spinner_loop,
    NULL,
    {.nastie =
        {
            NULL,
            0,
            0,
            0
        }
    }
};

void NST_robo_loop();
const Entity NST_robo = {
    NASTIE,
    {4, 15},
    {7, 15},
    PAL_SYS0,
    &robo_spr,
    NULL,
    &NST_robo_loop,
    NULL,
    {.nastie =
        {
            snd_robo,
            sizeof(snd_robo),
            1000,
            NASTIE_SPEED,
        }
    }
};

void NST_ant_loop();
const Entity NST_ant = {
    NASTIE,
    {7, 8},
    {7, 8},
    PAL_SYS0,
    &ant_spr,
    NULL,
    &NST_ant_loop,
    NULL,
    {.nastie =
        {
            snd_ant,
            sizeof(snd_ant),
            50,
            NASTIE_SPEED,
        }
    }
};

void NST_piggy_loop();
const Entity NST_piggy = {
    NASTIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &piggy_spr,
    NULL,
    &NST_piggy_loop,
    NULL,
    {.nastie =
        {
            snd_piggy,
            sizeof(snd_piggy),
            250,
            NASTIE_SPEED,
        }
    }
};

void NST_teeth_loop();
const Entity NST_teeth = {
    NASTIE,
    {8, 15},
    {8, 15},
    PAL_SYS0,
    &teeth_spr,
    NULL,
    &NST_teeth_loop,
    NULL,
    {.nastie =
        {
            snd_teeth,
            sizeof(snd_teeth),
            1500,
            NASTIE_SPEED,
        }
    }
};

void NST_whR_loop();
const Entity NST_whslowR = {
    NASTIE,
    {7, 14},
    {7, 14},
    PAL_SYS1,
    &whslowR_spr,
    NULL,
    &NST_whR_loop,
    NULL,
    {.nastie =
        {
            snd_wheelie,
            sizeof(snd_wheelie),
            300,
            SLO_SPEED,
        }
    }
};

const Entity NST_whfastR = {
    NASTIE,
    {7, 14},
    {7, 15},
    PAL_SYS1,
    &whfastR_spr,
    NULL,
    &NST_whR_loop,
    NULL,
    {.nastie =
        {
            snd_wheelie,
            sizeof(snd_wheelie),
            300,
            FAST_SPEED,
        }
    }
};

void NST_whL_loop();
const Entity NST_whslowL = {
    NASTIE,
    {7, 14},
    {7, 14},
    PAL_SYS1,
    &whslowL_spr,
    NULL,
    &NST_whL_loop,
    NULL,
    {.nastie =
        {
            snd_wheelie,
            sizeof(snd_wheelie),
            300,
            SLO_SPEED,
        }
    }
};

const Entity NST_whfastL = {
    NASTIE,
    {7, 14},
    {7, 15},
    PAL_SYS1,
    &whfastL_spr,
    NULL,
    &NST_whL_loop,
    NULL,
    {.nastie =
        {
            snd_wheelie,
            sizeof(snd_wheelie),
            300,
            FAST_SPEED,
        }
    }
};

void NST_beanie_loop();
const Entity NST_beanie = {
    NASTIE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &beanie_spr,
    NULL,
    &NST_beanie_loop,
    NULL,
    {.nastie =
        {
            snd_beanie,
            sizeof(snd_beanie),
            250,
            NASTIE_SPEED,
        }
    }
};

void NST_ostrich_loop();
const Entity NST_ostrich = {
    NASTIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &ostrich_spr,
    NULL,
    &NST_ostrich_loop,
    NULL,
    {.nastie =
        {
            snd_ostrich,
            sizeof(snd_ostrich),
            250,
            NASTIE_SPEED,
        }
    }
};

void NST_hippo_loop();
const Entity NST_hippo = {
    NASTIE,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &hippo_spr,
    NULL,
    &NST_hippo_loop,
    NULL,
    {.nastie =
        {
            snd_hippo,
            sizeof(snd_hippo),
            250,
            NASTIE_SPEED,
        }
    }
};

void BS_gargoyle_loop();
const Entity BS_gargoyle = {
    NASTIE,
    {24, 48},
    {24, 48},
    PAL_SYS0,
    &gargoyle_spr,
    NULL,
    &BS_gargoyle_loop,
    NULL,
    {.nastie =
        {
            NULL,
            NULL,
            NULL,
            0,
        }
    }
};

const Entity BS_gargoyle1 = {
    NASTIE,
    {24, 48},
    {24, 48},
    PAL_SYS0,
    &gargoyle_spr,
    NULL,
    &BS_gargoyle_loop,
    NULL,
    {.nastie =
        {
            NULL,
            NULL,
            NULL,
            1,
        }
    }
};

const Entity BS_gargoyle2 = {
    NASTIE,
    {24, 48},
    {24, 48},
    PAL_SYS0,
    &gargoyle_spr,
    NULL,
    &BS_gargoyle_loop,
    NULL,
    {.nastie =
        {
            NULL,
            NULL,
            NULL,
            2,
        }
    }
};

void BS_knight_loop();
const Entity BS_knight = {
    NASTIE,
    {12, 40},
    {18, 40},
    PAL_SYS1,
    &knight_spr,
    NULL,
    &BS_knight_loop,
    NULL,
    {.nastie =
        {
            NULL,
            NULL,
            NULL,
            NULL,
        }
    }
};

__attribute__((always_inline)) static inline void NST_still_fall(){
    newstatus = FALL_RIGHT;
    status = FALL_RIGHT; //Ugly hack to prevent animation change.
    curr->speed[Y] = FALLSPEED;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_still_land(){
    curr->speed[Y] = 0;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_fall(){
    newstatus = dir | FALL_RIGHT;
    curr->speed[Y] = FALLSPEED;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_turn_around(){
    newstatus = dir | RIGHT_TURN_LEFT;
    curr->frames = TURN_FRAMES;
    curr->speed[X] = 0;
}
__attribute__((always_inline)) static inline void NST_turn_around_fast(){
    newstatus = WALK_RIGHT | !dir;
}

__attribute__((always_inline)) static inline void NST_turn_up(){
    newstatus = dir | DOWN_TURN_UP;
    curr->frames = TURN_FRAMES;
    curr->speed[Y] = 0;
}
__attribute__((always_inline)) static inline void NST_turn_up_fast(){
    newstatus = WALK_UP | !dir;
}

__attribute__((always_inline)) static inline void NST_attack(){
    newstatus = dir | ATTACK_RIGHT_IN;
    curr->frames = ATTK_FRAMES;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_attack_vert(){
    newstatus = dir | ATTACK_DOWN_IN;
    curr->frames = ATTK_FRAMES;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_breaks(){
    calc_front(dir);
    calc_front_block();
    break_block_ind(env, front_ind);
    brk_debris(front_ind, BRK_SPEED, 0);
    XGM_setPCM(SFX_IND, snd_metal_bonk, sizeof(snd_metal_bonk));
    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
}

__attribute__((always_inline)) static inline void NST_deletes(){
    calc_front(dir);
    calc_front_block();
    break_block_ind(env, front_ind);
    summon_deletor(front_ind, TRUE);
}

__attribute__((always_inline)) static inline void NST_keep_walking(){
    newstatus = WALK_RIGHT | dir;
    curr->speed[X] = dir ? 
        -curr->character->role.nastie.speed : curr->character->role.nastie.speed;
}


__attribute__((always_inline)) static inline void NST_die(){
    kill(curr, WALKSPEED, -2*FALLSPEED);
    newstatus = DEAD;
    status = DEAD;
}

__attribute__((always_inline)) static inline void NST_deletes_and_keeps_going(){
    NST_deletes();
    NST_keep_walking();
}

__attribute__((always_inline)) static inline void NST_keep_dying(){
    if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
        result = ACT_DELETION;
    }
    curr->speed[Y] += GRAVITY;
}

__attribute__((always_inline)) static inline s16 ABS(s16 x){
    return x > 0 ? x : -x;
}

void NST_spinner_loop(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_still_fall();
                return;
            }
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                NST_still_land();
            }
        break;
    }
}

void NST_robo_loop(){
    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around();
                    return;
                case BLOCK:
                    if(breakable(front_ind)) NST_attack();
                    else NST_turn_around();
                    return;
                default:
                    break;
            }
            calc_front_floor();
            if(cliff()){
                NST_turn_around();
                return;
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
            NST_breaks();
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            NST_keep_walking();
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                NST_die();
                break;
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

void NST_ant_loop(){

    PHY_despawn();

    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case BLOCK:
                case FRAME:
                    NST_turn_around();
                    return;
                default:
                    NST_keep_walking();
                    return;
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
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                NST_keep_walking();
                break;
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

void NST_piggy_loop(){

    PHY_despawn();

    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around(); //why tho.
                    return;
                case BLOCK:
                    if(breakable(front_ind)) NST_attack();
                    else NST_turn_around();
                    return;
                default:
                    break;
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
            NST_deletes();
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            NST_turn_around_fast();
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                NST_keep_walking();
                break;
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

void NST_teeth_loop(){
    PHY_despawn();

    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around();
                    return;
                case BLOCK:
                    if(breakable(front_ind)) NST_deletes_and_keeps_going();
                    else NST_turn_around();
                    return;
                default:
                    break;
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
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                NST_keep_walking();
                return;
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

#define PX_MARGIN 4

void NST_whR_loop(){
    switch(status & (ANIM_MSK | DIR_MSK)){ //dir is not used in this loop
        case NST_R_RIGHT:
            //Roll-off condition
            calc_front(0);
            calc_back(0);
            if(!PHY_crash_point(front, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               !PHY_crash_point(back, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(back - PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = NST_R_DOWN;
                   status = NST_R_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS(( (back & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = curr->character->role.nastie.speed;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(front, PHY_mid_height() ) ){
                   newstatus = NST_R_UP;
                   status = NST_R_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ((front & ( BLOCK_TO_PX(0xFFFF) ) ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -curr->character->role.nastie.speed;
                   return;
            }
            break;
        case NST_R_DOWN:
            //Roll-off condition
            calc_front(1);
            PHY_calc_top();
            if(!PHY_crash_point(front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               !PHY_crash_point(front - PX_MARGIN, top) && 
               PHY_crash_point(front - PX_MARGIN, top - PX_MARGIN)){
                   newstatus = NST_R_LEFT;
                   status = NST_R_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[Y] ));
                   curr->speed[X] = -curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front - PX_MARGIN, PHY_mid_height() ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) ) ){
                   newstatus = NST_R_RIGHT;
                   status = NST_R_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) );
                   curr->speed[X] = curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
        case NST_R_LEFT:
            //Roll-off condition
            calc_front(1);
            calc_back(1);
            PHY_calc_top();
            if(!PHY_crash_point( front , top - PX_MARGIN) && 
               !PHY_crash_point( back , top - PX_MARGIN) && 
               PHY_crash_point( back + PX_MARGIN ,  top - PX_MARGIN)){
                   newstatus = NST_R_UP;
                   status = NST_R_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS(( ((back & ( BLOCK_TO_PX(0xFFFF) ) ) + 16 ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -curr->character->role.nastie.speed;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , top - PX_MARGIN) && 
               PHY_crash_point( front , PHY_mid_height() ) ){
                   newstatus = NST_R_DOWN;
                   status = NST_R_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( (((front & ( BLOCK_TO_PX(0xFFFF) ) ) + 16 ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = curr->character->role.nastie.speed;
                   return;
            }
            break;
        case NST_R_UP:
            //Roll-off condition
            calc_front(0);
            PHY_calc_top();
            if(!PHY_crash_point( front + PX_MARGIN, top ) && 
               !PHY_crash_point( front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               PHY_crash_point( front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = NST_R_RIGHT;
                   status = NST_R_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( (POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) );
                   curr->speed[X] = curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front + PX_MARGIN, PHY_mid_height()  ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X])  , top ) ){
                   newstatus = NST_R_LEFT;
                   status = NST_R_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[Y] ));
                   curr->speed[X] = -curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
    }
}

void NST_whL_loop(){
    switch(status & (ANIM_MSK | DIR_MSK)){ //dir is not used in this loop
        case NST_L_LEFT:
            //Roll-off condition
            calc_front(1);
            calc_back(1);
            if(!PHY_crash_point(front, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               !PHY_crash_point(back, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(back + PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = NST_L_DOWN;
                   status = NST_L_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( (back & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) - curr->character->size[X] ) );
                   curr->speed[X] = 0;
                   curr->speed[Y] = curr->character->role.nastie.speed;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(front, PHY_mid_height() ) ){
                   newstatus = NST_L_UP;
                   status = NST_L_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( (front & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[X]) );
                   curr->speed[X] = 0;
                   curr->speed[Y] = -curr->character->role.nastie.speed;
                   return;
            }
            break;
        case NST_L_DOWN:
            //Roll-off condition
            calc_front(0);
            PHY_calc_top();
            if(!PHY_crash_point(front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) &&
               !PHY_crash_point(front + PX_MARGIN, top) &&
               PHY_crash_point(front + PX_MARGIN, top - PX_MARGIN)){
                   newstatus = NST_L_RIGHT;
                   status = NST_L_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[Y] ) );
                   curr->speed[X] = curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front + PX_MARGIN, PHY_mid_height() ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) ) ){
                   newstatus = NST_L_LEFT;
                   status = NST_L_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) );
                   curr->speed[X] = -curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
        case NST_L_RIGHT:
            //Roll-off condition
            calc_front(0);
            calc_back(0);
            PHY_calc_top();
            if(!PHY_crash_point( front , top - PX_MARGIN) && 
               !PHY_crash_point( back , top - PX_MARGIN) && 
               PHY_crash_point( back - PX_MARGIN ,  top - PX_MARGIN)){
                   newstatus = NST_L_UP;
                   status = NST_L_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( ( back & ( BLOCK_TO_PX(0xFFFF) ) ) ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -curr->character->role.nastie.speed;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , top - PX_MARGIN) && 
               PHY_crash_point( front , PHY_mid_height() ) ){
                   newstatus = NST_L_DOWN;
                   status = NST_L_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ((front & ( BLOCK_TO_PX(0xFFFF) ) ) ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = curr->character->role.nastie.speed;
                   return;
            }
            break;
        case NST_L_UP:
            //Roll-off condition
            calc_front(1);
            PHY_calc_top();
            if(!PHY_crash_point( front - PX_MARGIN, top ) && 
               !PHY_crash_point( front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               PHY_crash_point( front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = NST_L_LEFT;
                   status = NST_L_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) ));
                   curr->speed[X] = -curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front - PX_MARGIN, PHY_mid_height()  ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X])  , top ) ){
                   newstatus = NST_L_RIGHT;
                   status = NST_L_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[Y] ));
                   curr->speed[X] = curr->character->role.nastie.speed;;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
    }
}

#define RIGHT 0
#define LEFT  1
#define DOWN  2
#define UP    3

#define BEAN_ATTK_FRAMES 64
#define BEAN_DELETE_FRAMES 64

void NST_beanie_deletor(u8 ind, u8 direction){
    XGM_setPCM(SFX_IND, snd_beanie_fire, sizeof(snd_beanie_fire));
    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
    fx.status = direction;
    fx.character = &FX_beanie_atk;
    fx.frames = BEAN_DELETE_FRAMES;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(ind)) + 7;
    fx.pos[Y] = BLOCK_TO_PX( (IND_TO_Y(ind) + 1) );
    fx.timer = 0;
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    ACT_add(&fx, &fx_buf);
}

__attribute__((always_inline)) static inline void NST_beanie_attackH(){
    newstatus = dir | ATTACK_RIGHT_IN;
    curr->frames = BEAN_ATTK_FRAMES;
    curr->speed[X] = 0;
}

__attribute__((always_inline)) static inline void NST_beanie_deleteH(){
    calc_front(dir);
    calc_front_block();
    break_block_ind(env, front_ind);
    NST_beanie_deletor(front_ind, dir);
    //summon_deletor(front_ind, TRUE);
}
__attribute__((always_inline)) static inline void NST_beanie_deleteV(){
    
}

void NST_beanie_loop(){

    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around();
                    return;
                case BLOCK:
                    if(breakable(front_ind)) {
                        NST_beanie_attackH();
                        NST_beanie_deleteH();
                    }
                    else NST_turn_around();
                    return;
                default:
                    break;
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
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            NST_keep_walking();
        break;
        case WALK_DOWN:
            switch( PHY_crash_point(POS_TO_PX(curr->pos[X]), 
                                    POS_TO_PX(curr->pos[Y]) - (dir ? curr->character->size[Y] : 0) ) ){
                case FRAME:
                    curr->pos[Y] &= FLOOR_CORR;
                    curr->speed[Y] = 0;
                    NST_turn_up();
                    break;
                case BLOCK:
                    if(dir){
                        calc_top_block();
                        if(breakable(top_ind)) {
                            NST_attack_vert();
                        }
                        else{
                            curr->pos[Y] &= FLOOR_CORR;
                            curr->pos[Y] += PX_TO_POS(16);
                            curr->speed[Y] = 0;
                            NST_turn_up();
                        }
                    }else{
                        calc_floor();
                        if(breakable(floor_ind)) {
                            NST_attack_vert();
                        }
                        else{
                            curr->pos[Y] &= FLOOR_CORR;
                            curr->speed[Y] = 0;
                            NST_turn_up();
                        }
                    }
                    
                    break;
            }
            break;
        case DOWN_TURN_UP:
            if(curr->frames--) return;
            newstatus = WALK_DOWN | !dir;
            curr->speed[Y] = !dir ? 
                -curr->character->role.nastie.speed : curr->character->role.nastie.speed;
            curr->pos[Y] += dir ? COLL_CORR : -COLL_CORR;
            break;
        case ATTACK_DOWN_IN:
            if(curr->frames--) return;
            //NST_deletes(); //Rewrite for beanies
            newstatus = dir | ATTACK_DOWN_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[Y] = 0;
            break;
        case ATTACK_DOWN_OUT:
            if(curr->frames--) return;
            //NST_turn_up_fast();
            //NST_keep_walkingV();
            break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

void NST_ostrich_loop(){
    
    PHY_despawn();

    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case BLOCK:
                case FRAME:
                    NST_turn_around();
                    return;
                default:
                    NST_keep_walking();
                    return;
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
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                
                Actor * player = NULL;
                if(blue_player && green_player){
                    //randomly go after one of the players.
                    if(RNG_get() & 0x01)
                        player = blue_player;
                    else
                        player = green_player;
                }     
                player = blue_player ? blue_player : green_player;
                if(!player){
                    NST_keep_walking();
                    return;
                }
                if(player->pos[X] > curr->pos[X]){
                    if(dir)
                        NST_turn_around();
                    else
                        NST_keep_walking();
                }else{
                    if(dir)
                        NST_keep_walking();
                    else
                        NST_turn_around();
                }
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}

void NST_hippo_loop(){
    PHY_despawn();

    calc_center_block();
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                NST_fall();
                return;
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around();
                    return;
                case BLOCK:
                    if(breakable(front_ind)) NST_attack();
                    else NST_turn_around();
                    return;
                default:
                    break;
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
            NST_deletes();
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            NST_keep_walking();
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                NST_keep_walking();
                break;
            }
        break;
        case DEAD:
            NST_keep_dying();
        break;
    }
}




void BS_gargoyle_loop(){
    if(curr->frames--) {
        return;
    }
    switch(status & ANIM_MSK){
        case BS_BIRTH:
            curr->frames = GL_ATTK_FRAMES;
            newstatus = BS_ATTK;
            break;
        case BS_IDLE:
            curr->frames = GL_ATTK_FRAMES;
            newstatus = BS_ATTK;
            break;
        case BS_ATTK:
            curr->frames = GL_IDLE_FRAMES;
            newstatus = BS_IDLE;
            //Decide which player to shoot
            Actor * target = NULL;
            if(green_player && blue_player){
                target = (RNG_get() & 0x01) ? blue_player : green_player;
            }else{
                target = blue_player ? blue_player : green_player;
            }
            if(!target) return; //Return if for whatever reason there is no eligible target.
            s16 delta[2];
            delta[X] = target->pos[X] - curr->pos[X];
            delta[Y] = target->pos[Y] - (curr->pos[Y] - PX_TO_POS(GL_FIRE_HEIGHT) );
            //Approximating with norm 1:
            u16 norm = (ABS(delta[X]) + ABS(delta[Y]))/2;
            fx.speed[X] = (delta[X] * GL_PROJ_SPEED) / norm;
            fx.speed[Y] = (delta[Y] * GL_PROJ_SPEED) / norm;
            fx.status = 0;
            switch(curr->character->role.nastie.speed){ //Incredibly inappropriate use of bytes
                case 0:
                    fx.character = &PR_simple;
                    break;
                case 1:
                    if(RNG_get() > 128 ){
                        fx.character = &PR_ultrabuster;
                    }else{
                        fx.character = &PR_simple;
                    }
                    break;
                case 2:
                    fx.character = &PR_simple;
                    break;
                default:
                    fx.character = &PR_simple;
                    break;
            }
            fx.pos[X] = POS_TO_PX(curr->pos[X]);
            fx.pos[Y] = POS_TO_PX(curr->pos[Y]) - GL_FIRE_HEIGHT;
            ACT_add(&fx, &projectiles);

            XGM_setPCM(SFX_IND, snd_gargoyle_fire, sizeof(snd_gargoyle_fire));
            XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
            break;
    }
}

//Helper macros for the probability limits.
#define GOLDC_LIMIT (KN_PROB_GDi_SILVC + KN_PROB_GDi_GOLDC)
#define GOLD_LIMIT (GOLDC_LIMIT + KN_PROB_GDi_GOLD)
#define GEM_LIMIT (GOLD_LIMIT + KN_PROB_GDi_GEM)
#define CLK3h_LIMIT (GEM_LIMIT + KN_PROB_GDi_CLK3h)
#define CLK6h_LIMIT (CLK3h_LIMIT + KN_PROB_GDi_CLK6h)
#define CLK9h_LIMIT (CLK6h_LIMIT + KN_PROB_GDi_CLK9h)
#define CLK12h_LIMIT (CLK9h_LIMIT + KN_PROB_GDi_CLK12h)
#define SHLD_LIMIT (CLK12h_LIMIT + KN_PROB_GDi_SHLD)
#define BOOT_LIMIT (SHLD_LIMIT + KN_PROB_GDi_BOOT)
#define UP1_LIMIT (BOOT_LIMIT + KN_PROB_GDi_1UP)
#define M2X_LIMIT (UP1_LIMIT + KN_PROB_GDi_2x)
#define M3X_LIMIT (M2X_LIMIT + KN_PROB_GDi_3x)
#define M4X_LIMIT (M3X_LIMIT + KN_PROB_GDi_4x)
#define M5X_LIMIT (M4X_LIMIT + KN_PROB_GDi_5x)
#define BALL_LIMIT (M5X_LIMIT + KN_PROB_GDi_BALL)
#define ARROW_LIMIT (BALL_LIMIT + KN_PROB_GDi_ARROW)

u8 BS_knight_good(u8 dice){
    //WARNING: NON-STANDARD RANGE SWITCH:
    switch(dice){
        case 0 ... KN_PROB_GDi_SILVC-1:
            return (GDi_SILVC >> GOOD_TYP_SHFT);
        case KN_PROB_GDi_SILVC ... GOLDC_LIMIT - 1:
            return (GDi_GOLDC >> GOOD_TYP_SHFT);
        case GOLDC_LIMIT ... GOLD_LIMIT - 1:
            return (GDi_GOLD >> GOOD_TYP_SHFT);
        case GOLD_LIMIT ... GEM_LIMIT - 1:
            return (GDi_GEM >> GOOD_TYP_SHFT);
        case GEM_LIMIT ... CLK3h_LIMIT - 1:
            return (GDi_CLK3h >> GOOD_TYP_SHFT);
        case CLK3h_LIMIT ... CLK6h_LIMIT - 1:
            return (GDi_CLK6h >> GOOD_TYP_SHFT);
        case CLK6h_LIMIT ... CLK9h_LIMIT - 1:
            return (GDi_CLK9h >> GOOD_TYP_SHFT);
        case CLK9h_LIMIT ... CLK12h_LIMIT - 1:
            return (GDi_CLK12h >> GOOD_TYP_SHFT);
        case CLK12h_LIMIT ... SHLD_LIMIT - 1:
            return (GDi_SHLD >> GOOD_TYP_SHFT);
        case SHLD_LIMIT ... BOOT_LIMIT - 1:
            return (GDi_BOOT >> GOOD_TYP_SHFT);
        case BOOT_LIMIT ... UP1_LIMIT - 1:
            return (GDi_1UP >> GOOD_TYP_SHFT);
        case UP1_LIMIT ... M2X_LIMIT - 1:
            return (GDi_2x >> GOOD_TYP_SHFT);
        case M2X_LIMIT ... M3X_LIMIT - 1:
            return (GDi_3x >> GOOD_TYP_SHFT);
        case M3X_LIMIT ... M4X_LIMIT - 1:
            return (GDi_4x >> GOOD_TYP_SHFT);
        case M4X_LIMIT ... M5X_LIMIT - 1:
            return (GDi_5x >> GOOD_TYP_SHFT);
        case M5X_LIMIT ... BALL_LIMIT - 1:
            return (GDi_BALL >> GOOD_TYP_SHFT);
        case BALL_LIMIT ... ARROW_LIMIT - 1:
            return (GDi_ARROW >> GOOD_TYP_SHFT);
        default:
            return (GDi_SILVC >> GOOD_TYP_SHFT);
    }
}

void BS_knight_loop(){
if(curr->frames--) {
        return;
    }
    switch(status & ANIM_MSK){
        case BS_BIRTH:
            curr->frames = KN_ATTK_FRAMES;
            newstatus = BS_ATTK;
            break;
        case BS_IDLE:
            curr->frames = KN_ATTK_FRAMES;
            newstatus = BS_ATTK;
            break;
        case BS_ATTK:
            curr->frames = KN_IDLE_FRAMES;
            newstatus = BS_IDLE;
            u8 target_ind;
            u8 count = 6;
            //Choose block
            do{
                target_ind = RNG_get();
                count--;
            }while(count && ( (env->back_blocks[target_ind] == CHI) ||
                                (target_ind >= BOARD_BUFFER) ||
                                ((env->front_blocks[target_ind] & BLK_TYPE) == GOODIE)));
            if(!count) return;
            //Choose goodie
            u8 good = BS_knight_good(RNG_get());

            //Fire target
            fx.status = 0;
            fx.character = &PR_packet;
            fx.actorData.packData.block = target_ind;
            fx.actorData.packData.good = good;
            fx.pos[X] = POS_TO_PX(curr->pos[X]);
            fx.pos[Y] = POS_TO_PX(curr->pos[Y]) - GL_FIRE_HEIGHT;

            s16 delta[2];
            delta[X] = (BLOCK_TO_PX( IND_TO_X(target_ind) ) + 8 ) - POS_TO_PX(curr->pos[X]);
            delta[Y] = (BLOCK_TO_PX( IND_TO_Y(target_ind) ) + 8 + 5) - (POS_TO_PX(curr->pos[Y]) - GL_FIRE_HEIGHT );
            //Approximating with norm 1:
            u16 norm = (ABS(delta[X]) + ABS(delta[Y]))/2;
            fx.speed[X] = (delta[X] * GL_PROJ_SPEED) / norm;
            fx.speed[Y] = (delta[Y] * GL_PROJ_SPEED) / norm;
            u16 sp_norm = (ABS(fx.speed[X]) + ABS(fx.speed[Y]))/2;
            fx.timer = PX_TO_POS(norm) / sp_norm;
            ACT_add(&fx, &fx_buf);

            break;
    }
}