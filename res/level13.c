#include "SOI.h"

#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BPB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(2)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(2)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor robo0 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(10)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};



static const Actor robo1 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(10)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo0,
};

// FIXME: Missing Moving blocks
const Board level13_broken = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,
     SLC, SLC, GLC, GLC, ARR, BFW, SLC,   0,   0,   0,   0,   0, RDK, BFW, BAL, GLC, GLC, SLC, SLC,
     SLC, SLC, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW, SLC, SLC,
       0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0,
       0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0,
       0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0, BFW,   0,
     BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,
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
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    6000,
    &robo1,
    &glp
};