#ifndef PROJECTILE_H
#define PROJECTILE_H

#define PR_R_RIGHT     0
#define PR_R_DOWN      1
#define PR_R_LEFT      2
#define PR_R_UP        3

#define PR_L_LEFT      0
#define PR_L_DOWN      1
#define PR_L_RIGHT     2
#define PR_L_UP        3

#define BALL_SPEED     2 * WALKSPEED
#define BALL_TIME      600

#define WALKP_SPEED    2 * WALKSPEED

extern const Entity PR_arrow;
extern const Entity PR_cannonball;
extern const Entity PR_simple;
extern const Entity PR_ultrabuster;
extern const Entity PR_spawner;
extern const Entity PR_packet;
extern const Entity PR_R_ball;
extern const Entity PR_L_ball;
extern const Entity PR_walkp;

#endif