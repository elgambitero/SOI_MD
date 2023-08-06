#include "SOI.h"

#define BDK (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOK (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)


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
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {&SPW_piggy,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
   {0, 0},
   MAX_TIMER - SPAWN_TIME,
   0,
   0,
   {
     .spwData = 
      {
         600,
         ALTERNATE,
         0
      }
   }
   };

static const Actor spinner0 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(4)},
   {0, 0},
      0,
   0,
   &spawn,
   };

static const Actor spinner1 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(13)},
   {0, 0},
      0,
   0,
   &spinner0,
   };

static const Actor spinner2 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(8)},
   {0, 0},
      0,
   0,
   &spinner1,
};


const Board level44 = {
    {
     RDK, GYO,   0,   0,   0, QUE, BDK,   0,   0, PIG,   0,   0, BDK, FYI,   0,   0,   0,   0,   0,
     BOK,   0,   0,   0,   0,   0, BDK,   0, BDK, GRI, BDK,   0, BDK,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BDK,   0,   0, BDK,   0, BDK,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BOK, FBO, BDK,   0,   0, BDK,   0, BDK,   0,   0,   0,   0,   0, BDK,   0,   0,
       0,   0,   0, BOK,   0, BDK,   0, BFW, BDK,   0, BDK, GBI, BDK, BDK, BDK, BDK, BDK,   0,   0,
       0,   0,   0,   0,   0, BDK, BDK,   0, BDK, BOK, BDK,   0,   0,   0,   0,   0,   0,   0,   0,
     FRO, BOK,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BOK,   0,   0,   0,   0,   0, BDK, BDK,   0, BDK, NET,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BDK,   0, BDK, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BDK, RDD,   0, BDK,   0, BDK, BDK, BDK, BDK, BDK,   0,   0,   0,   0,
       0,   0,   0,   0, BDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BDK,   0,   0,   0,   0, BDK,   0, BDK,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BFW, BDK,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0, BOO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_BK, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    6000, //bonus
    &spinner2, //nasties
    &glp //players
};