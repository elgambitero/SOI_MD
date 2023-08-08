#include "SOI.h"

#define BON (NORMAL_BLOCK | SOLID | BLK_DOT  | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn0 = {
    &SPW_teeth,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 250,
    0,
    NULL,
    {
        .spwData = {
            1000,
            ALTERNATE,
            0
        }
    }
};

static const Actor spawn1 = {
    &SPW_teeth,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 500,
    0,
    &spawn0,
    {
        .spwData = {
            1000,
            ALTERNATE,
            0
        }
    }
};

static const Actor spawn2 = {
    &SPW_teeth,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(12) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 750,
    0,
    &spawn1,
    {
        .spwData = {
            1000,
            ALTERNATE,
            0
        }
    }
};

static const Actor spawn3 = {
    &SPW_teeth,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 1000,
    0,
    &spawn2,
    {
        .spwData = {
            1000,
            ALTERNATE,
            0
        }
    }
};


const Board level64 = {
    {
       0,   0,   0, PIG,   0,   0,   0, PIG,   0, RDK,   0, PIG,   0,   0,   0, PIG,   0,   0, GLS,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BON,   0,   0,   0, BON,   0,   0,   0, BON,   0,   0,   0, BON,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BON, BON, BON,   0,   0,   0,   0,   0, BON, BON, BON,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,
       0,   0,   0, BON,   0,   0,   0, BON, BON, BON, BON, BON,   0,   0,   0, BON,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
     ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, THN,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
     M3X,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_PI, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    8000, //bonus
    &spawn3, //nasties
    &glp //players
};