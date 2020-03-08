#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"

#define PX_TO_TILE(px) (px >> 3)
#define PX_TO_BLOCK(px) (px >> 4)

#define FALLSPEED 4
#define WALKSPEED 2

#define TURN_FRAMES 32

void PHY_init(Board * board);
u8 PHY_computeStatus(Actor * actor);

#endif