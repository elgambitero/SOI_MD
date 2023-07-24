#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {
    &PL_blue,
       0,
       0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(12)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(12)},
   {   0,    0},
      0,
      0,
      &blp
   };



static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(10)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor robo0 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(8)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};



static const Actor robo1 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(8)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo0,
};


const Board level14 = {
    {
     BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW,
     BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW, GLS,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW, RDK,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0, RDD, BOW,
     BOG, BOW, BOW, BOW, BOG,   0,   0, BOG, BOW, BOG, BOW, BOG,   0,   0, BOG, BOW, BOW, BOW, BOG,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
     BOG, BOW, BOW, BOW, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG, BOW, BOW, BOW, BOG,
     BFW, BFW, BFW, BFW, BOG, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOG, BFW, BFW, BFW, BFW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, C6H,   0,
       0,   0,   0,   0,   0, C6H,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0, SLC,   0,   0,   0,   0, ARR,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    5000,
    &robo1,
    &glp
};