#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(2)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(2)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {
    &SPW_ostrich,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - 250,
    0,
    0,
    {.spwData =
        {
            400,
            0,
            0
        }
    }
};

const Board level39 = {
    {
     OST,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0, TRO,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, GRI, BOW, GBO, BOW, GGO, BOW, GNO, BOW, GYO, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, GRI, BOW, GBO, BOW, GGO, BOW, GNO, BOW, GYO, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, FBI, BOW, FGI, BOW, FNI, BOW, FYI, BOW, RDK, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, FRI, BOW, FBI, BOW, FGI, BOW, FNI, BOW, FYI, BOW,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, TRI,
    },

    {
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
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3, //music
    0,
    6000, //bonus
    &spawn, //nasties
    &glp //players
};