#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"
#include "player.h"

#define SFX_IND 5 //magic number

#define MAX_NASTIES 20
#define MAX_FX 10
#define MAX_PROJ 8

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

Board * env;

ActorList nasties;
ActorList fx_buf;
ActorList players;
ActorList projectiles;
ActorList pl_projectiles;

Actor * curr;

u8 status;
u8 newstatus;
u8 dir;

u16 front_ind;

u8 PHY_init(Board * board, PlayerStat * bl_stats, PlayerStat * gr_stats);
u8 PHY_computeStatus(Actor * actor);
void PHY_send_inputs(u8 ctrl1, u8 ctrl2);
void PHY_update();

void summon_deletor(u8 front_ind, u8 deletes);
void kill(Actor * act, u8 speed_x, u8 speed_y);

void calc_front(u8 direction);
void calc_front_block();
void brk_debris(u8 front_ind, u8 sp_x, u8 sp_y);

#endif