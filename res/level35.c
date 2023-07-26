#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT | COL_WHITE)
#define BRW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {
    &PL_blue,
    0,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(1)},
    {   0,    0},
    0,
    0,
    0
};

   static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(1)},
     {   0,    0},
    0,
    0,
    &blp
};



const Board level35 = {
    {
     NET, NET,   0, NET, NET, NET, NET, NET,   0, NET,   0, NET, NET, NET, NET, NET,   0, NET, NET,
     RDD, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, RDK,
     NET, NET, NET, NET,   0, NET, NET, NET, NET, NET, NET, NET,   0, NET,   0, NET, NET, NET, NET,
       0, NET, NET, NET, NET, NET,   0, NET, NET, NET,   0, NET, NET, NET, NET, NET,   0, NET, NET,
     NET, NET,   0, NET, NET, NET, NET, NET,   0, NET, NET, NET, NET,   0, NET, NET, NET, NET, NET,
     NET, NET, NET, NET, NET, NET,   0, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,   0, NET,
     NET,   0, NET, NET, NET, NET, NET,   0, NET, NET, NET, NET, NET, NET, NET,   0, NET, NET, NET,
     NET, NET, NET,   0, NET, NET,   0, NET, NET, NET,   0, NET, NET, NET, NET, NET,   0, NET, NET,
     NET, NET,   0, NET, NET, NET, NET,   0, NET, NET, NET, NET,   0, NET, NET,   0, NET, NET, NET,
       0, NET, NET, NET, NET, NET,   0, NET, NET, NET,   0, NET, NET, NET, NET, NET, NET,   0, NET,
     NET,   0, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,   0, NET, NET, NET, NET,   0,
     NET, NET,   0, NET, NET,   0, NET, NET, NET, NET, NET, NET,   0, NET, NET, NET,   0, NET, NET,
       0, NET, NET, NET, NET, NET, NET, NET, NET, NET,   0, NET, NET, NET, NET, NET, NET, NET,   0,
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
    MUS_HEAVY2,
    0,
    8000,
    0,
    &glp
};