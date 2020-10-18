#include "physics.h"

#include "board.h"
#include "blocks.h"
#include "gameplay.h"
#include "behavior.h"
#include "sound.h"

#include "globals.h"

u16 attr;
PlayerStat * pl_stat;
PlayerStat * bl_stat;
PlayerStat * gr_stat;

u8 collided;

//TODO: Organize. Make more understandable

u16 back_floor_ind;
u16 front_floor_ind;
u16 floor_ind;
u16 top_ind;
u16 front;
u16 back;
u16 top;
u16 center_ind;


#define B0 0
#define B1 1
#define G0 2
#define G1 3

u8 player_lines[4] = {255,255,255,255};

//TODO: Organize. Make more understandable
enum player_action{
    NOTHING,
    DEL_BLOCK,
    MK_BLOCK,
    SHOOT
};
enum player_action * pl_act;
enum player_action bl_act, gr_act;
u8 bl_ctrl;
u8 gr_ctrl;
u8 * ctrl;
u8 bl_after_status, gr_after_status;
u8 * after_status;
u8 bl_after_speed[2], gr_after_speed[2];
u8 * after_speed;

u8 result;

struct Actor fx = {0,
    0,
    0,
    {0, 0},
    {0, 0},
    0,
    0
};

u32 board_presence[8];

static inline void clean_presence(){
    memset(board_presence, 0x00000000, sizeof(board_presence));
}
static inline void set_presence(u8 ind){
    register u8 slot = (ind >> 5);
    register u8 shift = (ind & 0x1F);
    board_presence[slot] = (1 << shift);
}
static inline u8 is_occupied(u8 ind){
    register u8 slot = (ind >> 5);
    register u8 shift = (ind & 0x1F);
    return board_presence[slot] & (1 << shift);
}

//TODO: Organize. Make more understandable.
static inline void calc_front_block_hi(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 12 ) ) ) );
}

void calc_front_block(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 8 ) ) ) );
}

static inline void calc_front_block_lo(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 4 ) ) ) );
}

static inline void calc_next_floor(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) + 8 ) ) ) );
}

static inline void calc_front_floor(){
    front_floor_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) );
}

static inline void calc_back_floor(){
    back_floor_ind = XY_TO_IND( PX_TO_BLOCK( back ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_floor(){
    floor_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}

static inline void calc_top_block(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
static inline void calc_top_block_left(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[X] ) - curr->character->size[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
static inline void calc_top_block_right(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[X] ) + curr->character->size[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
static inline void calc_center_block(){
    center_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - (curr->character->size[Y] >> 1) ) ) ) ) ;
}


void calc_front(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - curr->character->size[X] : POS_TO_PX(curr->pos[X]) + curr->character->size[X];
}
static inline void calc_front_margin(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - curr->character->size[X] - COLL_MARGIN : POS_TO_PX(curr->pos[X]) + curr->character->size[X] + COLL_MARGIN;
}
static inline void calc_next(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - BLOCK_SIZE_PX : POS_TO_PX(curr->pos[X]) + BLOCK_SIZE_PX;
}
static inline void calc_back(u8 direction){
    back = direction ? POS_TO_PX(curr->pos[X]) + curr->character->size[X] : POS_TO_PX(curr->pos[X]) - curr->character->size[X];
}
static inline void calc_top(){
    top = POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1;
}

static inline u8 fall(u8 ind){
    return !( SOLID & env->front_blocks[ind] ) &&  ( POS_TO_PX(curr->pos[Y])  < BOARD_Y_PX );
}
static inline u8 land(u8 ind){
    return ( SOLID & env->front_blocks[ ind ] ) || (POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX);
}

static inline u8 cliff(){
    return (front_floor_ind < BOARD_BUFFER) && !( SOLID & env->front_blocks[front_floor_ind] );
}

static inline u8 crash_into(){
    if( front >= BOARD_X_PX )
        return FRAME;
    if(SOLID & env->front_blocks[front_ind])
        return BLOCK;
    if(GOODIE & env->front_blocks[front_ind])
        return GOODIE;
    else
        return 0;
}

static inline u8 breakable(u8 ind){
    return (BREAKABLE & env->front_blocks[ind]);
}

static inline u8 weap_ctrl(u8 after){
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

static inline u8 block_ctrl(u8 after){
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

static inline u8 jump_ctrl(u8 after){
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

void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.frames = 0;
    fx.character = &blk_debris0_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED_2X;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris1_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y - BRK_SPEED;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris2_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris3_ent;
    fx.speed[X] = sp_x;
    fx.speed[Y] = sp_y + BRK_SPEED_2X;
    ACT_add(&fx, &fx_buf);
}

static inline void jmp_brk_debris(u8 front_ind, u8 sp_x, u8 sp_y){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind));
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind));
    fx.frames = 0;
    fx.character = &blk_debris0_ent;
    fx.speed[X] = sp_x - BRK_SPEED_2X;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris1_ent;
    fx.speed[X] = sp_x - BRK_SPEED;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris2_ent;
    fx.speed[X] = sp_x + BRK_SPEED;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
    fx.character = &blk_debris3_ent;
    fx.speed[X] = sp_x + BRK_SPEED_2X;
    fx.speed[Y] = sp_y;
    ACT_add(&fx, &fx_buf);
}

