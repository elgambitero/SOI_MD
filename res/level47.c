#include "SOI.h"

#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BOK (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT   | COL_SLOT2)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(1)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(1)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {&SPW_teeth,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(1)},
   {-NASTIE_SPEED, 0},
      0,
   0,
   0,
   {
     .spwData = 
      {
         600,
         SEEK_PLAYER,
         0
      }
   }
   };

static const Actor spinner0 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(2)},
   {0, 0},
      0,
   0,
   &spawn,
   };

static const Actor spinner1 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(11)},
   {0, 0},
      0,
   0,
   &spinner0,
   };

static const Actor spinner2 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(11)},
   {0, 0},
      0,
   0,
   &spinner1,
};

// FIXME: MISSING MOVING BLOCKS
const Board level47_broken = {
    {
       0,   0,   0, BOW,   0, BOW,   0, BOW, C3H,   0,   0,   0,   0,   0, RDK,   0, TEH,   0, GLS,
       0,   0,   0, BOW,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOR, BOR,   0,   0,
       0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW,   0, BOW, BFW, BOW,   0,   0,   0,   0, BOW,   0,   0, BOR, BOR,   0,   0, BOR, BOR,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0, GLC,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0, BOW, BOR, BOR,   0,   0, BOR, BOR,   0,   0,
     RDD,   0,   0, BOW,   0, BOW,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0, BOW, BOW, BOW, BOW,   0,   0, BOR, BOR,   0,   0, BOR, BOR,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0, BOR, BOR,   0,   0, BOR, BOR,   0,   0,
       0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, THN,
       0,   0, BOK, BOW,   0, BOW,   0, BOW,   0, BOR, BOR,   0,   0, BOR, BOR,   0,   0, BOR, BOR,
       0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, QUE,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BOO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, M3X,
    },
    {PAL_R, PAL_BK, PAL_BL},
    MUS_HEAVY1, //music
    0,
    6000, //bonus
    &spinner2, //nasties
    &glp //players
};