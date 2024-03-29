#ifndef BLOCKS_H

#define BLOCKS_H

#define BLK_TYPE        (3 << 0) //2 bits

#define NORMAL_BLOCK    0x0001

#define SOLID                     (1 << 2)
#define BREAKABLE                 (1 << 3)
#define BROKEN                    (1 << 4)

#define NBLK_TYP_SHFT              5

#define NBLK_TYP_MSK              (7 << NBLK_TYP_SHFT) //3 bits

#define BLK_NOTHING               (0 << NBLK_TYP_SHFT)
#define BLK_FLAT                  (1 << NBLK_TYP_SHFT)
#define BLK_DOT                   (2 << NBLK_TYP_SHFT)
#define BLK_DONUT                 (3 << NBLK_TYP_SHFT)
#define BLK_CHISEL                (4 << NBLK_TYP_SHFT)
#define BLK_NET                   (5 << NBLK_TYP_SHFT)
#define BLK_QUESTION              (6 << NBLK_TYP_SHFT)
#define BLK_PLAYER                (7 << NBLK_TYP_SHFT)

#define NBLK_COL_SHFT              9

#define NBLK_COL_MSK              ((3 << NBLK_COL_SHFT))


#define COL_WHITE                 ((0 << NBLK_COL_SHFT))
#define COL_SLOT1                 ((1 << NBLK_COL_SHFT))
#define COL_SLOT2                 ((2 << NBLK_COL_SHFT))
#define COL_SLOT3                 ((3 << NBLK_COL_SHFT))

#define PL_BLUE                   ((0 << NBLK_COL_SHFT))
#define PL_GREEN                  ((1 << NBLK_COL_SHFT))

#define PAL_GR                    0
#define PAL_R                     1
#define PAL_BL                    2
#define PAL_PI                    3
#define PAL_YL                    4
#define PAL_BK                    5


#define SPECIAL_BLOCK           0x0002

#define SP_ACT_SHFT             2
#define SP_ACTIVE              (1 << SP_ACT_SHFT) //1 bit //what is this???

#define SP_TYP_SHFT             5

#define SP_TYP_MSK             (7 << SP_TYP_SHFT) //3 bit

#define SP_TRANS               (1 << SP_TYP_SHFT)
#define SP_SWITCH              (2 << SP_TYP_SHFT)
#define SP_FLOP                (3 << SP_TYP_SHFT)
#define SP_CANNON              (4 << SP_TYP_SHFT)
#define SP_GATE                (5 << SP_TYP_SHFT)
#define SP_SPAWNER             (6 << SP_TYP_SHFT)

#define TRANS_DIR_SHFT          11

#define TRANS_DIR_MSK          (1 << TRANS_DIR_SHFT) //1bit

#define TRANS_IN               (1 << TRANS_DIR_SHFT) //0x0800
#define TRANS_OUT              (0 << TRANS_DIR_SHFT) 

#define CAN_DIR_SHFT            11

#define CAN_DIR_MSK            (1 << CAN_DIR_SHFT)

#define CANNON_R               (0 << CAN_DIR_SHFT)
#define CANNON_L               (1 << CAN_DIR_SHFT)

#define FLOP_TOG_SHFT           11

#define FLOP_TOG_MSK           (1 << FLOP_TOG_SHFT) //1bit

#define FLOP_TOG_ON            (1 << FLOP_TOG_SHFT)
#define FLOP_TOG_OFF           (0 << FLOP_TOG_SHFT)

#define FLOP_ACT_SHFT           12

#define FLOP_ACT_MSK           (1 << FLOP_ACT_SHFT) //1bit

#define FLOP_ACT_ON            (1 << FLOP_ACT_SHFT)
#define FLOP_ACT_OFF           (0 << FLOP_ACT_SHFT)

#define GATE_SHFT               11

#define GATE_MSK               (1 << GATE_SHFT) //1bit

