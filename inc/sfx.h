#ifndef SFX_H
#define SFX_H

#define SFX_IND 5 //magic number

typedef enum {
    snd_1up_ID = 1,
    snd_arrow_ID = 2,
    snd_ball_ID = 3,
    snd_boot_ID = 4,
    snd_clock_ID = 5,
    snd_door_exit_ID = 6,
    snd_gem_ID = 7,
    snd_glass_ID = 8,
    snd_goldbar_ID = 9,
    snd_gold_coin_ID = 10,
    snd_key_ID = 11,
    snd_multiplier_ID = 12,
    snd_shield_ID = 13,
    snd_silver_coin_ID = 14,
    snd_thunderball_ID = 15,
    snd_turtle_ID = 16,
    snd_beanie_ID = 17,
    snd_ant_ID = 18,
    snd_hippo_ID = 19,
    snd_piggy_ID = 20,
    snd_robo_ID = 21,
    snd_player_death_ID = 22,
    snd_smiley_ID = 23,
    snd_teeth_ID = 24,
    snd_hammer_ID = 25,
    snd_wheelie_ID = 26,
    snd_ostrich_ID = 27,
    snd_walker_ID = 28,
    snd_arrow_fire_ID = 29,
    snd_ball_fire_ID = 30,
    snd_beanie_fire_ID = 31,
    snd_block_break_ID = 32,
    snd_block_crack_ID = 33,
    snd_block_create_ID = 34,
    snd_block_delete_ID = 35,
    snd_cannon_fire_ID = 36,
    snd_one_ID = 37,
    snd_two_ID = 38,
    snd_three_ID = 39,
    snd_four_ID = 40,
    snd_five_ID = 41,
    snd_gargoyle_fire_ID = 42,
    snd_hait_ID = 43,
    snd_huoh_ID = 44,
    snd_hurry_up_ID = 45,
    snd_metal_bonk_ID = 46,
    snd_switch_ID = 47,
    snd_teleport_ID = 48,
    snd_bonus_nothing_ID = 49,
    snd_bonus_start_ID = 50
}SFX_ind_t;

void SFX_playSound(SFX_ind_t id);

#endif