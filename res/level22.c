#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT3)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFG (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT2)
#define BFB (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT3)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(0) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheell = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(2)},
    {-SLO_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheelr = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(2)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheell,
};



static const Actor robo = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(19)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheelr,
};


const Board level22 = {
    {
       0,   0,   0,   0,   0, BOG,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,   0,   0,   0,
     RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,
     BOW,   0,   0,   0,   0, BFG,   0,   0,   0,   0,   0,   0,   0, BFG,   0,   0,   0,   0, BOW,
       0,   0,   0,   0,   0, BFG,   0,   0,   0,   0,   0,   0,   0, BFG,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BFG,   0,   0,   0, GLS,   0,   0,   0, BFG,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOG, BFG, BFG, BFG, BFG, BFG, BFG, BFG, BOG,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOR,   0, BFR, BFR, BFR, BOR,   0,   0,   0, RDK,   0,   0,   0, BOB, BFB, BFB, BFB,   0, BOB,
       0,   0,   0,   0,   0, BFR,   0,   0,   0,   0,   0,   0,   0, BFB,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BFR,   0,   0,   0,   0,   0,   0,   0, BFB,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BFR,   0,   0,   0,   0,   0,   0,   0, BFB,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOR,   0,   0,   0,   0,   0,   0,   0, BOB,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GEM,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2,
    0,
    3000,
    &robo,
    &glp
};