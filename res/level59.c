#include "SOI.h"

#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_SLOT1)


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
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(1)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {&SPW_piggy,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
   {0, 0},
   MAX_TIMER - SPAWN_TIME,
   0,
   0,
   {
     .spwData = 
      {
         1000,
         SEEK_PLAYER,
         0
      }
   }
   };


const Board level59 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, PIG,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BOW, BOW,   0,   0,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BOW,
       0,   0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BOW,   0, BOW,   0, BOW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BOW, BFR, RDK, BOW, RDD, BFR, BOW,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BOW, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BOW,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BOW,   0,   0,   0,   0,
       0,   0,   0, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BOW,   0,   0,   0,
     BFR,   0, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BOW,   0,   0,
       0, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BFR, BOW,   0,   0,
     BFR,   0, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BOW,   0,   0,
       0, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BFR, BOW,   0,   0,
     BOW,   0, BFR,   0, BOW, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BFR, BOW, BFR, BFR, BFR, BOW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, BAL,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,
       0,   0,   0, GLC,   0,   0, SLC,   0,   0,   0,   0,   0,   0,   0,   0, GLC,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,   0,   0,   0,   0,   0, SLC,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3, //music
    0,
    8000, //bonus
    &spawn, //nasties
    &glp //players
};