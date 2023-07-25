#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT | COL_WHITE)
#define BOK (NORMAL_BLOCK | SOLID | BLK_DOT | COL_SLOT1)
#define BRW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT | COL_WHITE)

static const Actor blp = {
    &PL_blue,
    0,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(3)},
    {   0,    0},
    0,
    0,
    0
};

   static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(3)},
    {   0,    0},
    0,
    0,
    &blp
};


// FIXME: MISSING MOVING BLOCKS
const Board level25_broken = {
    {
     BOK, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOK,
     BOW, BOK, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOK, BOW,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
     BOW, BOW, BOW, SLC, BOW, GLC, BOW, SLC, BOW, SLC, BOW, SLC, BOW, GLC, BOW, SLC, BOW, BOW, BOW,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
     BOW, BOW, SLC, BOW, SLC, BOW, SLC, BOW, GLC, BOW, GLC, BOW, SLC, BOW, SLC, BOW, SLC, BOW, BOW,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
     BOW, BOW, BOW, SLC, BOW, GLC, BOW, SLC, BOW, SLC, BOW, SLC, BOW, GLC, BOW, SLC, BOW, BOW, BOW,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
     BOW, BOW, SLC, BOW, SLC, BOW, SLC, BOW, GLC, BOW, GLC, BOW, SLC, BOW, SLC, BOW, SLC, BOW, BOW,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
     BOW, BOK, BOW, BOW, BOW, BOW, BOW, BOW, BOW, RDK, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOK, BOW,
     BOK, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOK,
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
    {PAL_BK, PAL_R, PAL_BL},
    MUS_HEAVY2,
    0,
    6000,
    0,
    &glp
};