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
      NULL
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

static const Actor robo0 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(2)},
    {NASTIE_SPEED, 0},
    0,
    0,
    NULL
};

static const Actor robo1 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(2)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo0
};

static const Actor robo2 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(4)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo1
};

static const Actor robo3 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(4)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo2
};

static const Actor robo4 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(6)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo3
};

static const Actor robo5 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(6)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo4
};

static const Actor robo6 = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(8)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo5
};

static const Actor robo7 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(8)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &robo6
};

static const Actor beanie = {
    &NST_robo,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(12)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &robo7
};


const Board level63 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0, RDK, BOW, RDD,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0, BOW,
       0,   0,   0,   0,   0,   0, BOW, BOW, BOW, NET, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,
     BOW,   0, BOW,   0,   0,   0,   0,   0, BOW, GLC, BOW,   0,   0,   0,   0,   0, BOW,   0, BOW,
       0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,   0, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,
     BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,
       0,   0, BOW, BOW, BOW, BOW, NET,   0,   0,   0,   0,   0, NET, BOW, BOW, BOW, BOW,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0, NET, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
     UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, UP1,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GEM,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,
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
    MUS_HEAVY3, //music
    0,
    6000, //bonus
    &beanie, //nasties
    &glp //players
};