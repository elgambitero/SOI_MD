#include "SOI.h"

#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)


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


static const Actor wheell0 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(2)},
    {-SLO_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheelr1 = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(2)},
    {SLO_SPEED, 0},
    0,
    0,
    &whell0,
};


static const Actor wheell2 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(5)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheelr1,
};

static const Actor wheelr3 = {
    &NST_whslowR,
    NST_R_RIGHT,
    0,
    {BLOCK_TO_PX(14) - 8, BLOCK_TO_PX(5)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheell2,
};


const Board level18 = {
    {
     SLC,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0, SLC,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0,
       0,   0, BFW, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC, BFW,   0,   0,
       0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,
       0,   0, BFW,   0,   0, BOG, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOG,   0,   0, BFW,   0,   0,
       0,   0, BFW,   0,   0, BFW,   0,   0,   0, RDK,   0,   0,   0, BFW,   0,   0, BFW,   0,   0,
       0,   0, BFW,   0,   0, BOG, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOG,   0,   0, BFW,   0,   0,
       0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,
       0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,
       0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY2,
    0,
    6000,
    &wheelr3,
    &glp
};