static inline void goodie_debris(u8 front_ind){
    fx.status = 0;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 8;
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(front_ind)) + 8;
    fx.frames = 0;
    fx.character = goodies_vector[0];
    fx.speed[X] = 0;
    fx.speed[Y] = -BRK_SPEED;
    break_block_ind(env, front_ind);
    ACT_add(&fx, &fx_buf);
}

void summon_deletor(u8 front_ind, u8 deletes){
    fx.status = deletes ? 1 : 0;
    fx.character = &deletor_ent;
    fx.frames = DELETOR_FRAMES;
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(front_ind)) + 7;
    fx.pos[Y] = BLOCK_TO_PX( (IND_TO_Y(front_ind) + 1) );
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    ACT_add(&fx, &fx_buf);
}

static inline void summon_arrow(u8 dir, ActorList * list){
    fx.status = dir;
    fx.character = &arrow_ent;
    fx.frames = 0;
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.speed[X] = dir ? -2*WALKSPEED : 2*WALKSPEED;
    fx.speed[Y] = 0;
    ACT_add(&fx, list);
}

void kill(Actor * act, u8 speed_x, u8 speed_y){
    if(act->character->death_sound){
        XGM_setPCM(SFX_IND, act->character->death_sound, act->character->death_sound_size);
        XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
    }
    act->status = DEAD;
    act->pos[Y] -= COLL_CORR;
    act->speed[Y] = speed_y;
    act->speed[X] = speed_x;
}

static inline void nastie_tree(){
    calc_center_block();
    set_presence(center_ind);
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_back(dir);
            calc_back_floor();
            if(fall(back_floor_ind)){
                if(curr->character->onFall){
                    (*curr->character->onFall)();
                    return;
                }
            }
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                    NST_turn_around();
                    return;
                case BLOCK:
                    if(breakable(front_ind)) (*curr->character->onCrash)();
                    else NST_turn_around();
                    return;
                default:
                    break;
            }
            calc_front_floor();
            if(cliff()){
                if(curr->character->onTrip){
                    (*curr->character->onTrip)();
                    return;
                }
            }
            curr->speed[X] = dir ? -WALKSPEED : WALKSPEED;
        break;
        case RIGHT_TURN_LEFT:
            if(curr->frames--) return;
            newstatus = WALK_RIGHT | !dir;
            curr->speed[X] = dir ? WALKSPEED : -WALKSPEED;
            curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
        break;
        case ATTACK_RIGHT_IN: 
            if(curr->frames--) return;
            if(curr->character->onAttack){
                (*curr->character->onAttack)();
            }
            newstatus = dir | ATTACK_RIGHT_OUT;
            curr->frames = ATTK_FRAMES;
            curr->speed[X] = 0;
        break;
        case ATTACK_RIGHT_OUT: 
            if(curr->frames--) return;
            (*curr->character->onFinishAttack)();
        break;
        case FALL_RIGHT:
            calc_floor();
            if(land(floor_ind)) {
                curr->pos[Y] &= FLOOR_CORR;
                curr->speed[Y] = 0;
                (*curr->character->onLand)();
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
}

