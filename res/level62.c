#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT  | COL_WHITE)
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
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor walker0 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(2)},
    {WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    0
};

static const Actor walker1 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(10)},
    {WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker0
};

static const Actor walker2 = {
    &NST_walker,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(13)},
    {WALKP_SPEED, 0},
    MAX_TIMER - 120,
    0,
    &walker1
};

static const Actor beanie = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(13)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &walker2
};

// FIXME: ADD MOVING BLOCKS
const Board level62_broken = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, NET, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, NET,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,   0,
       0, NET, NET, NET, BOW,   0, NET, NET, NET, BOW,   0, NET, NET, NET, BOW,   0, NET, NET, NET,
       0, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, NET, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, NET,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    6000, //bonus
    &beanie, //nasties
    &glp //players
};