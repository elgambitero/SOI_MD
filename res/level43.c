#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOK (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(12)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(11)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor cannonR = {&SPW_cannon,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(7)},
   {0, 0},
      MAX_TIMER - CANNON_TIME,
   0,
   0,
   };

static const Actor cannonL = {&SPW_cannon,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(7)},
   {0, 0},
      MAX_TIMER - (CANNON_TIME/2),
   0,
   &cannonR,
   };


static const Actor bean = {&NST_beanie,
   WALK_DOWN,
   0,
   {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(7)},
   {0, NASTIE_SPEED},
      0,
   0,
   &cannonL,
   };

static const Actor bean1 = {&NST_beanie,
   WALK_DOWN,
   0,
   {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(7)},
   {0, NASTIE_SPEED},
      0,
   0,
   &bean,
   };

const Board level43 = {
    {
     BOK, TGO,   0,   0,   0, TUR, BOK, GLC,   0, TYO,   0, GLC, BOK, GLS,   0,   0,   0, TBO, BOK,
       0, BOK,   0,   0,   0,   0,   0, BOK,   0,   0,   0, BOK,   0,   0,   0,   0,   0, BOK,   0,
       0,   0, BOK,   0,   0,   0,   0,   0, BOK, RDD, BOK,   0,   0,   0,   0,   0, BOK,   0,   0,
       0,   0,   0, BOK,   0,   0,   0,   0, BOK, UP1, BOK,   0,   0,   0,   0, BOK,   0,   0,   0,
       0,   0,   0,   0, BOK,   0,   0,   0, BOK,   0, BOK,   0,   0,   0, BOK,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOK,   0, BOK,   0,   0,   0, BOK,   0, BOK,   0,   0,   0,   0,   0,
     CNR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
       0,   0,   0,   0,   0, BOK, SLC, BOK,   0,   0,   0, BOK, SLC, BOK,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOK,   0,   0,   0, BOK, BOK, BOK,   0,   0,   0, BOK,   0,   0,   0,   0,
       0,   0,   0, BOK,   0,   0,   0,   0, BOK,   0, BOK,   0,   0,   0,   0, BOK,   0,   0,   0,
       0,   0, BOK,   0,   0,   0,   0,   0, BOK, TNO, BOK,   0,   0,   0,   0,   0, BOK,   0,   0,
     TRO, BOK, TNI,   0,   0,   0, TBI, BOK,   0, RDK,   0, BOK, TRI,   0,   0,   0,   0, BOK,   0,
     BOK,   0,   0,   0,   0,   0, BOK,   0,   0, TYI,   0,   0, BOK,   0,   0,   0,   0, TGI, BOK,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     M3X,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, M3X,
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
    {PAL_BK, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    5000, //bonus
    &bean1, //nasties
    &glp //players
};