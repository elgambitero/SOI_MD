#ifndef PLAYER_H

#define PLAYER_H

#include <genesis.h>

typedef struct Player{
    u8 size[2];
    u8 spr_pos[2];
    u8 palette;

    const SpriteDefinition * sprite_def;
    const u8 * death_sound;
    const u16 death_sound_size;

    void (*const onWalkInto)(u8);
    void (*const onTurnInto)(u8);
    void (*const onJumpInto)(u8);
    void (*const onFall)();
    void (*const onFallLands)();
    void (*const onJumpLands)();

    //void (*const onTurnAround)();
    //void (*const onStartWalking)();
    //void (*const onStartTurnAround);
    //void (*const onStopWalking)();

    void (*const onMakeBlock)();
    void (*const onDeleteBlock)();
    void (*const onMakeLowBlock)();
    void (*const onDeleteLowBlock)();
    void (*const onShoot)();
    void (*const onHeadBonk)();

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