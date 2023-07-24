#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define CHI (NORMAL_BLOCK | SOLID | BLK_CHISEL)


static const Actor blp = {
    &PL_blue,
    0,
    0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
    0,
    0,
    0
};

static const Actor glp = {
    &PL_green,
    0,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
    0,
    0,
    &blp
};

static const Actor gargoyle = {
    &BS_gargoyle,
    BS_BIRTH,
    GL_BIRTH_FRAMES,
    {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(3)},
    {0, 0},
    0,
    0,
    NULL,
    {.spwData =
      {
        400,
        0,
        0
      }
   }
};

static const Actor knight = {
    &BS_knight,
    BS_BIRTH,
    KN_BIRTH_FRAMES,
    {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(3)},
    {0, 0},
    0,
    0,
    &gargoyle,
    {.spwData =
        {
            200,
            0,
            0
        }
    }
};

static const Actor spinner0 = {
    &NST_spinner,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(6)},
    {0, 0},
    0,
    0,
    &knight,
};

const Board level20 = {
    {
       0,   0,   0, CHI,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_BONUSHEAVY,
    BONUS_FLAG,
    3000,
    &spinner0,
    &glp
};