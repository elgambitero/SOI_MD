#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(2)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(2)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(0) - 8, BLOCK_TO_PX(5)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(8)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor beanie2 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(0) - 8, BLOCK_TO_PX(11)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie1,
};

static const Actor beanie3 = {
    &NST_beanie,
    WALK_DOWN,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(1)},
    {0, NASTIE_SPEED},
    0,
    0,
    &beanie2,
};

static const Actor beanie4 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(13)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie3,
};

static const Actor beanie5 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(13)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie4,
};

static const Actor beanie6 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(13)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie5,
};


const Board level23 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BFW, BFW, BFW, BFW, BFW, BFW, BOW,   0,   0, BFW,   0,   0,   0, BOW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0, BOW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
     BOW, BFW, BFW, BFW, BFW, BFW, BFW, BOW,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0, BFW,   0,   0,   0,   0,
       0,   0, BOW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOW,   0,   0,   0, BFW,   0,   0,   0,   0,
     RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0, RDK,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, C3H,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    4000,
    &beanie6,
    &glp
};