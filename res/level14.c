#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BPB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(9)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(9)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(6)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheell0 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(11)},
    {-FAST_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor wheelr1 = {
    &NST_whfastR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(11)},
    {FAST_SPEED, 0},
    0,
    0,
    &whell0,
};


static const Actor wheell2 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(3)},
    {-FAST_SPEED, 0},
    0,
    0,
    &wheelr1,
};

static const Actor wheelr3 = {
    &NST_whfastR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(12)},
    {FAST_SPEED, 0},
    0,
    0,
    &wheell2,
};


static const Actor spinner = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(8)},
    {0, 0},
    0,
    0,
    &wheelr3,
};


const Board level14 = {
    {
     BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,
     BFW, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR, BFW,
     BFW,   0, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0, BFW,
     BFW,   0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0, BFW,
     BFW,   0,   0, BFW, QUE,   0,   0,   0,   0, GLC,   0,   0,   0,   0, QUE, BFW,   0,   0, BFW,
     BFW,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0, BFW,
     BFW,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0, BFW,
     BFW,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0, BFW,
     BFW,   0,   0, BFW, RDD,   0,   0,   0,   0, BPB,   0,   0,   0,   0, RDK, BFW,   0,   0, BFW,
     BFW,   0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0, BFW,
     BFW,   0, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0, BFW,
     BFW, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR, BFW,
     BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SHL,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY1,
    0,
    3000,
    &spinner,
    &glp
};