#ifndef PLAYER_STATUS_H
#define PLAYER_STATUS_H

#define START_LIVES  3
#define START_BALLS  3
#define START_ARROWS 3
#define START_NOWEAP 1

typedef struct SOI_player_status_t{
    uint32_t score;
    uint32_t bonus;
    uint8_t mult;
    uint8_t arrows;
    uint8_t balls;
    int8_t lives;
    uint8_t speed;
    uint8_t effect;
    uint8_t noweap;
}SOI_player_status_t;

#endif