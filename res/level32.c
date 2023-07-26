#include "SOI.h"

#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT  | COL_WHITE)

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

static const Actor walker0 = {
    &NST_walker,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(1)},
    {-WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    0
};

static const Actor walker1 = {
    &NST_walker,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(3)},
    {-WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker0
};

static const Actor walker2 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(5)},
    {WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker1
};

static const Actor walker3 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(7)},
    {WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker2
};

static const Actor walker4 = {
    &NST_walker,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(9)},
    {-WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker3
};

static const Actor robo0 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(1)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &walker4
};

static const Actor robo1 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(3)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo0
};

static const Actor robo2 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(5)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo1
};

static const Actor robo3 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(7)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo2
};

static const Actor robo4 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(9)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo3
};


const Board level32 = {
    {
     RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,
       0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,
     BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, UP1,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, TUR,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, C6H,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2, //music
    0,
    5000, //bonus
    &robo4, //nasties
    &glp //players
};