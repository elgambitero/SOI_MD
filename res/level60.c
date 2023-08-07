#include "SOI.h"

#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
     NULL
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };


static const Actor gargoyle = {&BS_gargoyle,
   BS_BIRTH,
   GL_BIRTH_FRAMES,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(13)},
   {0, 0},
   0,
   0,
   NULL,
   {.garData =
      {
         300,
         192,
         64,
         &NST_smiley
      }
   }
};

static const Actor knight = {&BS_knight,
   BS_BIRTH,
   KN_BIRTH_FRAMES,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(13)},
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


const Board level60 = {
    {
     RDK,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0, RDD,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
       0,   0,   0, CHI,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0, CHI,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
       0,   0,   0, CHI,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0, CHI,   0,   0,   0,
    },

    {
     CHI,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0, CHI,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
     CHI, CHI, CHI, CHI,   0,   0,   0,   0,   0, CHI,   0,   0,   0,   0,   0, CHI, CHI, CHI, CHI,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_BONUSHEAVY, //music
    BONUS_FLAG,
    6000, //bonus
    &knight, //nasties
    &glp //players
};