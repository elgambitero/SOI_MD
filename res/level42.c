#include "SOI.h"

#define BDR (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_DONUT | COL_SLOT1)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)

static const Actor blp = {&PL_blue,
       0,
       0,
    {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(13)},
    {   0,    0},
      0,
      0,
      0
    };

   static const Actor glp = {&PL_green,
      0,
      0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor spawn = {&SPW_smiley,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(1)},
   {-NASTIE_SPEED, 0},
      0,
   0,
   0,
   {
     .spwData = 
      {
         600,
         ALTERNATE,
         0
      }
   }
   };

static const Actor spinner0 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(1)},
   {0, 0},
      0,
   0,
   &spawn,
   };

static const Actor spinner1 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(1)},
   {0, 0},
      0,
   0,
   &spinner0,
   };

static const Actor spinner2 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(3)},
   {0, 0},
      0,
   0,
   &spinner1,
};

static const Actor spinner3 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(3)},
   {0, 0},
      0,
   0,
   &spinner2,
};

static const Actor spinner4 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(3)},
   {0, 0},
      0,
   0,
   &spinner3,
};

static const Actor spinner5 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(13) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner4,
};

static const Actor spinner6 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(7) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner5,
};

static const Actor spinner7 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner6,
};

static const Actor spinner8 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(10) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner7,
};

static const Actor spinner9 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner8,
};

const Board level42 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0, SMI,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BDR,   0,   0, GLD,   0,   0, BDR,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BDR,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,   0, BDR,   0,
       0,   0, BOW, BOW, BOW, BOW, BOW, BOW, BOW, RDK, BOW, BOW, BOW, BOW, BOW, BOW, BOW,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0, BOW, BOW, BOW, BOW, BOW, RDD, BOW, BOW, BOW, BOW, BOW,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    MUS_HEAVY2, //music
    0,
    6000, //bonus
    &spinner9, //nasties
    &glp //players
};