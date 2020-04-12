#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"

#define MAX_NASTIES 20
#define MAX_FX 50
#define MAX_PROJ 5

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

ActorList nasties;
ActorList fx_buf;
ActorList players;
ActorList projectiles;
ActorList bp_projectiles;
ActorList gp_projectiles;


u8 PHY_init(Board * board);
u8 PHY_computeStatus(Actor * actor);
void PHY_send_inputs(u8 ctrl1, u8 ctrl2);
void PHY_update();

#endif