#ifndef BLOCKS_H

#define BLOCKS_H

#define BLK_TYPE        0x0003

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

#define TRANS_DIR_MSK   0x0800

#define TRANS_IN        0x0000
#define TRANS_OUT       0x0800


#define SP_COL_MSK      0x0700

#define SP_COL_GR       (0 << 8)
#define SP_COL_R        (1 << 8)
#define SP_COL_BL       (2 << 8)
#define SP_COL_PI       (3 << 8)
#define SP_COL_YL       (4 << 8)
#define SP_COL_BK       (5 << 8)

#define GOODIE          0x0003
#define GOOD_TYP_MSK    0x03F0
#define GD_GET_INDEX(good) ( ( GOOD_TYP_MSK & good) >> 4 )

#define GD_ADD_INFO(good) ( good << 8 )
#define GD_GET_INFO(gd)   ( gd >> 8 )

#define GDi_SILVC         (0 << 4)
#define GDi_ARROW         (1 << 4)
#define GDi_CLK3h         (2 << 4)
#define GDi_CLK6h         (3 << 4)
#define GDi_CLK9h         (4 << 4)
#define GDi_CLK12h        (5 << 4)
#define GDi_GLASS         (6 << 4)
#define GDi_SHLD          (7 << 4)
#define GDi_BOOT          (8 << 4)
#define GDi_THNBALL       (9 << 4)
#define GDi_RDKEY         (10 << 4)
#define GDi_BLKEY         (11 << 4)
#define GDi_RDDOOR        (12 << 4)
#define GDi_BLDOOR        (13 << 4)
#define GDi_RDDOOR_open   (14 << 4)
#define GDi_BLDOOR_open   (15 << 4)
#define GDi_GOLDC         (16 << 4)
#define GDi_1UP           (17 << 4)
#define GDi_2x            (18 << 4)
#define GDi_3x            (19 << 4)
#define GDi_4x            (20 << 4)
#define GDi_5x            (21 << 4)
#define GDi_BALL          (22 << 4)
#define GDi_GEM           (23 << 4)
#define GDi_GOLD          (24 << 4)
#define GDi_TURTL         (25 << 4)
#define GDi_STAR          (26 << 4)
#define GDi_GRKEY         (27 << 4)
#define GDi_GRDOOR        (28 << 4)
#define GDi_GRDOOR_open   (29 << 4)

#define  BP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_BLUE )
#define  GP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_GREEN )

void drawBlock(u8 x, u8 y, u16 block);
void eraseBlock(u8 x, u8 y);
void eraseBlock_ind(u8 ind);
void load_blk_tiles(u16 ind);

#endif