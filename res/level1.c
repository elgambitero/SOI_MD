#include "levels.h"
#include "blocks.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define GLC (GOODIE | GD_GOLDC)
#define SLC (GOODIE | GD_SILVC)
#define RDK (GOODIE | GD_RDKEY)
#define RDD (GOODIE | GD_RDDOOR)

static const Actor blp = {&blue_player_ent,
       0,
       0,
    {120, 112},
    {   0,    0},
      0,
      0
    };

   static const Actor glp = {&green_player_ent,
      0,
      0,
   {184, 112},
   {   0,    0},
      0,
      &blp
   };

static const Actor robo = {&robo_ent,
   WALK_RIGHT,
   0,
   {40, 32},
   {0, 0},
   0,
   0,
   };



const Board level1 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, SLC,   0,   0,   0,   0,   0, GLC,   0, GLC,   0,   0,   0,   0,   0, SLC,   0,   0,
       0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0,
       0,   0,   0,   0,   0, SLC,   0,   0,   0,  SLC,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,
     BFW, BFW, BOR,   0,   0,   0,   0, BOR, BFW, BFW, BFW, BOR,   0,   0,   0,   0, BOR, BFW, BFW,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW, SLC,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0, SLC, BFW, BFR, BFR,
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
    0,
    0,
    &robo,
    &glp
};