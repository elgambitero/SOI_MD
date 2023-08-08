#include "SOI.h"

#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(6)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(6)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(4)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_DOWN,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(4)},
    {0, NASTIE_SPEED},
    0,
    0,
    &beanie0,
};

static const Actor beanie2 = {
    &NST_beanie,
    WALK_DOWN,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(4)},
    {0, NASTIE_SPEED},
    0,
    0,
    &beanie1,
};

static const Actor beanie3 = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(7)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie2,
};

static const Actor beanie4 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(10)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie3,
};

static const Actor beanie5 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(10)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie4,
};

static const Actor beanie6 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(10)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie5,
};

static const Actor beanie7 = {
    &NST_beanie,
    WALK_UP,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(10)},
    {0, -NASTIE_SPEED},
    0,
    0,
    &beanie6,
};


const Board level54 = {
    {
     SLC,   0,   0,   0,   0,   0,   0,   0, RDD, BOG, RDK,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG,   0,   0,
       0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GRO,   0,   0,
       0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,
     BOG, BOG, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG, BOG, BOG,
       0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,
       0,   0, GBO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,
       0,   0, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG, BOG,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOG,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     SLC,   0,   0,   0,   0,   0,   0,   0, FRI, BOG, FBI,   0,   0,   0,   0,   0,   0,   0, SLC,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, SLC,   0,   0, SLC,   0,   0, SLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, SLC,   0,   0, SLC,   0,   0, SLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY1,
    0,
    6000,
    &beanie7,
    &glp
};