#include "SOI.h"

#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {
    &PL_blue,
    0,
    0,
    {BLOCK_TO_PX(0) - 8, BLOCK_TO_PX(11)},
    {   0,    0},
    0,
    0,
    0
};

   static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(11)},
    {   0,    0},
    0,
    0,
    &blp
};


static const Actor spinner0 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    0,
};

static const Actor spinner1 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    &spinner0,
};

static const Actor spinner2 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    0,
    0,
    &spinner1,
};

static const Actor spinner3 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    0,
    0,
    &spinner2,
};

static const Actor spinner4 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    &spinner3,
};

static const Actor spinner5 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    &spinner4,
};




const Board level6 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0, BDW, TGO, BDW,   0,   0,   0,   0,   0,   0,   0, TGO,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, TGI,   0,   0,   0,   0, BDW,   0, BDW,   0,   0,   0,   0, RDD,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BDW,   0, BDW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BDW,   0, BDW,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BOG,   0,   0,   0, BOG,   0,   0, BDW,   0, BDW,   0,   0, BOG,   0,   0,   0, BOG,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BDW, RDK, BDW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BDW,   0,   0,   0, BDW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BDW, GEM,   0, GEM, BDW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BDW, NET, NET, NET, BDW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BDW, BDW, NET, NET, NET, NET, NET,  BDW BDW,   0,   0,   0,   0,   0,
       0,   0,   0, BDW, BDW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDW, BDW,   0,   0,   0,
     BDW, BDW, BDW,   0,   0,   0,   0,   0,   0, TGI,   0,   0,   0,   0,   0,   0, BDW, BDW, BDW,
    },

    {
     GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, C3H,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, UP1,   0, M3X,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_GR, PAL_R, PAL_BL},
    MUS_HEAVY3,
    0,
    3000,
    &spinner5,
    &glp
};