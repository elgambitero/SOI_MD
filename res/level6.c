#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define CHI (NORMAL_BLOCK | SOLID | BLK_CHISEL)
#define GLC (GOODIE | GDi_GOLDC)
#define SLC (GOODIE | GDi_SILVC)
#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)


static const Actor blp = {&PL_blue,
       0,
       0,
    {8, 208},
    {   0,    0},
      0,
      0,
      0
    };

static const Actor glp = {&PL_green,
   0,
   0,
{24, 208},
{   0,    0},
   0,
   0,
   &blp
};

static const Actor gargoyle = {&BS_gargoyle,
   BS_BIRTH,
   GL_BIRTH_FRAMES,
   {280, 48},
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

static const Actor knight = {&BS_knight,
   BS_BIRTH,
   KN_BIRTH_FRAMES,
   {280, 112},
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

const Board level6 = {
    {
     RDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,
    },

    {
     CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_BONUSHEAVY,
    0,
    5000,
    &knight,
    &glp
};