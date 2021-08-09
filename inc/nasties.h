#ifndef NASTIES_H
#define NASTIES_H

#define BS_BIRTH 0
#define BS_IDLE  1
#define BS_ATTK  2

#define GL_BIRTH_FRAMES 16 * 4
#define GL_IDLE_FRAMES 16 * 4 * 3 //2 cycles
#define GL_ATTK_FRAMES 41 * 4

#define KN_BIRTH_FRAMES 16 * 4
#define KN_IDLE_FRAMES 16 * 4 * 3 //2 cycles
#define KN_ATTK_FRAMES 48 * 4

extern const Entity NST_spinner;
extern const Entity NST_robo;
extern const Entity NST_ant;
extern const Entity NST_piggy;
extern const Entity NST_teeth;

extern const Entity BS_gargoyle;
extern const Entity BS_knight;

#endif