#include "SOI.h"

#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)


static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(7)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(8) - 8, BLOCK_TO_PX(7)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor wheel0 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(2)},
    {-SLO_SPEED, 0},
    0,
    0,
    0,
};


static const Actor wheel1 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(2)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel0,
};


static const Actor wheel2 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(4)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel1,
};


static const Actor wheel3 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(4)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel2,
};


static const Actor wheel4 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(6)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel3,
};


static const Actor wheel5 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(6)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel4,
};


static const Actor wheel6 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(5) - 8, BLOCK_TO_PX(8)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel5,
};


static const Actor wheel7 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(8)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel6,
};


static const Actor wheel8 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(10)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel7,
};


static const Actor wheel9 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(10)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel8,
};


static const Actor wheel10 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(12)},
    {-SLO_SPEED, 0},
    0,
    0,
    &wheel9,
};


static const Actor wheel11 = {
    &NST_whslowL,
    NST_L_LEFT,
    0,
    {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(12)},
    {-SLO_SPEED, 0},
    0,
    0,
    0&wheel10,
};


const Board level45 = {
    {
     BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW, RDK, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,
       0, BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0,
     BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0,   0,
       0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0,
     BFW,   0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BOW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,
       0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BOG,   0,
     BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BOG,
       0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0,
     BFW,   0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,
       0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BOW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0,
     BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,
       0, BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW,   0, BFW,   0,
     BFW,   0, BFW,   0, BFW,   0, BOG,   0, BFW, RDD, BFW,   0, BOG,   0, BFW,   0, BFW,   0, BFW,
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
    &wheel11,
    &glp
};