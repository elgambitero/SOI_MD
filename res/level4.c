#include "SOI.h"

#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(3)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(3)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spinner = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(4)},
   {0, 0},
      0,
   0,
   0,
   };



const Board level4 = {
    {
     SLC,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOG, BOG, BOG,   0,   0,   0, BOG, BOG, BOG,   0, BOG, BOG, BOG,   0,   0,   0, BOG, BOG, BOG,
     BOG,   0,   0,   0,   0, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG,   0,   0,   0,   0, BOG,
       0, BOG,   0,   0, BOG, BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG, BOG,   0,   0, BOG,   0,
     GLC, RDK,   0, BOG, BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG, BOG,   0, RDD, GLC,
     BOG, BOG, BOG, BOG, BOW, BOW, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOW, BOW, BOG, BOG, BOG, BOG,
     BOW, BOW, BOW, BOW, BOW, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOW, BOW, BOW, BOW, BOW,
     BOG, BOG, BOG, BOG, BOG, BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG, BOG, BOG, BOG, BOG, BOG,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
     BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GEM,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLD,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY1,
    0,
    6000,
    &spinner,
    &glp
};