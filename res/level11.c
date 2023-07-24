#include "SOI.h"

#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(2)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(2)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(12)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(12) - 8, BLOCK_TO_PX(12)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};


const Board level11 = {
    {
     BDW,   0,   0,   0,   0,   0,   0,   0, BDW,   0, BDW, TRO,   0,   0,   0,   0,   0,   0, BDW,
     BDW,   0,   0,   0, TBO,   0,   0,   0, BDW,   0, BDW,   0,   0,   0, TGO,   0,   0,   0, BDW,
     BDW, BDW, BDW, SLC, SLC, SLC, BDW, BDW, BDW,   0, BDW, BDW, BDW, SLC, SLC, SLC, BDW, BDW, BDW,
       0,   0, BDW,   0,   0,   0, BDW,   0,   0,   0,   0,   0, BDW,   0,   0,   0, BDW,   0,   0,
       0, BDW, SLC,   0, SLC,   0, SLC, BDW,   0,   0,   0, BDW, SLC,   0, SLC,   0, SLC, BDW,   0,
       0, BDW,   0,   0,   0,   0,   0, BDW,   0,   0,   0, BDW,   0,   0,   0,   0,   0, BDW,   0,
       0, BDW,   0, SLC, GLC, SLC,   0, BDW,   0,   0,   0, BDW,   0, SLC, GLC, SLC,   0, BDW,   0,
       0, BDW,   0,   0,   0,   0,   0, BDW,   0,   0,   0, BDW,   0,   0,   0,   0,   0, BDW,   0,
       0, BDW, TBI,   0, SLC,   0, TBI, BDW,   0,   0,   0, BDW, TGI,   0, SLC,   0, TGI, BDW,   0,
       0, BDW,   0,   0,   0,   0,   0, BDW,   0,   0,   0, BDW,   0,   0,   0,   0,   0, BDW,   0,
       0, BDW, NET, NET, NET, NET, NET, BDW,   0,   0,   0, BDW, NET, NET, NET, NET, NET, BDW,   0,
     BDW,   0,   0,   0,   0,   0,   0,   0, BDW,   0, BDW,   0,   0,   0,   0,   0,   0,   0, BDW,
       0,   0,   0,   0, RDK,   0,   0,   0, TRI, BDW,   0,   0,   0,   0, RDD,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,
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
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY1,
    0,
    6000,
    &beanie1,
    &glp
};