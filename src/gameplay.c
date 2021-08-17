#include "SOI.h"

#include "palettes.h"
#include "stage.h"
#include "sound.h"

#define START_LEVEL 1

Board board;

u8 colors[4];
u16 ind;
u16 frmInd;

u8 bonusClk;
u16 bonusCount;
u32 scoreCount;

u16 levelInd = START_LEVEL;

u8 bonusText[N_BONUS + 1];
u8 scoreText[N_SCORE + 1];
u8 livesText[N_LIVES + 1];
u8 levelText[N_LEVEL + 1];


void GAM_gameInit();
void GAM_levelInit();
void GAM_drawFrame();
void VDP_drawNumber(u16 number, u8 chars, u8 xpos, u8 ypos);

__attribute__((always_inline)) static inline void GAM_updateBonus(){
    //ONLY FOR COOPERATE FOR NOW
    if(GAM_gameType == COOPERATE){
        bonusCount = bl_stats.bonus;
        if(bonusCount){
            bonusClk = !bonusClk;
            if(!bonusClk) return;
            bl_stats.bonus--;
            sprintf(bonusText, "%05d", bonusCount);
            VDP_drawText(bonusText, X_BONUS, 0);
            if(bonusCount == 1000){
                XGM_setPCM(SFX_IND, snd_hurry_up, sizeof(snd_hurry_up));
                XGM_startPlayPCM(SFX_IND, 0, SOUND_PCM_CH2);
                XGM_setMusicTempo(4 * XGM_getMusicTempo() / 3);
            }
        }else{
            if(blue_player && blue_player->status != DEAD) {
                kill(blue_player, 0, PL_JMP_BOOST);
                //blue_player = NULL;
            }
            if(green_player && green_player->status != DEAD) {
                kill(green_player, 0, PL_JMP_BOOST);
                //green_player = NULL;
            }
        }
    }
}

void gameplayLoop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();
            GAM_gameInit();

            gameState = INITBOARD;
            SYS_enableInts();
        break;
        case INITBOARD:
            SYS_disableInts();
            GAM_levelInit();

            gameState = GAME;
            SYS_enableInts();
        break;
        case GAME:
            GAM_updateBonus();
            PHY_send_inputs(bl_ctrl, gr_ctrl);
            PHY_update();
            SPR_update();
            if((!blue_player) && (!green_player)){
                XGM_stopPlay();
                if(bonusCount < 1000){
                    XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
                }
                PAL_fadeOut(0, 63, 60, FALSE);
                gameState = ENDBOARD;
            }
        break;
        case TRYAGAIN:
            gameState = INITBOARD;
        break;
        case ENDBOARD:
            PHY_end();
            BRD_unload(&board);
            //FIXME: THIS IS TERRIBLE
            if(bl_stat->effect == KILLED && gr_stat->effect == KILLED){
                if(GAM_gameType == COOPERATE){
                    if(bl_stats.lives < 0){
                        gameState = GAMEOVER;
                    }else{
                        gameState = TRYAGAIN;
                    }
                }
            }else{
                gameState = AFTERBOARD;
            }
            gr_stat->effect = 0;
            bl_stat->effect = 0;
        break;
        case AFTERBOARD:
            if(GAM_gameType == COOPERATE){
                bl_stats.score += bonusCount * bl_stats.mult;
            }
            gameState = NEXTBOARD;
        break;
        case NEXTBOARD:
            levelInd++;
            if(levelInd == max_levels)
            {
                gameState = GAMEENDING;
                break;
            }
            gameState = INITBOARD;
        break;
        case GAMEOVER:
            SPR_end();
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            XGM_stopPlay();
                if(bonusCount < 1000){
                    XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
                }
            PAL_setColor(15, 0x0FFF);
            VDP_drawTextBG(BG_A,"GAME OVER", 10, 10);
            gameState = GAMEEXIT;
            break;
        case GAMEENDING:
            //VDP_resetScreen();
            SPR_end();
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            XGM_stopPlay();
                if(bonusCount < 1000){
                    XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
                }
            PAL_setColor(15, 0x0FFF);
            VDP_drawTextBG(BG_A,"Thank you for playing", 5, 10);
            gameState = GAMEEXIT;
        break;
        case GAMEEXIT:
            /*
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            VDP_clearPlane(PLAN_WINDOW, TRUE);

            VDP_setHorizontalScroll(BG_A, 0);
            VDP_setHorizontalScroll(BG_B, 0);
            VDP_setVerticalScroll(BG_A, 0);
            VDP_setVerticalScroll(BG_B, 0);
            VDP_setBackgroundColor(0);

            gameState = GAMEINIT;
            mainState = MAIN_MENU;
            */
        break;
    }
}

