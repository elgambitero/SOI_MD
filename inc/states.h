#ifndef STATES_H
#define STATES_H

#define PASSING  1
#define SHIELDED 2
#define SPEEDUP  3
#define KILLED   4

typedef struct PlayerStat{
    u32 score;
    u16 bonus;
    u8 mult;
    u8 arrows;
    u8 balls;
    s8 lives;
    u8 speed;
    u8 effect;
}PlayerStat;



#endif