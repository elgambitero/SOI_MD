#include "levels.h"
#include "blocks.h"

#define BDG (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT1)
#define BOG (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT1)
#define BDR (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT2)
#define BOR (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT2)
#define BDB (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_SLOT3)
#define BOB (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_SLOT3)
#define BDW (NORMAL_BLOCK | SOLID | BLK_DONUT | COL_WHITE)
#define BOW (NORMAL_BLOCK | SOLID | BLK_DOT   | COL_WHITE)
#define BFW (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_WHITE)
#define BFG (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT1)
#define BFR (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT2)
#define BFB (NORMAL_BLOCK | SOLID | BLK_FLAT  | COL_SLOT3)
#define CHI (NORMAL_BLOCK | SOLID | BLK_CHISEL)
#define QUE (NORMAL_BLOCK | SOLID | BLK_QUESTION)
#define NET (NORMAL_BLOCK | BLK_NET)

static const Actor blp = {&blue_player_ent,
       0,
       0,
    {176, 208},
    {   0,    0},
       0,
       0
    };

static const Actor spinner8 = {&spinner_ent,
       0,
       0,
    {96, 40},
    {   0,    0},
       0,
       0
    };

static const Actor spinner7 = {&spinner_ent,
       0,
       0,
    {214, 40},
    {   0,    0},
       0,
       &spinner8
    };

static const Actor spinner6 = {&spinner_ent,
       0,
       0,
    {198, 40},
    {   0,    0},
       0,
       &spinner7
    };

static const Actor spinner5 = {&spinner_ent,
       0,
       0,
    {182, 40},
    {   0,    0},
       0,
       &spinner6
    };

static const Actor spinner4 = {&spinner_ent,
       0,
       0,
    {166, 40},
    {   0,    0},
       0,
       &spinner5
    };

static const Actor spinner3 = {&spinner_ent,
       0,
       0,
    {134, 40},
    {   0,    0},
       0,
      &spinner4
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
    {150, 60},
    {   0,    0},
       0,
    &spinner2
    };



const Board test_level = {
    {
     BFW, BOW, BDW, CHI, QUE, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFG, BOG, BDG,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFR, BOR, BDR,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
     BFB, BOB, BDB,   0,   0,   0,   0, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, NET, NET, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, NET,   0, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, NET,   0, NET, NET,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, NET,   0, BFW,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0, NET,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0, BFW,   0, BFW,   0,   0, BFW, BFW,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, BDR,   0,   0,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
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
    {PAL_GR, PAL_R, PAL_BL},
    0,
    &spinner
};