#include "SOI.h"

#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {
    &PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(9)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(9)},
   {   0,    0},
      0,
      0,
      &blp
   };



static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(1)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(1)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor robo0 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(3)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie1,
};

static const Actor robo1 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(3)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo0,
};


const Board level24 = {
    {
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0, TUR, BFW, GLS,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0, RDD,
       0,   0,   0, BFW, BFW, BFW, BFW, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW, BFW, BFW, BFW,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0, GLC, BOO,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0, BFW, BFW, BFW, BFW, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC, RDK,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, M2X,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY1,
    0,
    5000,
    &robo1,
    &glp
};