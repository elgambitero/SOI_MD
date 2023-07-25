#include "SOI.h"

#define BFW (NORMAL_BLOCK | BREAKABLE| SOLID | BLK_FLAT  | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {8, 16},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {24, 16},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn0 = {
    &SPW_piggy,
    WALK_RIGHT,
    0,
    {296, 16},
    {0, 0},
    MAX_TIMER - 120,
    0,
     0,
    {.spwData =
        {
            600,
            0,
            0
        }
    }
};


static const Actor spawn1 = {
    &SPW_piggy,
    WALK_LEFT,
    0,
    {296, 16},
    {0, 0},
    MAX_TIMER - 120,
    0,
    &spawn0,
    {.spwData =
        {
            600,
            0,
            0
        }
    }
};


const Board level29 = {
    {
     PIG,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0, PIG,
     BFW, BFW, BFW, BFW, BFW,   0,   0, BFW, BFW, BFW, BFW, BFW,   0,   0, BFW, BFW, BFW, BFW, BFW,
     BFW,   0,   0,   0, BFW,   0,   0, BFW,   0, TUR,   0, BFW,   0,   0, BFW,   0,   0,   0, BFW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW, THN, BFW, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SHL,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,   0, BOO,
     BFW, BFW, BFW, BFW, BFW,   0,   0, BFW, BFW, BFW, BFW, BFW,   0,   0, BFW, BFW, BFW, BFW, BFW,
     BFW,   0,   0,   0, BFW,   0,   0, BFW,   0, RDD,   0, BFW,   0,   0, BFW,   0,   0,   0, BFW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0, SLC,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, M2X,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, UP1,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3, //music
    0,
    5000, //bonus
    &spawn1, //nasties
    &glp //players
};