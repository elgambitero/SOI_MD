#include "SOI.h"

#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BPB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(8)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(8)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheell = {
    &NST_whslowL,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(8)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheelr = {
    &NST_whslowR,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(8)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &whell,
};



static const Actor robo = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(4)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &whelr,
};


const Board level12 = {
    {
     BOW, BDW,   0,   0,   0,   0,   0, GLC, BFW, BFW, BFW, GLC,   0,   0,   0,   0,   0, BDW, BOW,
     BDW, C3H,   0,   0,   0,   0,   0, BFW,   0, GLC,   0, BFW,   0,   0,   0,   0,   0, M2X, BDW,
       0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BFW,   0,   0,   0, RDK,   0,   0,   0, BFW,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BPB, BPB, BPB, BPB, BFW, BFW, BFW, BPB, BPB, BPB, BPB,   0,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,
       0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,
       0, BFW,   0,   0,   0, BFW,   0,   0,   0, RDD,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,
     BFW, SLC,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0, SLC, BFW,
       0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,
       0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,
     BDW,   0,   0, BFW, SLC, BFW,   0,   0,   0,   0,   0,   0,   0, BFW, SLC, BFW,   0,   0, BDW,
     BOW, BDW,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0, BDW, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BAL,
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
    MUS_HEAVY2,
    0,
    5000,
    &robo,
    &glp
};