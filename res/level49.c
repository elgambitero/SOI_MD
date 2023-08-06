#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(5)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(5)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(3)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(5)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor beanie2 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(7)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie1,
};

static const Actor beanie3 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(9)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie2,
};

static const Actor beanie4 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(11)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie3,
};

static const Actor beanie5 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie4,
};


const Board level49 = {
    {
     RDK,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
       0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
     BOW,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0, RDD,   0,
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
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    6000,
    &beanie5,
    &glp
};