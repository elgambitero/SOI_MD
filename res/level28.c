#include "SOI.h"

#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BFB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_SLOT1)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(4)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(3)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spinner0 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   0,
   };

static const Actor spinner1 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner0,
   };

static const Actor spinner2 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner1,
};

static const Actor spinner3 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner2,
};

const Board level28 = {
    {
     TRO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, BOB, NET, BOB,   0,   0,   0,   0,   0,   0,   0, BOB, SLC, BOB,   0,   0,   0,
       0,   0, BOB,   0,   0, TRI, BOB,   0,   0,   0,   0,   0, BOB, TRI, NET, NET, BOB,   0, RDD,
       0, BOB,   0,   0,   0,   0,   0, BOB,   0,   0,   0, BOB, NET, NET, NET, NET, NET, BOB,   0,
     BOB,   0,   0, BOB,   0, BOB,   0,   0, BOB, RDK, BOB, NET, NET,   0, NET, NET,   0, NET, BOB,
     GLC,   0,   0,   0,   0,   0,   0,   0, GLC, BOB, NET, NET, NET, NET,   0, NET, NET, NET, QUE,
       0,   0, SLC, BFB,   0, BFB, SLC,   0,   0, BOB,   0, NET,   0, NET, NET, NET, NET,   0, NET,
       0,   0, SLC, SLC, BFB, SLC, SLC,   0,   0, BOB, NET, NET, NET, NET,   0, NET, NET, NET, NET,
       0,   0,   0,   0, BOB,   0,   0,   0,   0, BOB,   0, NET, NET, NET, NET, NET,   0, NET, NET,
       0,   0,   0,   0, BOB,   0,   0,   0,   0, BOB, NET, NET, NET, NET, NET, NET, NET, NET,   0,
     BFB,   0,   0,   0, BOB,   0,   0,   0, BFB, BOB, NET, NET,   0, NET, NET, NET, NET,   0, NET,
       0,   0, BOB,   0, BOB,   0, BOB,   0,   0, BOB,   0, NET, NET, NET, NET,   0, NET, NET, NET,
       0,   0,   0,   0, QUE,   0,   0,   0,   0, BOB, NET, NET,   0, NET, NET, NET, NET, NET,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, M3X,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_BL, PAL_GR, PAL_R},
    MUS_HEAVY2, //music
    0,
    6000, //bonus
    &spinner3, //nasties
    &glp //players
};