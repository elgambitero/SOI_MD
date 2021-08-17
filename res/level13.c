#include "SOI.h"

#define BDK (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)
#define SLC (GOODIE | GDi_SILVC)
#define GLC (GOODIE | GDi_GOLDC)
#define ARR (GOODIE | GDi_ARROW)
#define C3H (GOODIE | GDi_CLK3h)
#define GLS (GOODIE | GDi_GLASS)
#define M2X (GOODIE | GDi_2x )
#define M3X (GOODIE | GDi_3x )
#define THN (GOODIE | GDi_THNBALL)
#define GEM (GOODIE | GDi_GEM)
#define TUR (GOODIE | GDi_TURTL)
#define SHL (GOODIE | GDi_SHLD)
#define BOO (GOODIE | GDi_BOOT)
#define UP1 (GOODIE | GDi_1UP)
#define GLD (GOODIE | GDi_GOLD)
#define BAL (GOODIE | GDi_BALL)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(1)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(1)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor robo = {&NST_robo,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(19) - 8 , BLOCK_TO_PX(13)},
   {-NASTIE_SPEED, 0},
      0,
   0,
   0,
   };

static const Actor spin = {&NST_spinner,
   0,
   0,
   {BLOCK_TO_PX(1) - 8 , BLOCK_TO_PX(9)},
   {0, 0},
      0,
   0,
   &robo,
};

static const Actor spin1 = {&NST_spinner,
   0,
   0,
   {BLOCK_TO_PX(19) - 8 , BLOCK_TO_PX(9)},
   {0, 0},
      0,
   0,
   &spin,
};

static const Actor spawn = {&SPW_hippo,
   0,
   0,
   {BLOCK_TO_PX(10) - 8 , BLOCK_TO_PX(1)},
   {0, 0},
   MAX_TIMER - SPAWN_TIME,
   0,
   &spin1,
};




const Board level13 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, HPO,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BDW,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDW,
       0, BDW, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDW,   0,
     RDK,   0, BDW, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDW,   0, RDD,
       0,   0,   0, BDW, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDW,   0,   0,   0,
       0,   0,   0,   0, BDW, BDK, BDK, BDK, BDK, THN, BDK, BDK, BDK, BDK, BDW,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BDW, BDK, BDK, BDK, BDK, BDK, BDK, BDK, BDW,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BDW, BDK, BDK, BDK, BDK, BDK, BDW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BDW, BDK, BDK, BDK, BDW,   0,   0,   0,   0,   0,   0,   0,
     BOW,   0,   0,   0,   0,   0,   0,   0, BDW, BDK, BDW,   0,   0,   0,   0,   0,   0,   0, BOW,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     GLD,   0,   0,   0,   0,   0,   0,   0,   0, BAL,   0,   0,   0,   0,   0,   0,   0,   0, UP1,
       0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, THN,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BOO,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SHL,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_BK, PAL_GR, PAL_BL},
    MUS_HEAVY1, //music
    0,
    6000, //bonus
    &spawn, //nasties
    &glp //players
};