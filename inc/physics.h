#ifndef PHYSICS_H

#define PHYSICS_H

#include "actors.h"
#include "board.h"

#define FALLSPEED 2

void PHY_init(Board * board);
void PHY_computeStatus(Actor * actor);

#endif