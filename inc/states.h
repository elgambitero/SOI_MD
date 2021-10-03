#ifndef STATES_H
#define STATES_H

#define PASSING  1
#define SHIELDED 2
#define SPEEDUP  3
#define KILLED   4

enum MainStates{INTRO,
    TITLE_SCREEN_IN,
    TITLE_SCREEN,
    TITLE_SCREEN_OUT,
    MAIN_MENU,
    GAMEPLAY
    };
    
typedef struct PlayerStat{
    u32 score;
    u32 bonus;
    u8 mult;
    u8 arrows;
    u8 balls;
    s8 lives;
    u8 speed;
    u8 effect;
}PlayerStat;

typedef struct Pickups{
    u8 silv;
    u8 goldc;
    u8 gold;
    u8 gem;
    u8 lives;
    u8 balls;
    u8 arrows;
}Pickups;



#endif