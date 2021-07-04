#ifndef PHYSICS_H

#define PHYSICS_H

#define SFX_IND 5 //magic number

#define MAX_NASTIES 20
#define MAX_FX 10
#define MAX_PROJ 4

#define PX_TO_TILE(px) (px >> 3)
#define PX_TO_BLOCK(px) (px >> 4)
#define BLOCK_TO_PX(px) (px << 4)
#define BLOCK_SIZE_PX 16
#define BLOCK_SIZE_POS PX_TO_POS(BLOCK_SIZE_PX)

#define COLL_CORR (2 * DECIMALS)
#define COLL_MARGIN 1
#define FLOOR_CORR ( 0xFFFF << (DECIMALS + 4) )
#define FALLSPEED 4
#define WALKSPEED 3
#define PL_WALKSPEED WALKSPEED
#define PL_FASTSPEED 2 * PL_WALKSPEED
#define PL_JMP_BOOST -12
#define GRAVITY 1
#define BRK_SPEED 8
#define BRK_SPEED_2X 2 * BRK_SPEED

#define TURN_FRAMES 32
#define ATTK_FRAMES 16
#define DELETOR_FRAMES 7


//Ugly hack. sizeof(animation)?
#define BP_ATTK_FRAMES 5
#define BP_STL_TURN_FRAMES 8
#define BP_TURN_FRAMES 4
#define BP_STL_FRAMES 4

#define BLOCK 1
#define FRAME 2

#define ACT_CHANGED 1
#define ACT_DELETION 2

#define NOTHING      0
#define DEL_BLOCK    1
#define MK_BLOCK     2
#define SHOOT        3

Board * env;

ActorList nasties;
ActorList fx_buf;
ActorList players;
ActorList projectiles;
ActorList bp_projectiles;
ActorList gp_projectiles;

Actor * curr;
u8 collided;

u8 status;
u8 newstatus;
u8 dir;
u8 nastie_speed;


u8 * pl_act;
u8 bl_act, gr_act;

PlayerStat * pl_stat;
PlayerStat * bl_stat;
PlayerStat * gr_stat;

u8 * ctrl;
u8 bl_after_status, gr_after_status;
u8 * after_status;
u8 bl_after_speed[2], gr_after_speed[2];
u8 * after_speed;



u16 front_ind;
u16 back_floor_ind;
u16 front_floor_ind;
u16 floor_ind;
u16 top_ind;
u16 front;
u16 back;
u16 top;
u16 center_ind;

u8 gd_index;

u8 result;

struct Actor fx;

u8 PHY_init(Board * board, PlayerStat * bl_stats, PlayerStat * gr_stats);
u8 PHY_computeStatus(Actor * actor);
void PHY_send_inputs(u8 ctrl1, u8 ctrl2);
void PHY_update();
void PHY_end();

void summon_deletor(u8 front_ind, u8 deletes);
void kill(Actor * act, u8 speed_x, u8 speed_y);

//Boundary coordinate calculations.
__attribute__((always_inline)) static inline void calc_top(){
    top = POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1;
}
__attribute__((always_inline)) static inline void calc_front(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - curr->character->size[X] : POS_TO_PX(curr->pos[X]) + curr->character->size[X];
}
__attribute__((always_inline)) static inline void calc_front_margin(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - curr->character->size[X] - COLL_MARGIN : POS_TO_PX(curr->pos[X]) + curr->character->size[X] + COLL_MARGIN;
}
__attribute__((always_inline)) static inline void calc_next(u8 direction){
    front = direction ? POS_TO_PX(curr->pos[X]) - BLOCK_SIZE_PX : POS_TO_PX(curr->pos[X]) + BLOCK_SIZE_PX;
}
__attribute__((always_inline)) static inline void calc_back(u8 direction){
    back = direction ? POS_TO_PX(curr->pos[X]) + curr->character->size[X] : POS_TO_PX(curr->pos[X]) - curr->character->size[X];
}

//Block index calculations
__attribute__((always_inline)) static inline void calc_front_block_hi(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 12 ) ) ) );
}
__attribute__((always_inline)) static inline void calc_front_block(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 8 ) ) ) );
}
__attribute__((always_inline)) static inline void calc_front_block_lo(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) - 4 ) ) ) );
}
__attribute__((always_inline)) static inline void calc_next_floor(){
    front_ind = XY_TO_IND( PX_TO_BLOCK( front ), ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[Y] ) + 8 ) ) ) );
}
__attribute__((always_inline)) static inline void calc_front_floor(){
    front_floor_ind = XY_TO_IND( PX_TO_BLOCK( front ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y]) ) ) );
}
__attribute__((always_inline)) static inline void calc_back_floor(){
    back_floor_ind = XY_TO_IND( PX_TO_BLOCK( back ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}
__attribute__((always_inline)) static inline void calc_floor(){
    floor_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( POS_TO_PX(curr->pos[Y])  ) ) ) ;
}
__attribute__((always_inline)) static inline void calc_top_block(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
__attribute__((always_inline)) static inline void calc_top_block_left(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[X] ) - curr->character->size[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
__attribute__((always_inline)) static inline void calc_top_block_right(){
    top_ind =  XY_TO_IND( ( PX_TO_BLOCK( ( POS_TO_PX( curr->pos[X] ) + curr->character->size[X] ) ) ), (  PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1 ) )  ) ) ;
}
__attribute__((always_inline)) static inline void calc_center_block(){
    center_ind = XY_TO_IND( PX_TO_BLOCK( POS_TO_PX( curr->pos[X] ) ), (PX_TO_BLOCK( ( POS_TO_PX(curr->pos[Y]) - (curr->character->size[Y] >> 1) ) ) ) ) ;
}

//Environment colision calculation.

__attribute__((always_inline)) static inline u8 fall(u8 ind){
    return !( SOLID & env->front_blocks[ind] ) &&  ( POS_TO_PX(curr->pos[Y])  < BOARD_Y_PX );
}
__attribute__((always_inline)) static inline u8 land(u8 ind){
    return ( SOLID & env->front_blocks[ ind ] ) || (POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX);
}
__attribute__((always_inline)) static inline u8 cliff(){
    return (front_floor_ind < BOARD_BUFFER) && !( SOLID & env->front_blocks[front_floor_ind] );
}
__attribute__((always_inline)) static inline u8 crash_into(){
    if( front >= BOARD_X_PX )
        return FRAME;
    if(SOLID & env->front_blocks[front_ind])
        return BLOCK;
    if((GOODIE & env->front_blocks[front_ind]) == GOODIE)
        return GOODIE;
    else
        return 0;
}

//Environment analysis checks.
__attribute__((always_inline)) static inline u8 breakable(u8 ind){
    return (BREAKABLE & env->front_blocks[ind]);
}

void stop_time(u16 frames);

u8 breakable(u8 ind);

void clean_presence();
void set_presence(u8 ind);
u8 is_occupied(u8 ind);

void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y);

#endif