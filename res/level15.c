#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {
    &PL_blue,
       0,
       0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(3)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(3)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor cannonR = {
    &SPW_cannon,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(8)},
    {0, 0},
    MAX_TIMER - CANNON_TIME,
     0,
     0,
};

static const Actor cannonL = {
    &SPW_cannon,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(2)},
     {0, 0},
       MAX_TIMER - (CANNON_TIME),
     0,
     &cannonR,
};


const Board level15 = {
    {
     RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     CNR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
     RDK,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOO,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, M5X,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2,
    0,
    4000,
    &cannonL,
    &glp
};