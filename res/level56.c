#include "SOI.h"

#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor walker0 = {
    &NST_walker,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(7)},
    {-WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    0
};

static const Actor spawn0 = {
    &NST_walker,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 1,
    0,
    &walker0,
    {
        .spwData = {
            1200,
            0,
            0
        }
    }
};

static const Actor spawn1 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 1,
    0,
    &spawn0,
    {
        .spwData = {
            1200,
            0,
            0
        }
    }
};


const Board level56 = {
    {
     THN,   0,   0,   0, RDK, TEH,   0,   0,   0, BFW,   0,   0,   0, TEH, RDD,   0,   0,   0,   0,
     BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW,
     GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,
       0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, C3H,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0, ARR, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BAL, BAL,   0, UP1,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, M2X,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3, //music
    0,
    8000, //bonus
    &spawn1, //nasties
    &glp //players
};