static inline void fx_tree(){
    switch(attr & FX_TYP_MSK){
        case WAS_GOODIE:
        case SHRAPNEL:
            if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
                result = ACT_DELETION;
            }
            curr->speed[Y] += GRAVITY;
        break;
        case DELETER:
            if(curr->frames--) return;
            result = ACT_DELETION;
        break;
    }
}

static inline void player_tree(){
    switch(status & ANIM_MSK){
        case WALK_RIGHT:
            calc_front_margin(dir);
            calc_front_block();
            switch(crash_into()){
                case FRAME:
                case BLOCK:
                curr->speed[X] = 0;
                curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
                    break;
                case GOODIE:
                    goodie_debris(front_ind);
                default:
                    curr->speed[X] = dir ? -PL_WALKSPEED : PL_WALKSPEED;
                    break;
            }
            calc_front(dir);
            calc_back(dir);
            calc_front_floor();
            calc_back_floor();
            if(fall(front_floor_ind) && fall(back_floor_ind)){
                newstatus = FALL_RIGHT | dir;
                curr->speed[Y] = FALLSPEED;
                curr->speed[X] = 0;
                return;
            }
            if(jump_ctrl(status)) return;
            if( *ctrl & CTRL_MOV ){
                if( ( *ctrl & CTRL_LEFT ) != dir ){
                    newstatus = RIGHT_TURN_LEFT | dir;
                    curr->frames = BP_TURN_FRAMES;
                    curr->speed[X] = 0;
                    return;
                }
            }
            else
            {
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
                    XGM_setPCM(SFX_IND, whoah, sizeof(whoah));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, FALSE);
                break;
                case DEL_BLOCK:
                    calc_next(dir);
                    calc_front_block();
                    break_block_ind(env, front_ind);
                    XGM_setPCM(SFX_IND, fim, sizeof(fim));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, TRUE);
                break;
                case SHOOT:
                    XGM_setPCM(SFX_IND, fim, sizeof(fim));
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
                    XGM_setPCM(SFX_IND, whoah, sizeof(whoah));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    summon_deletor(front_ind, FALSE);
                break;
                case DEL_BLOCK:
                    calc_next(dir);
                    calc_next_floor();
                    break_block_ind(env, front_ind);
                    XGM_setPCM(SFX_IND, fim, sizeof(fim));
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
            switch(crash_into()){
                case FRAME:
                case BLOCK:
                    break;
                case GOODIE:
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
                    curr->pos[X] += dir ? COLL_CORR : -COLL_CORR;
                    break;
                case GOODIE:
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
            if( *ctrl & CTRL_MOV){
                register u8 push = *ctrl & CTRL_LEFT;
                curr->speed[X] = push ? -PL_WALKSPEED : PL_WALKSPEED;
                calc_front_margin( push );
                calc_front_block_hi();
                switch(crash_into()){
                    case FRAME:
                    case BLOCK:
                        curr->pos[X] += push ? COLL_CORR : -COLL_CORR;
                        curr->speed[X] = 0;
                        break;
                    case GOODIE:
                    default:
                        break;
                }
                calc_front_block_lo();
                switch(crash_into()){
                    case FRAME:
                    case BLOCK:
                        curr->pos[X] += push ? COLL_CORR : -COLL_CORR;
                        curr->speed[X] = 0;
                        break;
                    case GOODIE:
                    default:
                        break;
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
                    XGM_setPCM(SFX_IND, smack, sizeof(smack));
                    XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                    //play snap sound
                    break_block_ind(env, top_ind);
                    jmp_brk_debris(top_ind, 0, -BRK_SPEED);
                }else{
                    XGM_setPCM(SFX_IND, metal2, sizeof(metal2));
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

static inline void proj_tree(){
    if( (status & ANIM_MSK) == DEAD){
        result = ACT_DELETION;
        return;
    }
    switch(attr & MOVT_BITMSK){
        case FLIES:
            calc_front(dir);
            calc_front_block();
            switch(crash_into()){
                case BLOCK:
                    if(breakable(front_ind)){
                        if(attr & BREAKS){
                            brk_debris(front_ind, BRK_SPEED, 0);
                            if(!(attr & GOES_THRU)){
                                result = ACT_DELETION;
                            }
                        }
                        result = ACT_DELETION;
                    }else{
                        result = ACT_DELETION;
                        return;
                    }
                break;
                case FRAME:
                    result = ACT_DELETION;
                    return;
                break;
            }
        break;
        case LURKS:

        break;
    }
}

static inline void big_entity_tree(){
    switch(attr & BIG_ENT_MSK){
        case BLUE_PLAYER:
            ctrl = &bl_ctrl;
            pl_act = &bl_act;
            pl_stat = bl_stat;
            after_status = &bl_after_status;
            after_speed = bl_after_speed;
            player_tree();
        break;
        case GREEN_PLAYER:
            ctrl = &gr_ctrl;
            pl_act = &gr_act;
            pl_stat = gr_stat;
            after_status = &gr_after_status;
            after_speed = gr_after_speed;
            player_tree();
        break;
        case KNIGHT:

        break;
        case GARGOYLE:

        break;
    }
}

static inline void class_tree(){
    switch(attr & ENT_CHECK_BITMSK){
        case NASTIE:
            nastie_tree();
            if(curr->status == DEAD)
                return;
            if(collided){
                if(blue_player && ACT_collision(blue_player, curr)){
                    kill(blue_player, 0, -2*FALLSPEED);
                    blue_player = NULL;
                }
                if(green_player && ACT_collision(green_player, curr)){
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
                            bl_stat->score += curr->character->points;
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
                            gr_stat->score += curr->character->points;
                        }
                        proj_act = proj_act->next;
                    }
                }
            }
        break;
        case BIG_ENTITY:
            big_entity_tree();
        break;
        case PROJECTILE:
            proj_tree();
        break;
        case FX:
            fx_tree();
        break;

    }
}


void PHY_HCallback(){
    if(GET_VDPSTATUS(VDP_SPRCOLLISION_FLAG)){
        collided = TRUE;    
    }
}

u8 PHY_init(Board * board, PlayerStat * bl_stats, PlayerStat * gr_stats){
    env = board;
    collided = FALSE;
    SYS_setHIntCallback(PHY_HCallback);
    VDP_setHIntCounter(0);
    VDP_setHInterrupt(1);
    bl_stat = bl_stats;
    gr_stat = gr_stats;
    if(!ACT_init(&nasties, MAX_NASTIES)) return FALSE;
    if(!ACT_init(&fx_buf, MAX_FX)) return FALSE;
    if(!ACT_init(&players, MAX_PLAYERS)) return FALSE;
    if(!ACT_init(&projectiles, MAX_PROJ)) return FALSE;
    if(!ACT_init(&bp_projectiles, MAX_PROJ)) return FALSE;
    if(!ACT_init(&gp_projectiles, MAX_PROJ)) return FALSE;
    return TRUE;
}

void PHY_end(){
    collided = FALSE;
    VDP_setHInterrupt(0);
    ACT_end(&nasties);
    ACT_end(&fx_buf);
    ACT_end(&players);
    ACT_end(&projectiles);
    ACT_end(&bp_projectiles);
    ACT_end(&gp_projectiles);
}

void PHY_send_inputs(u8 ctrl1, u8 ctrl2){
    bl_ctrl = ctrl1;
    gr_ctrl = ctrl2;
}

u8 PHY_computeStatus(Actor * actor){
    result = 0;
    curr = actor;
    status = curr->status;
    newstatus = status;
    attr = curr->character->attr;
    dir = (status & 0x0001);

    class_tree();
    
    curr->status = newstatus;
    if(status != newstatus) result = ACT_CHANGED;
    return result;
}


void PHY_update(){
    ACT_update(&players);
    ACT_update(&nasties);
    ACT_update(&projectiles);
    ACT_update(&bp_projectiles);
    ACT_update(&gp_projectiles);
    ACT_update(&fx_buf);
    if(collided) collided = FALSE;
}
