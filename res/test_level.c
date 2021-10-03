#include "SOI.h"

#define BDG (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT2)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BDB (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT3)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT3)
#define  OB (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DOT   | COL_SLOT3)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define  FW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)
#define BFG (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT2)
#define BFB (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT3)
#define NET (NORMAL_BLOCK | BLK_NET)



static const Actor blp = {&PL_blue,
       STILL_RIGHT,
       0,
    {104, 31},
    {   0,    0},
      0,
       0,
       NULL
    };

static const Actor glp = {&PL_green,
       STILL_RIGHT,
       0,
    {120, 31},
    {   0,    0},
      0,
       0,
       &blp
    };

static const Actor spinner3 = {&NST_spinner,
       0,
       0,
    {134, 60},
    {   0,    0},
      0,
       0,
      0
    };

static const Actor spinner2 = {&NST_spinner,
       0,
       0,
    {166, 60},
    {   0,    0},
      0,
       0,
    &spinner3
    };


static const Actor spinner = {&NST_spinner,
       0,
       0,
    {150, 60},
    {   0,    0},
      0,
       0,
    &spinner2
    };

static const Actor robo = {&NST_teeth,
   WALK_RIGHT,
   0,
   {152, 32},
   {0, 0},
      MAX_TIMER - STAY_TIME,
   0,
   &spinner
   };

static const Actor piggy = {&NST_piggy,
   WALK_RIGHT,
   0,
   {264, 31},
   {0, 0},
      0,
   0,
   &robo
   };

static const Actor ant = {&NST_beanie,
      WALK_DOWN,
      0,
   {216, 80},
   {  0, NASTIE_SPEED},
      0,
      0,
   &piggy
   };

static const Actor ant_spawn = {&SPW_hippo,
      0,
      0,
   {247, 32},
   {   0,    0},
      MAX_TIMER - SPAWN_TIME,
      0,
   &ant
   };


static const Actor cannon_r = {&SPW_cannon,
      0,
      0,
   {8, 176},
   {   0,    0},
      MAX_TIMER - CANNON_TIME,
      0,
   &ant_spawn
   };

static const Actor cannon_l = {&SPW_cannon,
      1,
      0,
   {296, 176},
   {   0,    0},
      MAX_TIMER - (CANNON_TIME/2),
      0,
   &cannon_r
   };

const Board test_level = {
    {
     BFW, BOW, BDW, CHI, QUE, NET,   0,   0,   0,   0,   0, TRO,   0,   0, TGO, TBO, TNO, TYO, TWO,
     BFG, BOG, BDG,   0, M5X,   0,   0,   0, UP1, BOO, RDK, RDD,   0,   0,   0, OST,   0,   0,   0,
     BFR, BOR, BDR,   0,   0,   0, BOR, BOR, BOR, BOR, BOR, BOR, BOW, BOR, BOR, BOR,   0,   0,   0,
     BFB, BOB, BDB,   0,   0,   0, BOB, NET, NET, NET, NET,   0,   0,   0,   0,   0, BOR,   0, TUR,
     GRI, GBI, GGI, GNI, GYI, GWI, BOB, NET, NET,   0, BOR,   0,   0,   0,   0,   0,   0, GLC, BDB,
       0,   0,   0, GNI,   0,   0, BOB, NET,   0, BOR, BOR, BOR,   0,   0,   0,   0, BOG, BDR,   0,
      GP, THN,   0,   0,   0,   0, BOB, NET,   0,   0, BOR,   0,   0, BFG, GLC, GLC,   0,   0,   0,
       0,  BP,   0, ARR,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0, BFW, BFW,   0,   0,   0,
       0,   0,  BP,  OB,   0,   0,   0, NET, ANT, HMR, HPO, OST, PIG, SMI, TEH,   0, NET, NET, BFW,
       0,   0,   0,   0,   0, BFW,   0, BFW,   0, BFW, BFW, BFW,   0,   0,   0,   0, QUE, BFW,   0,
     CNR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
     FRI, FBI, FGI, FNI, FYI, FWI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, SHL,   0, C3H,   0,   0,   0, RDD,   0,   0, TRI, TGI, TBI, TNI, TYI, TWI, C3H,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC, GLC,  FW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, GLC,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_PI, PAL_YL, PAL_BK},
    MUS_HEAVY3,
    0,
    1500,
    &cannon_l,
    &glp
};