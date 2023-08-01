#include "SOI.h"

#include "sprites.h"

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

void PR_ub_loop();
const Entity PR_ultrabuster = {
    PROJECTILE,
    {5, 10},
    {7, 15},
    PAL_SYS0,
    &ultrabuster_spr,
    NULL,
    &PR_ub_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

const Entity PR_spawner = {
    PROJECTILE,
    {5, 10},
    {7, 15},
    PAL_SYS0,
    &spawner_spr,
    NULL,
    &PR_simp_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_packet_loop();
void PR_packet_land();
const Entity PR_packet = {
    PROJECTILE,
    {5, 10},
    {7, 15},
    PAL_SYS0,
    &packet_spr,
    NULL,
    &PR_packet_loop,
    &PR_packet_land,
    {.proj = 
        {
        }
    }
};

void PR_R_ball_loop();
const Entity PR_R_ball = {
    PROJECTILE,
    {6, 12},
    {8, 15},
    PAL_SYS0,
    &R_ball_spr,
    NULL,
    &PR_R_ball_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_L_ball_loop();
const Entity PR_L_ball = {
    PROJECTILE,
    {6, 12},
    {8, 15},
    PAL_SYS0,
    &L_ball_spr,
    NULL,
    &PR_L_ball_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_walkp_loop();
const Entity PR_walkp = {
    PROJECTILE,
    {7, 15},
    {7, 10},
    PAL_SYS0,
    &walkp_spr,
    NULL,
    &PR_walkp_loop,
    NULL,
    {.proj = 
        {
        }
    }
};

void PR_arrow_loop(){
    PHY_calc_front(dir);
    PHY_calc_front_block();
    switch(PHY_crash_into()){
        case BLOCK:
        case FRAME:
            result = ACT_DELETION;
            return;
    }
}

void PR_canb_loop(){
    PHY_calc_front(dir);
    PHY_calc_front_block();
    if(PHY_crash_into()){
        result = ACT_DELETION;
        if(PHY_breakable(front_ind)){
            BRD_break_block_ind(env, front_ind);
            if(dir)
                PHY_brk_debris(front_ind, -CANBALL_SPEED, 0);
            else
                PHY_brk_debris(front_ind,  CANBALL_SPEED, 0);
        }
    }
}

void PR_walkp_loop(){ //Same as cannonball
    PHY_calc_front(dir);
    PHY_calc_front_block();
    if(PHY_crash_into()){
        result = ACT_DELETION;
        if(PHY_breakable(front_ind)){
            BRD_break_block_ind(env, front_ind);
            if(dir)
                PHY_brk_debris(front_ind, -CANBALL_SPEED, 0);
            else
                PHY_brk_debris(front_ind,  CANBALL_SPEED, 0);
        }
    }
}

__attribute__((always_inline)) static inline u8 calc_front_block_top(){
    return XY_TO_IND( (PX_TO_BLOCK( front )),(  PX_TO_BLOCK( top )) );
}

__attribute__((always_inline)) static inline u8 calc_back_block_top(){
    return XY_TO_IND( (PX_TO_BLOCK( back )),  (PX_TO_BLOCK( top )) );
}

__attribute__((always_inline)) static inline void calc_PR_top(){
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
    PHY_calc_front(dir);
    PHY_calc_back(dir);
    PHY_calc_front_floor();
    switch(crashing(front_floor_ind)){
        case FRAME:
            crashed = 1;
            break;
        case BLOCK:
            if(env->front_blocks[front_floor_ind] != CHI){
                //Checking for chisels everywhere is pathetic.
                crashed = 1;
                if(PHY_breakable(front_floor_ind)){
                    BRD_break_block_ind(env, front_floor_ind);
                    PHY_brk_debris(front_floor_ind, curr->speed[X], curr->speed[Y]);
                }
            }
            break;
    }
    calc_PR_top();
    u8 front_top_ind = calc_front_block_top();
    switch(crashing(front_top_ind)){
        case FRAME:
            crashed = 1;
            break;
        case BLOCK:
            if(env->front_blocks[front_top_ind] != CHI){
                crashed = 1;
                if(PHY_breakable(front_top_ind)){
                    BRD_break_block_ind(env, front_top_ind);
                    PHY_brk_debris(front_top_ind, curr->speed[X], curr->speed[Y]);
                }
            }
            break;
    }
    if(curr->speed[Y] > 0){
        PHY_calc_back_floor();
        switch(crashing(back_floor_ind)){
            case FRAME:
                crashed = 1;
                break;
            case BLOCK:
                if(env->front_blocks[back_floor_ind] != CHI){
                    crashed = 1;
                    if(PHY_breakable(back_floor_ind)){
                        BRD_break_block_ind(env, back_floor_ind);
                        PHY_brk_debris(back_floor_ind, curr->speed[X], curr->speed[Y]);
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
                    if(PHY_breakable(back_top_ind)){
                        BRD_break_block_ind(env, back_top_ind);
                        PHY_brk_debris(back_top_ind, curr->speed[X], curr->speed[Y]);
                    }
                }
                break;
        }
    }
    if(crashed) result = ACT_DELETION;
}

void PR_ub_loop(){
    PHY_calc_front(dir);
    PHY_calc_back(dir);
    PHY_calc_front_floor();
    switch(crashing(front_floor_ind)){
        case FRAME:
            result = ACT_DELETION;
            return;
        case BLOCK:
            if(env->front_blocks[front_floor_ind] != CHI){
                //Checking for chisels everywhere is pathetic.
                if(PHY_breakable(front_floor_ind)){
                    BRD_break_block_ind(env, front_floor_ind);
                    PHY_brk_debris(front_floor_ind, curr->speed[X], curr->speed[Y]);
                } else {
                    result = ACT_DELETION;
                    return;
                }
            }
            break;
    }
    calc_PR_top();
    u8 front_top_ind = calc_front_block_top();
    switch(crashing(front_top_ind)){
        case FRAME:
            result = ACT_DELETION;
            return;
        case BLOCK:
            if(env->front_blocks[front_top_ind] != CHI){
                if(PHY_breakable(front_top_ind)){
                    BRD_break_block_ind(env, front_top_ind);
                    PHY_brk_debris(front_top_ind, curr->speed[X], curr->speed[Y]);
                } else {
                    result = ACT_DELETION;
                    return;
                }
            }
            break;
    }
    if(curr->speed[Y] > 0){
        PHY_calc_back_floor();
        switch(crashing(back_floor_ind)){
            case FRAME:
                result = ACT_DELETION;
                return;
            case BLOCK:
                if(env->front_blocks[back_floor_ind] != CHI){
                    if(PHY_breakable(back_floor_ind)){
                        BRD_break_block_ind(env, back_floor_ind);
                        PHY_brk_debris(back_floor_ind, curr->speed[X], curr->speed[Y]);
                    } else {
                        result = ACT_DELETION;
                        return;
                    }
                }
                break;
        }
    }else{
        u8 back_top_ind = calc_back_block_top();
        switch(crashing(back_top_ind)){
            case FRAME:
                result = ACT_DELETION;
                return;
            case BLOCK:
                if(env->front_blocks[back_top_ind] != CHI){
                    if(PHY_breakable(back_top_ind)){
                        BRD_break_block_ind(env, back_top_ind);
                        PHY_brk_debris(back_top_ind, curr->speed[X], curr->speed[Y]);
                    } else {
                        result = ACT_DELETION;
                        return;
                    }
                }
                break;
        }
    }
}

void PR_packet_loop(){
    /*
    PHY_calc_center_block();
    if(center_ind == curr->actorData.packData.block){
        result = ACT_DELETION;
    }
    */
    if(!curr->timer--){
        result = ACT_DELETION;
    }
    
}

void PR_packet_land(){
    u8 block_ind = curr->actorData.packData.block;
    u16 good_block = (GOODIE | ( curr->actorData.packData.good << GOOD_TYP_SHFT));
    if(!env->front_blocks[block_ind]){
        env->front_blocks[block_ind] = good_block;
        BLK_drawBlock(IND_TO_X(block_ind), IND_TO_Y(block_ind), KNI);
    }else{
        env->back_blocks[block_ind] = good_block;
        BRD_create_block_ind(env, QUE, block_ind);
    }
}

#define PX_MARGIN 2

void PR_R_ball_loop(){
    PHY_despawn();

    switch(status & (ANIM_MSK | DIR_MSK)){ //dir is not used in this loop
        case PR_R_RIGHT:
            //Roll-off condition
            PHY_calc_front(0);
            PHY_calc_back(0);
            if(!PHY_crash_point(front, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               !PHY_crash_point(back, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(back - PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = PR_R_DOWN;
                   status = PR_R_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS(( (back & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = BALL_SPEED;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(front, PHY_mid_height() ) ){
                   newstatus = PR_R_UP;
                   status = PR_R_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ((front & ( BLOCK_TO_PX(0xFFFF) ) ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -BALL_SPEED;
                   return;
            }
            break;
        case PR_R_DOWN:
            //Roll-off condition
            PHY_calc_front(1);
            PHY_calc_top();
            if(!PHY_crash_point(front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               !PHY_crash_point(front - PX_MARGIN, top) && 
               PHY_crash_point(front - PX_MARGIN, top - PX_MARGIN)){
                   newstatus = PR_R_LEFT;
                   status = PR_R_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[Y] ));
                   curr->speed[X] = -BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front - PX_MARGIN, PHY_mid_height() ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) ) ){
                   newstatus = PR_R_RIGHT;
                   status = PR_R_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) );
                   curr->speed[X] = BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
        case PR_R_LEFT:
            //Roll-off condition
            PHY_calc_front(1);
            PHY_calc_back(1);
            PHY_calc_top();
            if(!PHY_crash_point( front , top - PX_MARGIN) && 
               !PHY_crash_point( back , top - PX_MARGIN) && 
               PHY_crash_point( back + PX_MARGIN ,  top - PX_MARGIN)){
                   newstatus = PR_R_UP;
                   status = PR_R_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS(( ((back & ( BLOCK_TO_PX(0xFFFF) ) ) + 16 ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -BALL_SPEED;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , top - PX_MARGIN) && 
               PHY_crash_point( front , PHY_mid_height() ) ){
                   newstatus = PR_R_DOWN;
                   status = PR_R_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( (((front & ( BLOCK_TO_PX(0xFFFF) ) ) + 16 ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = BALL_SPEED;
                   return;
            }
            break;
        case PR_R_UP:
            //Roll-off condition
            PHY_calc_front(0);
            PHY_calc_top();
            if(!PHY_crash_point( front + PX_MARGIN, top ) && 
               !PHY_crash_point( front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               PHY_crash_point( front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = PR_R_RIGHT;
                   status = PR_R_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( (POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) );
                   curr->speed[X] = BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front + PX_MARGIN, PHY_mid_height()  ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X])  , top ) ){
                   newstatus = PR_R_LEFT;
                   status = PR_R_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[Y] ));
                   curr->speed[X] = -BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
    }
}

void PR_L_ball_loop(){
    PHY_despawn();

    switch(status & (ANIM_MSK | DIR_MSK)){ //dir is not used in this loop
        case PR_L_LEFT:
            //Roll-off condition
            PHY_calc_front(1);
            PHY_calc_back(1);
            if(!PHY_crash_point(front, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               !PHY_crash_point(back, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(back + PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = PR_L_DOWN;
                   status = PR_L_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( (back & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) - curr->character->size[X] ) );
                   curr->speed[X] = 0;
                   curr->speed[Y] = BALL_SPEED;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) + PX_MARGIN) && 
               PHY_crash_point(front, PHY_mid_height() ) ){
                   newstatus = PR_L_UP;
                   status = PR_L_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( (front & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[X]) );
                   curr->speed[X] = 0;
                   curr->speed[Y] = -BALL_SPEED;
                   return;
            }
            break;
        case PR_L_DOWN:
            //Roll-off condition
            PHY_calc_front(0);
            PHY_calc_top();
            if(!PHY_crash_point(front + PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) &&
               !PHY_crash_point(front + PX_MARGIN, top) &&
               PHY_crash_point(front + PX_MARGIN, top - PX_MARGIN)){
                   newstatus = PR_L_RIGHT;
                   status = PR_L_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + curr->character->size[Y] ) );
                   curr->speed[X] = BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front + PX_MARGIN, PHY_mid_height() ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X]) , POS_TO_PX(curr->pos[Y]) ) ){
                   newstatus = PR_L_LEFT;
                   status = PR_L_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS( ( POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) );
                   curr->speed[X] = -BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
        case PR_L_RIGHT:
            //Roll-off condition
            PHY_calc_front(0);
            PHY_calc_back(0);
            PHY_calc_top();
            if(!PHY_crash_point( front , top - PX_MARGIN) && 
               !PHY_crash_point( back , top - PX_MARGIN) && 
               PHY_crash_point( back - PX_MARGIN ,  top - PX_MARGIN)){
                   newstatus = PR_L_UP;
                   status = PR_L_UP; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ( ( back & ( BLOCK_TO_PX(0xFFFF) ) ) ) + curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = -BALL_SPEED;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( POS_TO_PX(curr->pos[X]) , top - PX_MARGIN) && 
               PHY_crash_point( front , PHY_mid_height() ) ){
                   newstatus = PR_L_DOWN;
                   status = PR_L_DOWN; //animation change cancellation.
                   curr->pos[X] = PX_TO_POS( ( ((front & ( BLOCK_TO_PX(0xFFFF) ) ) ) - curr->character->size[X] ));
                   curr->speed[X] = 0;
                   curr->speed[Y] = BALL_SPEED;
                   return;
            }
            break;
        case PR_L_UP:
            //Roll-off condition
            PHY_calc_front(1);
            PHY_calc_top();
            if(!PHY_crash_point( front - PX_MARGIN, top ) && 
               !PHY_crash_point( front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) ) && 
               PHY_crash_point( front - PX_MARGIN, POS_TO_PX(curr->pos[Y]) + PX_MARGIN) ){
                   newstatus = PR_L_LEFT;
                   status = PR_L_LEFT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (POS_TO_PX(curr->pos[Y]) & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) ));
                   curr->speed[X] = -BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            
            //Climb condition
            if(PHY_crash_point( front - PX_MARGIN, PHY_mid_height()  ) && 
               PHY_crash_point( POS_TO_PX(curr->pos[X])  , top ) ){
                   newstatus = PR_L_RIGHT;
                   status = PR_L_RIGHT; //animation change cancellation.
                   curr->pos[Y] = PX_TO_POS(( ( (top & ( BLOCK_TO_PX(0xFFFF) ) ) + 16) + curr->character->size[Y] ));
                   curr->speed[X] = BALL_SPEED;
                   curr->speed[Y] = 0;
                   return;
            }
            break;
    }
}