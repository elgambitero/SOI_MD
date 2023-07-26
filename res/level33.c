#include "SOI.h"

#define BFW (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_FLAT  | COL_WHITE)

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
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(13)},
   {   0,    0},
      0,
      0,
      &blp
   };

static const Actor bean = {&NST_beanie,
   WALK_LEFT,
   0,
   {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(2)},
   {-NASTIE_SPEED, 0},
      0,
   0,
   0,
   };

static const Actor spinner0 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(1) - 8, BLOCK_TO_PX(8)},
   {0, 0},
      0,
   0,
   &bean,
   };

static const Actor spinner1 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(2) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner0,
   };

static const Actor spinner2 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(3) - 8, BLOCK_TO_PX(8)},
   {0, 0},
      0,
   0,
   &spinner1,
};

static const Actor spinner3 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(4) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner2,
};

static const Actor spinner4 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(6) - 8, BLOCK_TO_PX(9)},
   {0, 0},
      0,
   0,
   &spinner3,
};

static const Actor spinner5 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(9) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner4,
};

static const Actor spinner6 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(11) - 8, BLOCK_TO_PX(10)},
   {0, 0},
      0,
   0,
   &spinner5,
};

static const Actor spinner7 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(15) - 8, BLOCK_TO_PX(5)},
   {0, 0},
      0,
   0,
   &spinner6,
};

static const Actor spinner8 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(16) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner7,
};

static const Actor spinner9 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(17) - 8, BLOCK_TO_PX(7)},
   {0, 0},
      0,
   0,
   &spinner8,
};

static const Actor spinner10 = {&NST_spinner,
   WALK_RIGHT,
   0,
   {BLOCK_TO_PX(18) - 8, BLOCK_TO_PX(6)},
   {0, 0},
      0,
   0,
   &spinner9,
};

static const Actor can0 = {
    &SPW_cannon,
    WALK_RIGHT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(2)},
    {0, 0},
    MAX_TIMER - CANNON_TIME,
    0,
    &spinner10,
};

static const Actor can1 = {
    &SPW_cannon,
    WALK_LEFT,
    0,
    {BLOCK_TO_PX(19) - 8, BLOCK_TO_PX(6)},
    {0, 0},
    MAX_TIMER - 600,
    0,
    &can0,
};

const Board level33 = {
    {
     C3H,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, GLS,
       0, BFW,   0, BFW,   0, BFW,   0, BFW, BFW, BFW, BFW, BFW,   0, BFW,   0, BFW,   0, BFW, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDK,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BFW,   0, BFW, CNL,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, RDD,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },

    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, SLC,   0,
     ARR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0, SHL,   0,   0,   0,   0,   0, GLC,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, M2X,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, ARR,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    },
    {PAL_R, PAL_GR, PAL_BL},
    MUS_HEAVY3, //music
    0,
    3000, //bonus
    &spinner11, //nasties
    &glp //players
};