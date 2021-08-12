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
#define COLL_MARGIN (1 << (DECIMALS - 2))
#define FLOOR_CORR ( 0xFFFF << (DECIMALS + 4) )
#define WALKSPEED (1 << (DECIMALS - 1) )
#define FALLSPEED 2 * WALKSPEED
#define PL_WALKSPEED WALKSPEED
#define PL_FASTSPEED 2 * PL_WALKSPEED
#define CANBALL_SPEED  ( 4 << (DECIMALS - 1) )
#define PL_JMP_BOOST -( 3 << (DECIMALS))
#define GRAVITY (1 << (DECIMALS - 2))
#define BRK_SPEED (1 << (DECIMALS + 1))
#define BRK_SPEED_2X 2 * BRK_SPEED

#define TURN_FRAMES 32
#define ATTK_FRAMES 16
#define DELETOR_FRAMES 7


//Ugly hack. sizeof(animation)?
#define BP_ATTK_FRAMES 5
#define BP_STL_TURN_FRAMES 8
#define BP_TURN_FRAMES 4
#define BP_STL_FRAMES 4

#define BLOCK 6
#define FRAME 7

#define ACT_CHANGED 1
#define ACT_DELETION 2

#define NOTHING      0
#define DEL_BLOCK    1
#define MK_BLOCK     2
#define SHOOT        3

//Pointer to level board.
Board * env;

//Actor lists
ActorList nasties;
ActorList fx_buf;
ActorList players;
ActorList projectiles;
ActorList bp_projectiles;
ActorList gp_projectiles;

//Current actor being evaluated (kinda equivalent to self)
Actor * curr;

//Storage for status, direction and resulting status, for fast access.
u8 status;
u8 newstatus;
u8 dir;

//Player statistics, for goodie recollection.
PlayerStat * pl_stat;
PlayerStat * bl_stat;
PlayerStat * gr_stat;

//Actor boundary coordinates
u16 front;
u16 back;
u16 top;

//Neighbouring block indexes.
u16 front_ind;
u16 back_floor_ind;
u16 front_floor_ind;
u16 floor_ind;
u16 top_ind;
u16 center_ind;

//Index for calculating the index of the taken goodie (deprecated?)
u8 gd_index;

//Result of physics calculation.
u8 result;

struct Actor fx;

u8 PHY_init(Board * board, PlayerStat * bl_stats, PlayerStat * gr_stats);
u8 PHY_computeStatus(Actor * actor);
void PHY_send_inputs(u8 ctrl1, u8 ctrl2);
void PHY_update();
void PHY_end();

void kill(Actor * act, u8 speed_x, u8 speed_y);

//Time manipulation
void stop_time(u16 frames);

//Special effects
void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y);
void summon_deletor(u8 front_ind, u8 deletes);

//Actor boundary coordinate calculations.
__attribute__((always_inline)) static inline void calc_top(){
    top = POS_TO_PX(curr->pos[Y]) - BLOCK_SIZE_PX - 1; //THIS IS REALLY BAD.
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

//Neighbouring block index calculations
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

__attribute__((always_inline)) static inline u8 PHY_calc_index(u16 x, u16 y){
    return XY_TO_IND( PX_TO_BLOCK( x ), PX_TO_BLOCK( y ) );
}

//Environment colision calculation.
__attribute__((always_inline)) static inline u8 fall(u8 ind){
    return !( SOLID & env->front_blocks[ind] ) &&  ( POS_TO_PX(curr->pos[Y])  < BOARD_Y_PX );
}
__attribute__((always_inline)) static inline u8 land(u8 ind){
    return ( ( SOLID & env->front_blocks[ ind ] ) || (POS_TO_PX(curr->pos[Y]) >= BOARD_Y_PX ) );
}
__attribute__((always_inline)) static inline u8 cliff(){
    return (front_floor_ind < BOARD_BUFFER) && !( SOLID & env->front_blocks[front_floor_ind] );
}
//this is starting to get kind of terrible.
__attribute__((always_inline)) static inline u8 crash_into(){
    if( front >= BOARD_X_PX )
        return FRAME;
    if(SOLID & env->front_blocks[front_ind])
        return BLOCK;
    return 0;
}

__attribute__((always_inline)) static inline u8 PHY_crash_point(u16 x, u16 y){
    if( x >= BOARD_X_PX || y >= BOARD_Y_PX)
        return FRAME;
    if(SOLID & env->front_blocks[PHY_calc_index(x, y)])
        return BLOCK;
    return 0;
}


//Environment analysis checks.
__attribute__((always_inline)) static inline u8 breakable(u8 ind){
    return (BREAKABLE & env->front_blocks[ind]);
}

#endif