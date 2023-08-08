#include "SOI.h"

#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor beanie0 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(3)},
    {NASTIE_SPEED, 0},
    0,
    0,
    0,
};

static const Actor beanie1 = {
    &NST_beanie,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(5)},
    {NASTIE_SPEED, 0},
    0,
    0,
    &beanie0,
};

static const Actor wheel0 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(13)},
    {-FAST_SPEED, 0},
    0,
    0,
    &beanie1,
};

static const Actor wheel1 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
    {-FAST_SPEED, 0},
    0,
    0,
    &wheel0,
};


const Board level58 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, FRI,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, NET,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET,
     NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET,
     GRO, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
     NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, NET, RDD,
     NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, NET, BOR, FRI, BOR, NET,
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
    MUS_HEAVY2,
    0,
    6000,
    &wheel1,
    &glp
};