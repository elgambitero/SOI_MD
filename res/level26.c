#include "SOI.h"

#define BFB (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_DOWN,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(0)},
    {0, NASTIE_SPEED},
    0,
    0,
    0,
};

static const Actor wheell0 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(9)},
    {-SLO_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor wheelr1 = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(9)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheell0,
};



const Board level26 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFB, BOW, BOW, BOW, BFB, BOW, BOW, BOW,   0,   0,   0, BOW, BOW, BOW, BFB, BOW, BOW, BOW, BFB,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW, RDK, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, RDD, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,
       0,   0,   0, BFB, BFB, BFB, BOW,   0,   0,   0,   0,   0, BOW, BFB, BFB, BFB,   0,   0,   0,
       0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, BFB,   0,   0,   0,   0,   0,   0,   0, BFB, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,
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
    {PAL_BL, PAL_R, PAL_GR},
    MUS_HEAVY3,
    0,
    6000,
    &wheelr1,
    &glp
};