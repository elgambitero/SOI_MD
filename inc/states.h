#ifndef STATES_H
#define STATES_H

#define SPEEDUP  1
#define SHIELDED 2
#define PASSING  3

typedef struct PlayerStat{
    u32 score;
    u8 arrows;
    u8 balls;
    u8 lives;
    u8 speed;
    u8 effect;
}PlayerStat;



#endif