#define GATE_OPEN              (0 << GATE_SHFT)
#define GATE_CLOSED            (1 << GATE_SHFT)

#define NASTIE_SHFT            11

#define NASTIE_MSK             (7 << NASTIE_SHFT) //3bit

#define NASTIE_ANT             (0 << NASTIE_SHFT)
#define NASTIE_HMR             (1 << NASTIE_SHFT)
#define NASTIE_HPO             (2 << NASTIE_SHFT)
#define NASTIE_OST             (3 << NASTIE_SHFT)
#define NASTIE_PIG             (4 << NASTIE_SHFT)
#define NASTIE_SMI             (5 << NASTIE_SHFT)
#define NASTIE_TEH             (6 << NASTIE_SHFT)


#define SP_COL_SHFT             8

#define SP_COL_MSK             (7 << SP_COL_SHFT) //3bit

#define SP_COL_GR              (0 << SP_COL_SHFT)
#define SP_COL_R               (1 << SP_COL_SHFT)
#define SP_COL_BL              (2 << SP_COL_SHFT)
#define SP_COL_PI              (3 << SP_COL_SHFT)
#define SP_COL_YL              (4 << SP_COL_SHFT)
#define SP_COL_WT              (5 << SP_COL_SHFT)

#define GOODIE                  0x0003

#define GOOD_TYP_SHFT           4
#define GOOD_TYP_MSK           (0x3F << GOOD_TYP_SHFT) //5bit
#define GD_GET_INDEX(good)     ( ( GOOD_TYP_MSK & good) >> GOOD_TYP_SHFT )

#define GDi_SILVC              (0 << GOOD_TYP_SHFT)
#define GDi_ARROW              (1 << GOOD_TYP_SHFT)
#define GDi_CLK3h              (2 << GOOD_TYP_SHFT)
#define GDi_CLK6h              (3 << GOOD_TYP_SHFT)
#define GDi_CLK9h              (4 << GOOD_TYP_SHFT)
#define GDi_CLK12h             (5 << GOOD_TYP_SHFT)
#define GDi_GLASS              (6 << GOOD_TYP_SHFT)
#define GDi_SHLD               (7 << GOOD_TYP_SHFT)
#define GDi_BOOT               (8 << GOOD_TYP_SHFT)
#define GDi_THNBALL            (9 << GOOD_TYP_SHFT)
#define GDi_RDKEY              (10 << GOOD_TYP_SHFT)
#define GDi_BLKEY              (11 << GOOD_TYP_SHFT)
#define GDi_RDDOOR             (12 << GOOD_TYP_SHFT)
#define GDi_BLDOOR             (13 << GOOD_TYP_SHFT)
#define GDi_RDDOOR_open        (14 << GOOD_TYP_SHFT)
#define GDi_BLDOOR_open        (15 << GOOD_TYP_SHFT)
#define GDi_KNGOOD             (16 << GOOD_TYP_SHFT) //Separates PAL_SYS0 goodies from PAL_SYS1
#define GDi_GOLDC              (17 << GOOD_TYP_SHFT)
#define GDi_1UP                (18 << GOOD_TYP_SHFT)
#define GDi_2x                 (19 << GOOD_TYP_SHFT)
#define GDi_3x                 (20 << GOOD_TYP_SHFT)
#define GDi_4x                 (21 << GOOD_TYP_SHFT)
#define GDi_5x                 (22 << GOOD_TYP_SHFT)
#define GDi_BALL               (23 << GOOD_TYP_SHFT)
#define GDi_GEM                (24 << GOOD_TYP_SHFT)
#define GDi_GOLD               (25 << GOOD_TYP_SHFT)
#define GDi_TURTL              (26 << GOOD_TYP_SHFT)
#define GDi_STAR               (27 << GOOD_TYP_SHFT)
#define GDi_GRKEY              (28 << GOOD_TYP_SHFT)
#define GDi_GRDOOR             (29 << GOOD_TYP_SHFT)
#define GDi_GRDOOR_open        (30 << GOOD_TYP_SHFT)

