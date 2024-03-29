#ifndef NASTIES_H
#define NASTIES_H

#define BS_BIRTH 0
#define BS_IDLE  1
#define BS_ATTK  2

#define SLO_SPEED    WALKSPEED/2
#define FAST_SPEED    WALKSPEED * 4

#define HMR_ATTK_IN_FRAMES 24
#define HMR_ATTK_OUT_FRAMES 8

#define GL_BIRTH_FRAMES 16 * 4
#define GL_IDLE_FRAMES 16 * 4 * 3 //2 cycles
#define GL_ATTK_FRAMES 41 * 4

#define GL_FIRE_HEIGHT 36
#define GL_PROJ_SPEED (4 << (DECIMALS-1))

#define KN_BIRTH_FRAMES 16 * 4
#define KN_IDLE_FRAMES 16 * 4 * 3 //2 cycles
#define KN_ATTK_FRAMES 48 * 4

#define NST_R_RIGHT     0
#define NST_R_DOWN      1
#define NST_R_LEFT      2
#define NST_R_UP        3

#define NST_L_LEFT      0
#define NST_L_DOWN      1
#define NST_L_RIGHT     2
#define NST_L_UP        3

//THESE NEED TO SUM 256!
#define KN_PROB_GDi_SILVC       72
#define KN_PROB_GDi_GOLDC       30
#define KN_PROB_GDi_GOLD        28
#define KN_PROB_GDi_GEM         24
#define KN_PROB_GDi_CLK6h       8
#define KN_PROB_GDi_CLK3h       8
#define KN_PROB_GDi_CLK9h       8
#define KN_PROB_GDi_CLK12h      8
#define KN_PROB_GDi_SHLD        8
#define KN_PROB_GDi_BOOT        8
#define KN_PROB_GDi_1UP         4
#define KN_PROB_GDi_2x          8
#define KN_PROB_GDi_3x          8
#define KN_PROB_GDi_4x          8
#define KN_PROB_GDi_5x          8
#define KN_PROB_GDi_BALL        8
#define KN_PROB_GDi_ARROW       8

#define NASTIE_SPEED WALKSPEED
#define WALKER_TIME 300

#define SMILEY_FRAMES 48
#define SMILEY_FRAMETIME 2

extern const Entity NST_spinner;
extern const Entity NST_robo;
extern const Entity NST_ant;
extern const Entity NST_piggy;
extern const Entity NST_teeth;
extern const Entity NST_whslowR;
extern const Entity NST_whfastR;
extern const Entity NST_whslowL;
extern const Entity NST_whfastL;
extern const Entity NST_beanie;
extern const Entity NST_ostrich;
extern const Entity NST_hippo;
extern const Entity NST_hammer;
extern const Entity NST_walker;
extern const Entity NST_smiley;

extern const Entity BS_gargoyle;
extern const Entity BS_knight;

#endif