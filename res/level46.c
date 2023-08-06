#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)


static const Actor blp = {
    &PL_blue,
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



static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(3)},
    {NASTIE_SPEED, 0},
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
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(11)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &beanie1,
};

static const Actor beanie3 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(11)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie2,
};

static const Actor robo0 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(13)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie3,
};


const Board level46 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GRO, GBO, GGO, GNO, GYO, RDK,
     BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, FRI, BOW, FGI, BOW, FBI, BOW, FRI, BOW, FRI, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, FNI, BOW, FYI, BOW, FNI, BOW, FGI, BOW, FBI, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW,   0, BOW, FRI, BOW, FYI, BOW, FNI, BOW, FYI, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW, FNI, BOW,   0,   0,   0,   0,
       0,   0,   0,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GRO, GNI, GYI, RDD,
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
    12000,
    &robo0,
    &glp
};