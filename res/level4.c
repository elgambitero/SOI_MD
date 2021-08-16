#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)
#define UP1 (GOODIE | GDi_1UP)
#define SLC (GOODIE | GDi_SILVC)
#define GLC (GOODIE | GDi_GOLDC)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(8) + 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(12) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor wheel = {&NST_whslowL,
   NST_L_LEFT,
   0,
   {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(11)},
   {-SLO_SPEED, 0},
      0,
   0,
   0,
   };



const Board level4 = {
    {
     BFW, BFW, BFW, BFW, BFW, BFW, BOW, GLC,   0, RDK,   0, GLC, BOW, BFW, BFW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BFW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0, BOW, BFW, BFW, BFW,
     BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW,   0, BOW,   0,   0,   0,   0,   0, BOW, BFW, BFW,
     BFW, BOW,   0,   0,   0,   0,   0, BOW,   0, RDD,   0, BOW,   0,   0,   0,   0,   0, BOW, BFW,
     BOW, SLC,   0,   0,   0,   0, BOW, SLC,   0,   0,   0, SLC, BOW,   0,   0,   0,   0, SLC, BOW,
     BFW, BOW,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0,   0,   0, BOW, BFW,
     BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0,   0,   0, BOW, BFW, BFW,
     BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW,   0,   0,   0,   0,   0, BOW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW,   0,   0,   0, BOW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW, SLC, BOW, BFW, BFW, BFW, BFW, BFW,
     BFW, BFW, BFW, BFW, BFW, BFW, BOW,   0,   0,   0,   0,   0, BOW, BFW, BFW, BFW, BFW, BFW, BFW,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, UP1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    MUS_HEAVY1, //music
    0,
    5000, //bonus
    &wheel, //nasties
    &glp //players
};