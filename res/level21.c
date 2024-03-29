#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define ROW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(9)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(9)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {&SPW_piggy,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(2)},
   {0, 0},
   MAX_TIMER - 100,
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



const Board level21 = {
    {
     GLC, GLC, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, SLC, SLC,
     PIG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,
     BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BOW,   0, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0,   0,   0,   0, SLC, M2X, SLC,   0,   0,   0,   0, BOW,   0,   0, RDD,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, ROW, ROW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, THN,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SLC,   0, M3X,   0,   0, GLC,   0,   0,   0,   0, SLC,   0,   0, GLC,   0,   0, SLC,   0,
       0,   0, GEM,   0,   0, SLC,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0, ARR,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    6000, //bonus
    &spawn, //nasties
    &glp //players
};