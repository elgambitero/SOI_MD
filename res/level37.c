#include "SOI.h"

#define BOK (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT   | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)



static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheel0 = {
    &NST_whfastR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(3)},
    {FAST_SPEED, 0},
    0,
    0,
    0,
};

static const Actor wheel1 = {
    &NST_whfastR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(11)},
    {FAST_SPEED, 0},
    0,
    0,
    &wheel0,
};

static const Actor wheel2 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(3)},
    {-FAST_SPEED, 0},
    0,
    0,
    &wheel1,
};

static const Actor wheel3 = {
    &NST_whfastL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(11)},
    {-FAST_SPEED, 0},
    0,
    0,
    &wheel2,
};


const Board level37 = {
    {
     TBO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, TGO,
       0, BOK, BOK, BOK, BOK, BOK, BOK,   0, BOW,   0, BOW,   0, BOK, BOK, BOK, BOK, BOK, BOK,   0,
       0, BOK,   0,   0,   0,   0, BOK,   0, BOW,   0, BOW,   0, BOK,   0,   0,   0,   0, BOK,   0,
       0, BOK, BOK, BOK, BOK, BOK, BOK,   0, BOW,   0, BOW,   0, BOK, BOK, BOK, BOK, BOK, BOK,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,
     TBI,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0, TGI,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
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
    MUS_HEAVY1,
    0,
    8000,
    &wheel3,
    &glp
};