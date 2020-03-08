#include "levels.h"
#include "blocks.h"

#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)

static const Actor blp = {&blue_player_ent,
       0,
       0,
    {176, 208},
    {   0,    0},
       0,
       0
    };

static const Actor spinner3 = {&spinner_ent,
       0,
       0,
    {150, 208},
    {   0,    0},
       0,
       0
    };

static const Actor spinner2 = {&spinner_ent,
       0,
       0,
    {118, 20},
    {   0,    0},
       0,
    &spinner3
    };

static const Actor spinner = {&spinner_ent,
       0,
       0,
    {182, 208},
    {   0,    0},
       0,
    &spinner2
    };



const Board level1 = {
    {
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0, BOR, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BFW, BOR,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFW, BFW, BOR,   0,   0,   0,   0, BOR, BFW, BFW, BFW, BOR,   0,   0,   0,   0, BOR, BFW, BFW,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
     BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR, BFR, BFW,   0,   0,   0,   0, BFW, BFR, BFR,
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
    &spinner
};