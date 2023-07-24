#include "SOI.h"

#define BDB (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)

static const Actor blp = {
    &PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(5)},
    {   0,    0},
      0,
      0,
      0
    };

static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(5)},
    {   0,    0},
    0,
    0,
    &blp
};

static const Actor spawn = {
    &SPW_hammer,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 120,
    0,
    0,
    {.spwData =
        {
            600,
            ALTERNATE,
            0
        }
   }
};

static const Actor spinner0 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(2)},
    {0, 0},
    0,
    0,
    &spawn,
};


static const Actor spinner1 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(12) - 8, BLOCK_TO_PX(2)},
    {0, 0},
    0,
    0,
    &spinner,
};



const Board level3 = {
    {
     RDD,   0,   0,   0,   0,   0,   0,   0,   0, HMR,   0,   0,   0,   0,   0,   0,   0,   0, RDK,
       0,   0,   0,   0,   0,   0,   0,   0, BDB, BDB, BDB,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BDB,   0,   0,   0, BDB,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BDB,   0,   0,   0,   0,   0, BDB,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BDB,   0,   0,   0,   0,   0,   0,   0, BDB,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BDB,   0,   0,   0, BOB, BOB, BOB,   0,   0,   0, BDB,   0,   0,   0,   0,
       0,   0,   0, BDB,   0,   0,   0, BOB,   0,   0,   0, BOB,   0,   0,   0, BDB,   0,   0,   0,
       0,   0, BDB,   0,   0,   0, BOB,   0,   0,   0,   0,   0, BOB,   0,   0,   0, BDB,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BDB,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDB,
       0, BDB,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDB,   0,
       0,   0, BDB,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDB,   0,   0,
       0,   0,   0, BDB,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDB,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, THN,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0, SLC,   0,   0,   0,   0,
    },
    {PAL_BL, PAL_R, PAL_GR},
    MUS_HEAVY3, //music
    0,
    5000, //bonus
    &spinner1, //nasties
    &glp //players
};