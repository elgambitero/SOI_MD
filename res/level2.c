#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFG (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_SLOT2)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };


const Board level2 = {
    {
       0,   0,   0,   0,   0,   0, BFG, BFG, SLC, BFG, BFG, BFG,   0, SLC, BFG, BFG, C3H,   0,   0,
       0,   0, BFG, BFG, BFG, BFG, GLC, BFG, BFG, BFG, BFG, BFG, BFG, BFG,   0,   0, BFG, BFG,   0,
       0, BFG, BFG, BFG, BFG, BFW, BFW, BFW, BFW, GLC, BFG, BFG, BFG, BFG, BFW, BFG, BFG, BFG,   0,
       0, GLC, BFG, BFG, SLC,   0, BFG, BFG, BFW, BFG, BFG,   0, BFW, BFW, BFG, BFG, BFG, BFG,   0,
       0, BFG, BFG, BFG, BFG, BFG, GLC,   0, BFW, BFW, RDK, BFW, BFW, BFW, BFG, GLC, BFG, BFG,   0,
       0, BFG, BFG, BFG, BFW, BFW, BFG,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFG, BFG,   0,   0,
       0, BFG, BFG, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFG,   0, BFG,   0,   0,   0,
       0,   0, BFG,   0, BFG, BFG,   0, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BFG,   0,   0,   0,   0, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW, RDD,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0, BFW,   0,   0,
       0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0, BFW, BFW,   0,   0, BFW,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW, BFW, BFW,   0,   0,
       0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2, //music
    0,
    6000, //bonus
    NULL, //nasties
    &glp //players
};