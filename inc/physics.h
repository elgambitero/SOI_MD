#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"

#define PX_TO_TILE(px) (px >> 3)
#define PX_TO_BLOCK(px) (px >> 4)
#define BLOCK_TO_PX(px) (px << 4)

#define FALLSPEED 4
#define WALKSPEED 2
#define GRAVITY 1
#define BRK_SPEED 8
#define BRK_SPEED_2X 2 * BRK_SPEED

#define TURN_FRAMES 32
#define ATTK_FRAMES 16

#define BLOCK 1
#define FRAME 2

#define ACT_CHANGED 1
#define ACT_DELETION 2

void PHY_init(Board * board);
u8 PHY_computeStatus(Actor * actor);

#endif