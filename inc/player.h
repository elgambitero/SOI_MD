#ifndef PLAYER_H

#define PLAYER_H

typedef struct Player{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;
    u16 points;

    const SpriteDefinition * sprite_def;
    const u8 * death_sound;
    const u16 death_sound_size;

    void (*const onWalkInto)();
    void (*const onJumpInto)();
    void (*const onFall)();
    void (*const onStartWalking)();
    void (*const onStopWalking)();

    void (*const onAttack)();

    u8 (*const onBlockCtrl)(u8);
    u8 (*const onWeapCtrl)(u8);
    u8 (*const onJumpCtrl)(u8);

    u32 score;
    u8 arrows;
    u8 balls;
    u8 lives;
}Player;

typedef struct PlayerStat{
    u32 score;
    u8 arrows;
    u8 balls;
    u8 lives;
}PlayerStat;

#endif