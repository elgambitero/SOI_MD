#include "SOI.h"

#define BDB (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT2)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(1)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(1)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {
    &SPW_piggy,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    0,
};

static const Actor robo0 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(5)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &spawn,
};

static const Actor robo1 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(9)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo0,
};

static const Actor wheel0 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(6)},
    {-SLO_SPEED, 0},
    0,
    0,
    &robo1,
};

static const Actor wheel1 = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(6)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel0,
};

static const Actor wheel2 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(9)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel1,
};

static const Actor wheel3 = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(9)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel2,
};



const Board level26 = {
    {
     TRO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,
     BOW, BFW, BFW, BFW, BOW, SLC, BOW, BFW, BOW, RDK, BOW, BFW, BOW, GLC, BOW, BFW, BFW, BFW, BOW,
     TRI,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, TRI,
       0, BDR, BDR, BDR,   0,   0, BFW,   0,   0, BDW,   0,   0, BFW,   0,   0,   0,   0,   0, PIG,
       0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0, BDB, BDB,
       0,   0, BDR, BDR, BDR,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BFW,   0, BDW,   0, BDW,   0, BFW,   0,   0,   0, BDB, BDB,   0,
       0, BDR, BDR, BDR,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0, BDB, BDB,   0,   0,
       0,   0, BDR, BDR, BDR,   0, BFW,   0, BDW, BDW, BDW,   0, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0, BDB, BDB,   0,   0,   0,
       0, BDR, BDR, BDR,   0,   0, BFW,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BOW,   0,   0, TRI,   0,   0, BOW,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_BL, PAL_R, PAL_GR},
    MUS_HEAVY2,
    0,
    8000,
    &wheel3,
    &glp
};