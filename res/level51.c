#include "SOI.h"

#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheel0 = {
    &NST_whslowR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(3)},
    {SLO_SPEED, 0},
    0,
    0,
    0,
};


static const Actor wheel1 = {
    &NST_whslowR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(11)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel0,
};


static const Actor wheel2 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(3)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel1,
};


static const Actor wheel3 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(11)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel2,
};


static const Actor wheel4 = {
    &NST_whslowR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(6)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel3,
};


static const Actor wheel5 = {
    &NST_whslowR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(6)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel4,
};


static const Actor wheel6 = {
    &NST_whslowR,
    NST_R_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(6)},
    {SLO_SPEED, 0},
    0,
    0,
    &wheel5,
};

// TODO: MOVING BLOCKS MISSING
const Board level51_broken = {
    {
     GLC,   0,   0,   0, SLC,   0,   0,   0,   0, RDK,   0,   0,   0,   0, SLC,   0,   0,   0, GLC,
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
     GLC,   0,   0,   0, SLC,   0,   0,   0,   0, RDD,   0,   0,   0,   0, SLC,   0,   0,   0, GLC,
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
    MUS_HEAVY1,
    0,
    6000,
    &wheel6,
    &glp
};