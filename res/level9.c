#include "SOI.h"

#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)

static const Actor blp = {
    &PL_blue,
    0,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(11)},
    {   0,    0},
    0,
    0,
    0
};

static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(11)},
    {   0,    0},
    0,
    0,
    &blp
};

static const Actor spinner = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(4)},
    {0, 0},
    0,
    0,
    0,
};

static const Actor wheel = {
    &NST_whslowL,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(10)},
    {-SLO_SPEED, 0},
    0,
    0,
    &spinner,
};



const Board level9 = {
    {
       0,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOR, BOR,   0,   0,   0,   0,   0, BOR, BOR,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOR,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOR,   0,   0,   0,   0,
       0,   0,   0, BOR,   0,   0, BOW, RDD,   0,   0,   0, RDK, BOW,   0,   0, BOR,   0,   0,   0,
       0,   0, BOR,   0,   0, BOW, BDW, BOW,   0,   0,   0, BOW, BDW, BOW,   0,   0, BOR,   0,   0,
       0,   0, BOR,   0,   0,   0, BOW,   0,   0, BOW,   0,   0, BOW,   0,   0,   0, BOR,   0,   0,
       0,   0, BOR,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0, BOR,   0,   0,
       0,   0, BOR,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0, BOR,   0,   0,
       0,   0, BOR,   0,   0,   0,   0,   0,   0, BOO,   0,   0,   0,   0,   0,   0, BOR,   0,   0,
       0,   0,   0, BOR,   0,   0, BOW, BOW,   0,   0,   0, BOW, BOW,   0,   0, BOR,   0,   0,   0,
       0,   0,   0,   0, BOR,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0, BOR,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOR, BOR,   0,   0,   0,   0,   0, BOR, BOR,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BOR, BOR, BOR, BOR, BOR,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, M2X,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3,
    0,
    5000,
    &wheel,
    &glp
};