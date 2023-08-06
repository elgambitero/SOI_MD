#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)

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

static const Actor beanie0 = {&NST_robo,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(4)},
   {NASTIE_SPEED, 0},
      0,
   0,
   0,
   };

static const Actor beanie1 = {&NST_robo,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(4)},
   {NASTIE_SPEED, 0},
      0,
   0,
   &beanie0,
   };

static const Actor beanie2 = {&NST_robo,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(4)},
   {NASTIE_SPEED, 0},
      0,
   0,
   &beanie1,
   };

static const Actor can0 = {&SPW_cannon,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(5)},
   {0, 0},
   MAX_TIMER - CANNON_TIME,
   0,
   &beanie2,
   };

static const Actor can1 = {&SPW_cannon,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(8)},
   {0, 0},
      MAX_TIMER - CANNON_TIME,
   0,
   &can0,
   };

static const Actor can2 = {&SPW_cannon,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(11)},
   {0, 0},
      MAX_TIMER - CANNON_TIME,
   0,
   &can1,
   };

const Board level48 = {
    {
     TYI,   0,   0,   0, TRI,   0,   0,   0, TNI, BOW, TYO, BOW, TNO, BOW, TRO, BOW, TBO, BOW, TGO,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, FYI, BOW, FNI, BOW, FRI, BOW, FBI, BOW, FGI,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0, BOW,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     TBI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     CNR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, TGI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GYO, GLC, GNO, GLC, GRO, GLC, GBO, GLC, GGO, RDK,
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
    MUS_HEAVY2, //music
    0,
    10000, //bonus
    &can2, //nasties
    &glp //players
};