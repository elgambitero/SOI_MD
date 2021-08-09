#include "SOI.h"

#include "sprites.h"
#include "sound.h"

void PR_arrow_loop();
const Entity PR_arrow = {
    PROJECTILE,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &arrow_spr,
    NULL,
    &PR_arrow_loop,
    NULL,
    {.proj =
        {
        }
    }
};

void PR_canb_loop();
const Entity PR_cannonball = {
    PROJECTILE,
    {3, 7},
    {3, 7},
    PAL_SYS0,
    &cannonball_spr,
    NULL,
    &PR_canb_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_simp_loop();
const Entity PR_simple = {
    PROJECTILE,
    {5, 10},
    {7, 15},
    PAL_SYS1,
    &simple_spr,
    NULL,
    &PR_simp_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_arrow_loop(){
    calc_front(dir);
    calc_front_block();
    switch(crash_into()){
        case BLOCK:
        case FRAME:
            result = ACT_DELETION;
            return;
    }
}

void PR_canb_loop(){
    calc_front(dir);
    calc_front_block();
    if(crash_into()){
        result = ACT_DELETION;
        if(breakable(front_ind)){
            break_block_ind(env, front_ind);
            if(dir)
                brk_debris(front_ind, -CANBALL_SPEED, 0);
            else
                brk_debris(front_ind,  CANBALL_SPEED, 0);
        }
    }
}

__attribute__((always_inline)) static inline u8 calc_front_block_top(){
    return XY_TO_IND( (PX_TO_BLOCK( front )),(  PX_TO_BLOCK( top )) );
}

__attribute__((always_inline)) static inline u8 calc_back_block_top(){
    return XY_TO_IND( (PX_TO_BLOCK( back )),  (PX_TO_BLOCK( top )) );
}

__attribute__((always_inline)) static inline u8 calc_PR_top(){
    top = POS_TO_PX(curr->pos[Y])  - curr->character->size[Y];
}

__attribute__((always_inline)) static inline u8 crashing(u8 ind){
    if( front >= BOARD_X_PX || top >= BOARD_Y_PX  || POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX)
        return FRAME;
    if(SOLID & env->front_blocks[ind])
        return BLOCK;
    return 0;
}
void PR_simp_loop(){
    u8 crashed = 0;
    calc_front(dir);
    calc_back(dir);
    calc_front_floor();
    switch(crashing(front_floor_ind)){
        case FRAME:
            crashed = 1;
            break;
        case BLOCK:
            if(env->front_blocks[front_floor_ind] != CHI){
                //Checking for chisels everywhere is pathetic.
                crashed = 1;
                if(breakable(front_floor_ind)){
                    break_block_ind(env, front_floor_ind);
                    brk_debris(front_floor_ind, curr->speed[X], curr->speed[Y]);
                }
            }
            break;
    }
    u8 front_top_ind = calc_front_block_top();
    switch(crashing(front_top_ind)){
        case FRAME:
            crashed = 1;
            break;
        case BLOCK:
            if(env->front_blocks[front_top_ind] != CHI){
                crashed = 1;
                if(breakable(front_top_ind)){
                    break_block_ind(env, front_top_ind);
                    brk_debris(front_top_ind, curr->speed[X], curr->speed[Y]);
                }
            }
            break;
    }
    if(curr->speed[Y] > 0){
        calc_back_floor();
        calc_front_floor();
        switch(crashing(back_floor_ind)){
            case FRAME:
                crashed = 1;
                break;
            case BLOCK:
                if(env->front_blocks[back_floor_ind] != CHI){
                    crashed = 1;
                    if(breakable(back_floor_ind)){
                        break_block_ind(env, back_floor_ind);
                        brk_debris(back_floor_ind, curr->speed[X], curr->speed[Y]);
                    }
                }
                break;
        }
    }else{
        u8 back_top_ind = calc_back_block_top();
        switch(crashing(back_top_ind)){
            case FRAME:
                crashed = 1;
                break;
            case BLOCK:
                if(env->front_blocks[back_top_ind] != CHI){
                    crashed = 1;
                    if(breakable(back_top_ind)){
                        break_block_ind(env, back_top_ind);
                        brk_debris(back_top_ind, curr->speed[X], curr->speed[Y]);
                    }
                }
                break;
        }
    }
    if(crashed) result = ACT_DELETION;
}
/*
void PR_update(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    curr->character->role.proj.travel();
}
*/