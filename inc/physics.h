#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"

#define PX_TO_TILE(px) (px >> 3)
#define PX_TO_BLOCK(px) (px >> 4)

#define FALLSPEED 2
#define WALKSPEED 1

#define TURN_FRAMES 16

void PHY_init(Board * board);
void PHY_computeStatus(Actor * actor);

#endif