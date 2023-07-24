#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BOP (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {
    &PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(10)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(10)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor can0 = {
    &SPW_cannon,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    MAX_TIMER - CANNON_TIME,
     0,
     0,
};

static const Actor can1 = {
    &SPW_cannon,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(9)},
     {0, 0},
       MAX_TIMER - (CANNON_TIME),
     0,
     &can0,
};


const Board level17 = {
    {
       0,   0,   0,   0, RDK,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
       0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, SLC, C3H, GLC, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0, SLC,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, SLC, ARR, GLC, CNL,
       0,   0,   0,   0, SLC,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0, RDD,   0,   0,   0,   0, BOP, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOP,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_PI, PAL_GR, PAL_BL},
    MUS_HEAVY1,
    0,
    5000,
    &can1,
    &glp
};