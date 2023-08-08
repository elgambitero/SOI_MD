#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT  | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };



static const Actor can0 = {
    &SPW_cannon,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
    {0, 0},
    MAX_TIMER - CANNON_TIME,
    0,
    0,
    {
      .spwData = {
         2625,
         0,
         0,
      }
    }
};

const Board level57 = {
    {
     BOW, BOW, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, GLC,
     BOW, BOW, NET, BOW, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     BOW, BOW, NET, BOW, BOW, NET, BOW, NET, BOW, BOW, NET, BOW, BOW, NET, BOW, NET, BOW,   0, NET,
     BOW, BOW, NET, BOW, NET, NET, NET, SLC, NET, SLC, NET, NET, SLC, NET, NET, SLC, NET, NET, BOW,
     BOW, BOW, NET, BOW, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, BOW, NET,
     BOW, BOW, NET, BOW, NET,   0, BOW, NET, BOW, NET, BOW, BOW, NET, BOW, BOW, NET, BOW, NET, NET,
     BOW, BOW, NET, BOW, BOW, NET, NET, NET, NET, NET, SLC, NET, NET, NET, NET, NET, NET, NET, NET,
     BOW, BOW, NET, BOW, NET, BOW, NET, BOW, BOW, NET, NET, NET, BOW, BOW, BOW, NET, NET, NET, NET,
     BOW, BOW, NET, BOW, NET, NET, BOW, NET, SLC, BOW, NET, BOW, NET, SLC,   0, NET, BOW,   0, NET,
     RDK, BOW, NET, BOW, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, BOW,
       0, NET, NET, BOW, NET, NET, NET, BOW, NET, NET, NET, NET, BOW, NET, BOW, NET, NET, BOW, GLC,
       0, BOW, NET, BOW, NET, NET, BOW, NET, NET, BOW, NET, BOW, NET, NET, NET, NET, BOW, NET, NET,
     RDD, BOW,   0, NET, NET,   0, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, CNL,
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
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    8000, //bonus
    &can0, //nasties
    &glp //players
};