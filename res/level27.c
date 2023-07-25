#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(12)},
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

static const Actor spawn = {&SPW_ostrich,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(3)},
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

static const Actor spawn1 = {&SPW_ant,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(3)},
   {0, 0},
      MAX_TIMER - 250,
   0,
   &spawn,
   {.spwData =
      {
         400,
         0,
         0
      }
   }
   };

const Board level27 = {
    {
     BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,
     BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0, FRO, BFW,
     BFW,   0,   0,   0,   0,   0,   0, ANT, BFW,   0, BFW,   0,   0,   0,   0,   0,   0, OST, BFW,
     BFW,   0,   0,   0, BFW, BFW, BFW, BFW, BFW,   0, BFW,   0,   0,   0, BFW, BFW, BFW, BFW, BFW,
     BFW,   0,   0,   0,   0,   0,   0,   0, BFW, RDK, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,
     BFW,   0,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,
     BFW, BFW, BFW, BFW, BFW,   0,   0,   0, BFW,   0, BFW, BFW, BFW, BFW, BFW,   0,   0,   0, BFW,
     BFW,   0,   0,   0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,
     BFW,   0,   0,   0,   0,   0,   0,   0, BFW, RDD, BFW,   0,   0,   0,   0,   0,   0,   0, BFW,
     BFW,   0,   0, BFW, BFW, BFW, BFW, BFW, BFW, FBO, BFW,   0,   0,   0, BFW, BFW, BFW, BFW, BFW,
     BFW,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0, BFW,
     BFW,   0,   0,   0,   0, THN, GRO,   0,   0,   0,   0,   0, GBO, THN,   0,   0,   0,   0, BFW,
     BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0, TUR,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, M2X,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    3000, //bonus
    &spawn1, //nasties
    &glp //players
};