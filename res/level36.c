#include "SOI.h"

#define BDB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DONUT | COL_SLOT3)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT3)

#define BDG (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DONUT | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)

#define BDR (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DONUT | COL_SLOT2)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)

#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheel0 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(1)},
    {-SLO_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheel1 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(3)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel0,
};

static const Actor wheel2 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(5)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel1,
};

static const Actor robo = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(1)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel2,
};


const Board level36 = {
    {
     QUE,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0, QUE,
       0,   0, BOB, BFW, BFW, BFW, BFW, BFW, BFW, BDB, BFW, BFW, BFW, BFW, BFW, BFW, BOB,   0,   0,
       0,   0, BFW, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, BFW,   0,   0,
       0,   0, BFW,   0, BOR, BFW, BFW, BFW, BFW, BDR, BFW, BFW, BFW, BFW, BOR,   0, BFW,   0,   0,
       0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,
       0,   0, BFW,   0, BFW,   0, BOG, BFW, BFW, BDG, BFW, BFW, BOG,   0, BFW,   0, BFW,   0,   0,
       0,   0, BDB,   0, BDR,   0, BDG,   0,   0,   0,   0,   0, BDG,   0, BDR,   0, BDB,   0,   0,
       0,   0, BFW,   0, BFW,   0, BOG, BFW, BFW, BDG, BFW, BFW, BOG,   0, BFW,   0, BFW,   0,   0,
       0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,
       0,   0, BFW,   0, BOR, BFW, BFW, BFW, BFW, BDR, BFW, BFW, BFW, BFW, BOR,   0, BFW,   0,   0,
       0,   0, BFW, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, BFW,   0,   0,
       0,   0, BOB, BFW, BFW, BFW, BFW, BFW, BFW, BDB, BFW, BFW, BFW, BFW, BFW, BFW, BOB,   0,   0,
     QUE,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0, QUE,
    },

    {
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOO,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, C9H,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, UP1,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BAL,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    4000,
    &robo,
    &glp
};