#ifndef BLOCKS_H

#define BLOCKS_H

#include "globals.h"

#define NORMAL_BLOCK    0x0001

#define SOLID           0x0004
#define BREAKABLE       0x0008
#define BROKEN          0x0010

#define NBLK_TYP_MSK    0x00E0

#define BLK_NOTHING    (0 << 5)
#define BLK_FLAT       (1 << 5)
#define BLK_DOT        (2 << 5)
#define BLK_DONUT      (3 << 5)
#define BLK_CHISEL     (4 << 5)
#define BLK_NET        (5 << 5)
#define BLK_QUESTION   (6 << 5)
#define BLK_PLAYER     (7 << 5)

#define NBLK_COL_MSK    0x0300

#define GET_BLK_PAL(byte) (byte >> 8)

#define COL_WHITE     (0 << 8)
#define COL_SLOT1     (1 << 8)
#define COL_SLOT2     (2 << 8)
#define COL_SLOT3     (3 << 8)

#define PL_BLUE       (0 << 8)
#define PL_GREEN      (1 << 8)

#define PAL_GR 0
#define PAL_R  1
#define PAL_BL 2
#define PAL_PI 3
#define PAL_YL 4
#define PAL_BK 5


#define SPECIAL_BLOCK   0x0002

#define SP_ACTIVE       0x0004

#define SP_TYP_MSK      0x0018

#define SP_TRANS        (1 << 3)
#define SP_SWITCH       (2 << 3)
#define SP_FLOP         (3 << 3)

#define SP_COL_MSK      0x0700

#define GOODIE          0x0003
#define GOOD_TYP_MSK    0x00FC
#define GD_GET_INDEX(good) ( good >> 2 )

#define GD_ADD_INFO(good) ( good << 8 )
#define GD_GET_INFO(gd)   ( gd >> 8 )

#define GD_SILVC         (0 << 2)
#define GD_ARROW         (1 << 2)
#define GD_CLK3h         (2 << 2)
#define GD_CLK6h         (3 << 2)
#define GD_CLK9h         (4 << 2)
#define GD_CLK12h        (5 << 2)
#define GD_GLASS         (6 << 2)
#define GD_SHLD          (7 << 2)
#define GD_BOOT          (8 << 2)
#define GD_THNBALL       (9 << 2)
#define GD_RDKEY         (10 << 2)
#define GD_BLKEY         (11 << 2)
#define GD_RDDOOR        (12 << 2)
#define GD_BLDOOR        (13 << 2)
#define GD_RDDOOR_open   (14 << 2)
#define GD_BLDOOR_open   (15 << 2)
#define GD_GOLDC         (16 << 2)
#define GD_1UP           (17 << 2)
#define GD_2x            (18 << 2)
#define GD_3x            (19 << 2)
#define GD_4x            (20 << 2)
#define GD_5x            (21 << 2)
#define GD_BALL          (22 << 2)
#define GD_GEM           (23 << 2)
#define GD_GOLD          (24 << 2)
#define GD_TURTL         (25 << 2)
#define GD_STAR          (26 << 2)
#define GD_GRKEY         (27 << 2)
#define GD_GRDOOR        (28 << 2)
#define GD_GRDOOR_open   (29 << 2)

#define  BP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_BLUE )
#define  GP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_GREEN )

void drawBlock(u8 x, u8 y, u16 block);
void eraseBlock(u8 x, u8 y);

#endif