#include "SOI.h"

#include "sprites.h"
#include "sound.h"


#define NASTIE_SPEED WALKSPEED

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
            NULL,
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

__attribute__((always_inline)) static inline void NST_attack(){
    newstatus = dir | ATTACK_RIGHT_IN;
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

__attribute__((always_inline)) static inline void NST_turn_around_fast(){
    newstatus = WALK_RIGHT | !dir;
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

__attribute__((always_inline)) static inline void NST_despawn(){
    curr->timer++;
    if(curr->timer == MAX_TIMER){
        result = ACT_DELETION;
        return;
    };
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
/* OLD nastie_loop()
void NST_update(){
    if(curr->timer){
        curr->timer++;
        if(curr->timer == MAX_TIMER){
            result = ACT_DELETION;
            return;
        };
    }

    calc_center_block();
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
}
*/

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

    NST_despawn();

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

    NST_despawn();

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
    NST_despawn();

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
            Actor * target = blue_player;
            //fire projectile.
            //fx.speed[X] = PX_TO_POS(-2);
            //fx.speed[Y] = PX_TO_POS(2); //Provisional
            s16 delta[2];
            delta[X] = target->pos[X] - curr->pos[X];
            delta[Y] = target->pos[Y] - (curr->pos[Y] - PX_TO_POS(GL_FIRE_HEIGHT) );
            //Approximating with norm 1:
            u16 norm = (ABS(delta[X]) + ABS(delta[Y]))/2;
            fx.speed[X] = (delta[X] * GL_PROJ_SPEED) / norm;
            fx.speed[Y] = (delta[Y] * GL_PROJ_SPEED) / norm;
            fx.status = 0;
            fx.character = &PR_simple;
            fx.pos[X] = POS_TO_PX(curr->pos[X]);
            fx.pos[Y] = POS_TO_PX(curr->pos[Y]) - GL_FIRE_HEIGHT;
            ACT_add(&fx, &projectiles);

            XGM_setPCM(SFX_IND, snd_gargoyle_fire, sizeof(snd_gargoyle_fire));
            XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
            break;
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
            //Decide and fire gift.
            break;
    }
}