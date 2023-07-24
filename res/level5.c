#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT | COL_WHITE)
#define BRW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(12)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(12)},
   {   0,    0},
      0,
      0,
      &blp
   };



const Board level5 = {
    {
     BOW, BOW, BOW, BOW, BOW, BOW, SLC,   0,   0, GLC,   0,   0, SLC, BOW, BOW, BOW, BOW, BOW, BOW,
     BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,
     BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW,
     BOW, BOW, BOW,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0, BOW, BOW, BOW,
     SLC,   0,   0,   0, BOW, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,   0,   0,   0, SLC,
       0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,
     GLC,   0,   0,   0, BOW,   0,   0,   0,   0, GEM,   0,   0,   0,   0, BRW,   0,   0,   0, GLC,
       0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,
     SLC,   0,   0,   0, BOW, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,   0,   0,   0, SLC,
     BOW, BOW, BOW,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0, BOW, BOW, BOW,
     BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW,
     BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,
     BOW, BOW, BOW, BOW, BOW, BOW, SLC,   0,   0, GLC,   0,   0, SLC, BOW, BOW, BOW, BOW, BOW, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, GLC,   0,   0, C3H,   0,   0, GLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,
       0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY2,
    0,
    6000,
    0,
    &glp
};