void GAM_setStartingBoard(u8 lvl){
    levelInd = lvl;
}

void GAM_gameInit(){

    bl_stats.lives = 3;
    bl_stats.balls = 3;
    bl_stats.arrows = 3;
    bl_stats.mult = 1;
    bl_stats.score = 0;
    bl_stats.speed = PL_WALKSPEED;
    
    gr_stats.lives = 3;
    gr_stats.balls = 3;
    gr_stats.arrows = 3;
    gr_stats.mult = 1;
    gr_stats.score = 0;
    gr_stats.speed = PL_WALKSPEED;
}

void GAM_levelInit(){

    current_level = levels[levelInd];

    ind = TILE_USERINDEX;
    blue_player = NULL;
    green_player = NULL;
    bl_ctrl = 0;
    gr_ctrl = 0;
    
    VDP_setPalette(PAL0, pal_sys0.data);
    VDP_setPalette(PAL1, pal_sys1.data);

    GAM_drawFrame();

    BLK_load_tiles(ind);

    SPR_init();
    
    if(!PHY_init(&board, &bl_stats, &gr_stats)) {
        SYS_die("Error when initializing Physics");
    }
    
    if(!BRD_load(&board, current_level)) {
        SYS_die("Error when loading the Board");
    }

    blue_player = ACT_seek(&PL_blue, &players);
    green_player = ACT_seek(&PL_green, &players);

    if(JOY_getPortType(PORT_2) == PORT_TYPE_UNKNOWN){
        ACT_remove(green_player, &players);
        green_player = 0;
    }

    BRD_load_palettes(&board);
    BRD_draw(&board);
    BRD_play_music(&board);

    bl_stats.bonus = board.bonus;
    gr_stats.bonus = board.bonus;

    VDP_drawText("Score", 0, 0);
    VDP_drawText("Bonus", 15, 0);
    VDP_drawText("L:", 27, 0);
    VDP_drawText("Lvl", 32, 0);

    GAM_updateScore();
    GAM_updateLives();
    GAM_updateLevel();

}

void GAM_drawFrame(){
    VDP_loadTileSet(main_frame.tileset, ind, DMA);
    frmInd = ind;
    ind += main_frame.tileset->numTile;

    VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 0, 0, 0, 1, 1);

    VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 0, 3, 0, 1, 1);

    VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 27, 0, 3, 1, 1);

    VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 27, 3, 3, 1, 1);
    
    for(u8 i = 0; i < 19; i++){
        VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                1+i*2, 0, 1, 0, 2, 1);

        VDP_setMapEx(BG_B, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                1+i*2, 27, 1, 3, 2, 1);
    }

    for(u8 i = 0; i < 13; i++){
        VDP_setMapEx(BG_A, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                0, 1 + i*2, 0, 1, 1, 2);

        VDP_setMapEx(BG_A, main_frame.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, frmInd),
                39, 1 + i*2, 3, 1, 1, 2);
    }
}



void GAM_setGametype(u8 game_type){
    GAM_gameType = game_type;
}

void GAM_updateScore(){
    if(GAM_gameType == COOPERATE){
        scoreCount = bl_stats.score;
        sprintf(scoreText, "%08lu", scoreCount);
        VDP_drawText(scoreText, X_SCORE, 0);
    }
}

void GAM_updateLives(){
     if(GAM_gameType == COOPERATE){
        sprintf(livesText, "%d", bl_stats.lives);
        VDP_drawText(livesText, X_LIVES, 0);
    }
}

void GAM_updateLevel(){
    if(GAM_gameType == COOPERATE){
        sprintf(levelText, "%03d", levelInd);
        VDP_drawText(levelText, X_LEVEL, 0);
    }
}