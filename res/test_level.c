#include "SOI.h"

#define BDG (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT2)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BDB (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT3)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT3)
#define  OB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT   | COL_SLOT3)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define  FW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)
#define BFG (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT2)
#define BFB (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT3)
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
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

const Board test_level = {
    {
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
       0,   0,   0,   0,   0,   0,   0,   0, RDK, RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    {PAL_PI, PAL_YL, PAL_BK},
    MUS_HEAVY3,
    0,
    1500,
    0,
    &glp
};