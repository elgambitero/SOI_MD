
#include "SOI.h"

#include "sound.h"

u8 channel = 0;
u16 pcm_channel[3] = {
    SOUND_PCM_CH2,
    SOUND_PCM_CH3,
    SOUND_PCM_CH4
};

void SFX_playSound(u8 id){
    switch(id){
        case snd_1up_ID:
            XGM_setPCM(SFX_IND + channel, snd_1up, sizeof(snd_1up));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_arrow_ID:
            XGM_setPCM(SFX_IND + channel, snd_arrow, sizeof(snd_arrow));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_ball_ID:
            XGM_setPCM(SFX_IND + channel, snd_ball, sizeof(snd_ball));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_boot_ID:
            XGM_setPCM(SFX_IND + channel, snd_boot, sizeof(snd_boot));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_clock_ID:
            XGM_setPCM(SFX_IND + channel, snd_clock, sizeof(snd_clock));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_door_exit_ID:
            XGM_setPCM(SFX_IND + channel, snd_door_exit, sizeof(snd_door_exit));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_gem_ID:
            XGM_setPCM(SFX_IND + channel, snd_gem, sizeof(snd_gem));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_glass_ID:
            XGM_setPCM(SFX_IND + channel, snd_glass, sizeof(snd_glass));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_goldbar_ID:
            XGM_setPCM(SFX_IND + channel, snd_goldbar, sizeof(snd_goldbar));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_gold_coin_ID:
            XGM_setPCM(SFX_IND + channel, snd_gold_coin, sizeof(snd_gold_coin));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_key_ID:
            XGM_setPCM(SFX_IND + channel, snd_key, sizeof(snd_key));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_multiplier_ID:
            XGM_setPCM(SFX_IND + channel, snd_multiplier, sizeof(snd_multiplier));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_shield_ID:
            XGM_setPCM(SFX_IND + channel, snd_shield, sizeof(snd_shield));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_silver_coin_ID:
            XGM_setPCM(SFX_IND + channel, snd_silver_coin, sizeof(snd_silver_coin));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_thunderball_ID:
            XGM_setPCM(SFX_IND + channel, snd_thunderball, sizeof(snd_thunderball));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_turtle_ID:
            XGM_setPCM(SFX_IND + channel, snd_turtle, sizeof(snd_turtle));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_beanie_ID:
            XGM_setPCM(SFX_IND + channel, snd_beanie, sizeof(snd_beanie));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_ant_ID:
            XGM_setPCM(SFX_IND + channel, snd_ant, sizeof(snd_ant));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_hippo_ID:
            XGM_setPCM(SFX_IND + channel, snd_hippo, sizeof(snd_hippo));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_piggy_ID:
            XGM_setPCM(SFX_IND + channel, snd_piggy, sizeof(snd_piggy));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_robo_ID:
            XGM_setPCM(SFX_IND + channel, snd_robo, sizeof(snd_robo));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_player_death_ID:
            XGM_setPCM(SFX_IND + channel, snd_player_death, sizeof(snd_player_death));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_smiley_ID:
            XGM_setPCM(SFX_IND + channel, snd_smiley, sizeof(snd_smiley));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_teeth_ID:
            XGM_setPCM(SFX_IND + channel, snd_teeth, sizeof(snd_teeth));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_hammer_ID:
            XGM_setPCM(SFX_IND + channel, snd_hammer, sizeof(snd_hammer));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_wheelie_ID:
            XGM_setPCM(SFX_IND + channel, snd_wheelie, sizeof(snd_wheelie));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_ostrich_ID:
            XGM_setPCM(SFX_IND + channel, snd_ostrich, sizeof(snd_ostrich));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_walker_ID:
            XGM_setPCM(SFX_IND + channel, snd_walker, sizeof(snd_walker));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_arrow_fire_ID:
            XGM_setPCM(SFX_IND + channel, snd_arrow_fire, sizeof(snd_arrow_fire));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_ball_fire_ID:
            XGM_setPCM(SFX_IND + channel, snd_ball_fire, sizeof(snd_ball_fire));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_beanie_fire_ID:
            XGM_setPCM(SFX_IND + channel, snd_beanie_fire, sizeof(snd_beanie_fire));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_block_break_ID:
            XGM_setPCM(SFX_IND + channel, snd_block_break, sizeof(snd_block_break));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_block_crack_ID:
            XGM_setPCM(SFX_IND + channel, snd_block_crack, sizeof(snd_block_crack));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_block_create_ID:
            XGM_setPCM(SFX_IND + channel, snd_block_create, sizeof(snd_block_create));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_block_delete_ID:
            XGM_setPCM(SFX_IND + channel, snd_block_delete, sizeof(snd_block_delete));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_cannon_fire_ID:
            XGM_setPCM(SFX_IND + channel, snd_cannon_fire, sizeof(snd_cannon_fire));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_one_ID:
            XGM_setPCM(SFX_IND + channel, snd_one, sizeof(snd_one));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_two_ID:
            XGM_setPCM(SFX_IND + channel, snd_two, sizeof(snd_two));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_three_ID:
            XGM_setPCM(SFX_IND + channel, snd_three, sizeof(snd_three));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_four_ID:
            XGM_setPCM(SFX_IND + channel, snd_four, sizeof(snd_four));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_five_ID:
            XGM_setPCM(SFX_IND + channel, snd_five, sizeof(snd_five));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_gargoyle_fire_ID:
            XGM_setPCM(SFX_IND + channel, snd_gargoyle_fire, sizeof(snd_gargoyle_fire));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_hait_ID:
            XGM_setPCM(SFX_IND + channel, snd_hait, sizeof(snd_hait));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_huoh_ID:
            XGM_setPCM(SFX_IND + channel, snd_huoh, sizeof(snd_huoh));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_hurry_up_ID:
            XGM_setPCM(SFX_IND + channel, snd_hurry_up, sizeof(snd_hurry_up));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_metal_bonk_ID:
            XGM_setPCM(SFX_IND + channel, snd_metal_bonk, sizeof(snd_metal_bonk));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_switch_ID:
            XGM_setPCM(SFX_IND + channel, snd_switch, sizeof(snd_switch));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_teleport_ID:
            XGM_setPCM(SFX_IND + channel, snd_teleport, sizeof(snd_teleport));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_bonus_nothing_ID:
            XGM_setPCM(SFX_IND + channel, snd_bonus_nothing, sizeof(snd_bonus_nothing));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        case snd_bonus_start_ID:
            XGM_setPCM(SFX_IND + channel, snd_bonus_start, sizeof(snd_bonus_start));
            XGM_startPlayPCM(SFX_IND + channel, 0, pcm_channel[channel]);
            channel++;
            channel = channel % 3;
            break;
        default:
            break;
    }
}