#define  BP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_BLUE )
#define  GP ( NORMAL_BLOCK | SOLID | BREAKABLE | BLK_PLAYER | PL_GREEN )


#define TRI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_R )
#define TGI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_GR )
#define TBI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_BL )
#define TNI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_PI )
#define TYI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_YL )
#define TWI ( SPECIAL_BLOCK | SP_TRANS | TRANS_IN | SP_COL_WT )

#define TRO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_R )
#define TGO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_GR )
#define TBO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_BL )
#define TNO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_PI )
#define TYO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_YL )
#define TWO ( SPECIAL_BLOCK | SP_TRANS | TRANS_OUT | SP_COL_WT )

#define FRI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_R )
#define FGI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_GR )
#define FBI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_BL )
#define FNI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_PI )
#define FYI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_YL )
#define FWI ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_ON | FLOP_ACT_ON | SP_COL_WT )

#define FRO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_R )
#define FGO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_GR )
#define FBO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_BL )
#define FNO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_PI )
#define FYO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_YL )
#define FWO ( SPECIAL_BLOCK | SP_FLOP | FLOP_TOG_OFF | FLOP_ACT_ON | SP_COL_WT )

#define GRI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_R )
#define GGI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_GR )
#define GBI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_BL )
#define GNI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_PI )
#define GYI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_YL )
#define GWI ( SPECIAL_BLOCK | SP_GATE | GATE_OPEN | SP_COL_WT )
#define GRO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_R )
#define GGO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_GR )
#define GBO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_BL )
#define GNO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_PI )
#define GYO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_YL )
#define GWO ( SPECIAL_BLOCK | SP_GATE | GATE_CLOSED | SOLID | SP_COL_WT )

#define CNR ( SPECIAL_BLOCK | SP_CANNON | CANNON_R | SOLID )
#define CNL ( SPECIAL_BLOCK | SP_CANNON | CANNON_L | SOLID )

#define CHI (NORMAL_BLOCK | SOLID | BLK_CHISEL)
#define QUE (NORMAL_BLOCK | SOLID | BREAKABLE | BLK_QUESTION)
#define KNI (GOODIE | GDi_KNGOOD)

#define ANT (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_ANT)
#define HMR (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_HMR)
#define HPO (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_HPO)
#define OST (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_OST)
#define PIG (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_PIG)
#define SMI (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_SMI)
#define TEH (SPECIAL_BLOCK | SP_SPAWNER | NASTIE_TEH)

#define RDK (GOODIE | GDi_RDKEY)
#define RDD (GOODIE | GDi_RDDOOR)
#define SLC (GOODIE | GDi_SILVC)
#define GLC (GOODIE | GDi_GOLDC)
#define GLD (GOODIE | GDi_GOLD)
#define GEM (GOODIE | GDi_GEM)
#define UP1 (GOODIE | GDi_1UP)
#define ARR (GOODIE | GDi_ARROW)
#define BAL (GOODIE | GDi_BALL)
#define C3H (GOODIE | GDi_CLK3h)
#define C6H (GOODIE | GDi_CLK6h)
#define C9H (GOODIE | GDi_CLK9h)
#define C0H (GOODIE | GDi_CLK12h)
#define M2X (GOODIE | GDi_2x )
#define M3X (GOODIE | GDi_3x )
#define M4X (GOODIE | GDi_4x )
#define M5X (GOODIE | GDi_5x )
#define GLS (GOODIE | GDi_GLASS)
#define THN (GOODIE | GDi_THNBALL)
#define TUR (GOODIE | GDi_TURTL)
#define SHL (GOODIE | GDi_SHLD)
#define BOO (GOODIE | GDi_BOOT)

void BLK_drawBlock(u8 x, u8 y, u16 block);
void BLK_eraseBlock(u8 x, u8 y);
void BLK_eraseBlock_ind(u8 ind);
void BLK_load_tiles(u16 ind);

#endif