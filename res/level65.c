#include "SOI.h"

#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFG (NORMAL_BLOCK | SOLID | BLK_FLAT  | BREAKABLE | COL_SLOT2)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11)) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn0 = {
    &SPW_ostrich,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(2)},
    {0, 0},
    MAX_TIMER - 120,
    0,
    0,
    {.spwData =
        {
            720,
            0,
            0
        }
    }
};

static const Actor beanie0 = {
    &NST_beanie,
    WALK_DOWN,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(5)},
    {0, NASTIE_SPEED},
    0,
    0,
    &spawn0,
};

static const Actor wheel0 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(4)},
    {-FAST_SPEED, 0},
    0,
    0,
    &beanie0,
};


const Board level65 = {
    {
     GLS,   0,   0,   0,   0,   0, SLC,   0,   0, GLC,   0,   0, SLC,   0,   0,   0,   0,   0,   0,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, OST,   0,   0,   0,
       0,   0,   0,   0,   0,   0, NET, NET, NET, NET, NET, NET, NET,   0, BOW, BFW, BOW,   0,   0,
       0,   0,   0,   0,   0,   0, NET,   0, BOW, BFW, BOW,   0, NET,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, NET, BOW,   0,   0,   0, BOW, NET,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, NET, BFW,   0,   0,   0, BFG, NET,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, NET, BOW,   0,   0,   0, BOW, NET, BFW, BFW, BFW, BFW,   0,   0,
       0,   0,   0,   0,   0,   0, NET,   0, BOW, BFW, BOW,   0, NET,   0,   0,   0,   0,   0,   0,
       0, BDW,   0,   0,   0,   0, NET, NET, NET, NET, NET, NET, NET,   0,   0,   0,   0, BDW,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BFR, BFR, BFR, NET, NET, BFW, BFW, BFW,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BFR, BFR, BFR,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BFR, BFR, BFR,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, RDK, BFR, BFR, BFR, RDD,   0, BOW,   0,   0,   0,   0, THN,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2,
    0,
    7000,
    &wheel0,
    &glp
};