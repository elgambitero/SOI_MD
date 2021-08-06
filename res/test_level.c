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
#define CHI (NORMAL_BLOCK | SOLID | BLK_CHISEL)
#define QUE (NORMAL_BLOCK | SOLID | BLK_QUESTION)
#define NET (NORMAL_BLOCK | BLK_NET)
#define GLC (GOODIE | GDi_GOLDC)
#define ARR (GOODIE | GDi_ARROW)
#define C3H (GOODIE | GDi_CLK3h)
#define M2X (GOODIE | GDi_2x)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)
#define THN (GOODIE | GDi_THNBALL)
#define BOO (GOODIE | GDi_BOOT)
#define SHI (GOODIE | GDi_SHLD)
#define X3  (GOODIE | GDi_3x )
#define TUR (GOODIE | GDi_TURTL)



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

static const Actor ant = {&NST_ant,
      0,
      0,
   {264, 31},
   {   0,    0},
      MAX_TIMER - STAY_TIME,
      0,
   &piggy
   };

static const Actor ant_spawn = {&SPW_ant,
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
     BFG, BOG, BDG,   0,   0,   0,   0,   0,   0, BOO,   0, RDD,   0, TUR,  X3,   0,   0,   0,   0,
     BFR, BOR, BDR,   0,   0,   0, BOR, BOR, BOR, BOR, BOR, BOR, BOW, BOR, BOR, BOR,   0,   0,   0,
     BFB, BOB, BDB,   0,   0,   0, BOB, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BOB, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,  GLC, BDB,
     RDK,   0,   0,   0,   0,   0, BOB, NET,   0, NET, NET,   0,   0,   0,   0,   0, BOG, BDR,   0,
      GP, THN,   0,   0,   0,   0, BOB, NET,   0, NET, NET,   0,   0, BFG, GLC, GLC,   0,   0,   0,
       0,  BP,   0, ARR,   0,   0,   0, NET,   0, BFW,   0,   0,   0,   0, BFW, BFW,   0,   0,   0,
       0,   0,  BP,  OB,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0, NET, NET, BFW,
       0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0, BFW, BFW,   0,   0,   0,   0, QUE, BFW,   0,
     CNR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,
       0, SHI,   0, C3H,   0,   0,   0, RDD,   0,   0, TRI, TGI, TBI, TNI, TYI, TWI, C3H,   0,   0,
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
    {PAL_GR, PAL_R, PAL_BL},
    2,
    0,
    5000,
    &cannon_l,
    &glp
};