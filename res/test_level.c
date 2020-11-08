#include "levels.h"
#include "blocks.h"
#include "actors.h"

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
#define GLC (GOODIE | GD_GOLDC)
#define ARR (GOODIE | GD_ARROW)
#define C3H (GOODIE | GD_CLK3h)
#define M2X (GOODIE | GD_2x)
#define RDK (GOODIE | GD_RDKEY)
#define RDD (GOODIE | GD_RDDOOR)
#define THN (GOODIE | GD_THNBALL)

static const Actor blp = {&blue_player_ent,
       STILL_RIGHT,
       0,
    {104, 31},
    {   0,    0},
      0,
       0,
       0
    };

static const Actor glp = {&green_player_ent,
       STILL_RIGHT,
       0,
    {120, 31},
    {   0,    0},
      0,
       0,
       &blp
    };

static const Actor spinner3 = {&spinner_ent,
       0,
       0,
    {134, 60},
    {   0,    0},
      0,
       0,
      0
    };

static const Actor spinner2 = {&spinner_ent,
       0,
       0,
    {166, 60},
    {   0,    0},
      0,
       0,
    &spinner3
    };


static const Actor spinner = {&spinner_ent,
       0,
       0,
    {150, 60},
    {   0,    0},
      0,
       0,
    &spinner2
    };

static const Actor robo = {&teeth_ent,
   WALK_RIGHT,
   0,
   {152, 32},
   {0, 0},
      MAX_TIMER - STAY_TIME,
   0,
   &spinner
   };

static const Actor piggy = {&piggy_ent,
   WALK_RIGHT,
   0,
   {264, 31},
   {0, 0},
      0,
   0,
   &robo
   };

static const Actor ant = {&ant_ent,
      0,
      0,
   {264, 31},
   {   0,    0},
      MAX_TIMER - STAY_TIME,
      0,
   &piggy
   };

static const Actor ant_spawn = {&ant_spawner_ent,
      0,
      0,
      {231,31},
      {0, 0},
      0,
      0,
      &ant
};


const Board test_level = {
    {
     BFW, BOW, BDW, CHI, QUE, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFG, BOG, BDG,   0,   0,   0,   0,   0,   0, RDK,   0, RDD,   0,   0,   0,   0,   0,   0,   0,
     BFR, BOR, BDR,   0,   0,   0, BOR, BOR, BOR, BOR, BOR, BOR, BOW, BOR, BOR, BOR,   0,   0,   0,
     BFB, BOB, BDB,   0,   0,   0, BOB, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BOB, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,  GLC, BDB,
       0,   0,   0,   0,   0,   0, BOB, NET,   0, NET, NET,   0,   0,   0,   0,   0, BOG, BDR,   0,
      GP, THN,   0,   0,   0,   0, BOB, NET,   0, NET, NET,   0,   0, BFG, GLC, GLC,   0,   0,   0,
       0,  BP,   0, ARR,   0,   0,   0, NET,   0, BFW,   0,   0,   0,   0, BFW, BFW,   0,   0,   0,
       0,   0,  BP,  OB,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0, NET, NET, BFW,
       0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0, BFW, BFW,   0,   0,   0,   0, QUE, BFW,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,
       0,   0,   0, C3H,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0, C3H,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLC, GLC,  FW,   0,   0,   0,   0,
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
    {PAL_GR, PAL_R, PAL_BL},
    0,
    0,
    &ant_spawn,
    &glp
};