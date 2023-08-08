#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT  | COL_WHITE)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(4)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(5)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor robo0 = {
    &NST_robo,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(11)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    0
};

static const Actor spawn0 = {
    &SPW_teeth,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
    {0, 0},
    MAX_TIMER - SPAWN_TIME,
    0,
    &robo0,
    {
        .spwData = {
            1200,
            0,
            0
        }
    }
};

static const Actor beanie = {
    &NST_beanie,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(2)},
    {-NASTIE_SPEED, 0},
    0,
    0,
    &spawn0,
};


const Board level61 = {
    {
     TYO,   0, SLC,   0,   0,   0,   0,   0,   0, TEH,   0,   0,   0,   0,   0,   0, SLC,   0, TGO,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, NET, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW, BOW,   0,   0,   0,   0, SLC, BOW,   0, BOW, SLC,   0,   0,   0,   0, BOW, BOW, BOW,
       0,   0,   0, BOW, BOW, BOW, BOW, BOW, BOW,   0, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,
       0, BOW,   0,   0,   0, RDD,   0,   0,   0, SLC,   0,   0,   0, RDK,   0,   0,   0, BOW,   0,
       0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,
       0,   0,   0,   0,   0,   0,   0,   0, TGI, BOW, TYI,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, C3H,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, GEM,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    6000, //bonus
    &beanie, //nasties
    &glp //players
};