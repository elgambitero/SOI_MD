#ifndef STATES_H
#define STATES_H

enum MainStates{INTRO,
    MAIN_MENU,
    GAMEPLAY
    };

enum MainStates mainState;

typedef struct PlayerStat{
    u32 score;
    u8 arrows;
    u8 balls;
    u8 lives;
}PlayerStat;


#endif