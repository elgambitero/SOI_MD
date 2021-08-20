#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define GLC (GOODIE | GDi_GOLDC)
#define SLC (GOODIE | GDi_SILVC)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)

static const Actor blp = {&PL_blue,
       0,
       0,
    {120, 112},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {184, 112},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor robo = {&NST_robo,
   WALK_RIGHT,
   0,
   {40, 32},
   {0, 0},
      0,
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
    MUS_HEAVY1,
    0,
    3000,
    &robo,
    &glp
};