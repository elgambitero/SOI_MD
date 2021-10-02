#include "SOI.h"

#include "palettes.h"
#include "stage.h"
#include "sound.h"
#include "images.h"

#define START_LEVEL 1
#define DEF_PLAYERS 0

Board board;

u8 colors[4];
u16 ind;
u16 frmInd;

u8 bonusClk;
u16 bonusCount;
u32 scoreCount;

typedef struct BonusGather{
    Pickups * bl_pick;
    Pickups * gr_pick;
}BonusGather;

BonusGather bonusData = {
    &bl_pick,
    &gr_pick
};

BonusGather * bonusGather;

const u16 channels[] = {
    SOUND_PCM_CH2,
    SOUND_PCM_CH3,
    SOUND_PCM_CH4
};

u16 paintSlots;
u8 soundSlot;

u16 levelInd = START_LEVEL;
u8 numPlayer = DEF_PLAYERS;

u8 bonusText[N_BONUS + 1];
u8 scoreText[N_SCORE + 1];
u8 livesText[N_LIVES + 1];
u8 levelText[N_LEVEL + 1];


void GAM_gameInit();
void GAM_levelInit();
void GAM_drawFrame();
void GAM_normalInter();
void GAM_bonusInter();
void GAM_normalInter_loop();
void GAM_bonusInter_loop(BonusGather * gather);
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
                SFX_playSound(snd_hurry_up_ID);
                XGM_setMusicTempo(4 * XGM_getMusicTempo() / 3);
            }
        }else{
            if(blue_player && blue_player->status != DEAD) {
                PHY_kill(blue_player, 0, PL_JMP_BOOST);
                //blue_player = NULL;
            }
            if(green_player && green_player->status != DEAD) {
                PHY_kill(green_player, 0, PL_JMP_BOOST);
                //green_player = NULL;
            }
        }
    }
}

void GAM_controls(u16 joy, u16 changed, u16 state){
    switch(joy){
        case JOY_1:
            if(blue_player){
                controls_3(&bl_ctrl, changed, state);
            }
        break;
        case JOY_2:
            if(green_player){
                controls_3(&gr_ctrl, changed, state);
            }
        break;
    }
}

void GAM_interControls(u16 joy, u16 changed, u16 state){
    if(changed & BUTTON_START){
        if(state & BUTTON_START){
            gameState = AFTERBOARD_OUT;
        }
    }
}

enum MainStates GAM_loop(){
    switch(gameState){
        case GAMEINIT:
            SYS_disableInts();
            GAM_gameInit();

            gameState = INITBOARD;
            SYS_enableInts();
            return GAMEPLAY;
        case INITBOARD:
            SYS_disableInts();
            GAM_levelInit();

            gameState = GAME;
            SYS_enableInts();
            return GAMEPLAY;
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
            return GAMEPLAY;
        case TRYAGAIN:
            gameState = INITBOARD;
            return GAMEPLAY;
        case ENDBOARD:
            PHY_end();
            SPR_end();
            BRD_unload(&board);
            //FIXME: THIS IS TERRIBLE
            if(bl_stat->effect == KILLED && gr_stat->effect == KILLED){
                if(GAM_gameType == COOPERATE){
                    if(bl_stats.lives + gr_stats.lives < 0){
                        gameState = GAMEOVER;
                    }else{
                        if(current_level->attributes & BONUS_FLAG){
                            gameState = AFTERBOARD_IN;
                            bonusGather = NULL;
                            VDP_clearPlane(BG_A, TRUE);
                            VDP_clearPlane(BG_B, TRUE);
                        }else{
                            gameState = TRYAGAIN;
                        }
                    }
                }
            }else{
                //Transitions to intermission.
                if(GAM_gameType == COOPERATE){
                    bl_stats.score += bonusCount * bl_stats.mult;
                }
                VDP_clearPlane(BG_A, TRUE);
                VDP_clearPlane(BG_B, TRUE);
                gameState = AFTERBOARD_IN;
            }
            gr_stat->effect = 0;
            bl_stat->effect = 0;
            return GAMEPLAY;
        case AFTERBOARD_IN:
            if(current_level->attributes & BONUS_FLAG){
                GAM_bonusInter(bonusGather);
            }else{
                GAM_normalInter();
            }
            gameState = AFTERBOARD;
            return GAMEPLAY;
        case AFTERBOARD:
            if(current_level->attributes & BONUS_FLAG){
                GAM_bonusInter_loop(bonusGather);
            }else{
                GAM_normalInter_loop();
            }
            return GAMEPLAY;
        case AFTERBOARD_OUT:
            VDP_fadeOut(0, 63, 20, FALSE);
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            gameState = NEXTBOARD;
            return GAMEPLAY;
        case NEXTBOARD:
            levelInd++;
            if(levelInd == max_levels)
            {
                gameState = GAMEENDING;
                return GAMEPLAY;
            }
            gameState = INITBOARD;
            return GAMEPLAY;
        case GAMEOVER:
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            XGM_stopPlay();
                if(bonusCount < 1000){
                    XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
                }
            PAL_setColor(15, 0x0FFF);
            VDP_drawTextBG(BG_A,"GAME OVER", 10, 10);
            gameState = GAMEEXIT;
            return GAMEPLAY;
        case GAMEENDING:
            //VDP_resetScreen();
            VDP_clearPlane(BG_A, TRUE);
            VDP_clearPlane(BG_B, TRUE);
            XGM_stopPlay();
                if(bonusCount < 1000){
                    XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
                }
            PAL_setColor(15, 0x0FFF);
            VDP_drawTextBG(BG_A,"Thank you for playing", 5, 10);
            gameState = GAMEEXIT;
            return GAMEPLAY;
        case GAMEEXIT:
            return GAMEPLAY;
    }
    return GAMEPLAY;
}

void GAM_setStartingBoard(u8 lvl){
    levelInd = lvl;
}

void GAM_setPlayers(u8 pl){
    numPlayer = pl;
}

void GAM_gameInit(){

    bl_stats.lives = 2;
    bl_stats.balls = 3;
    bl_stats.arrows = 3;
    bl_stats.mult = 1;
    bl_stats.score = 0;
    bl_stats.speed = PL_WALKSPEED;
    
    gr_stats.lives = 2;
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
    if(current_level->attributes & BONUS_FLAG){
        bonusGather = &bonusData;
        memset(&bl_pick, 0, sizeof(Pickups));
        memset(&gr_pick, 0, sizeof(Pickups));
    }else
        bonusGather = NULL;
    
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

    if(!numPlayer){
        ACT_remove(green_player, &players);
        green_player = 0;
        gr_stat->effect = KILLED;
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

    JOY_setEventHandler( &GAM_controls );

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
        scoreCount = bl_stats.score + gr_stats.score;
        sprintf(scoreText, "%08lu", scoreCount);
        VDP_drawText(scoreText, X_SCORE, 0);
    }
}

void GAM_updateLives(){
     if(GAM_gameType == COOPERATE){
        sprintf(livesText, "%d", bl_stats.lives + gr_stats.lives);
        VDP_drawText(livesText, X_LIVES, 0);
    }
}

void GAM_updateLevel(){
    if(GAM_gameType == COOPERATE){
        sprintf(levelText, "%03d", levelInd);
        VDP_drawText(levelText, X_LEVEL, 0);
    }
}

void GAM_normalInter(){
    VDP_setPaletteColors(32, (u16*) palette_black, 32);
    u16 palette[32];
    memcpy(&palette[0], brd_end_1_img.palette->data, 16 * 2);
    memcpy(&palette[16], brd_end_2_img.palette->data, 16 * 2);
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawImageEx(BG_A, &brd_end_1_img, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX), 0, 0, FALSE, TRUE);
    VDP_drawImageEx(BG_B, &brd_end_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + brd_end_1_img.tileset->numTile )), 0, 0, FALSE, TRUE);
    // fade in
    VDP_fadeIn(32, 63 , palette, 20, FALSE);
    JOY_setEventHandler( &GAM_interControls );
}

void GAM_bonusInter(BonusGather * stack){
    VDP_setPaletteColors(32, (u16*) palette_black, 32);
    u16 palette[32];
    memcpy(&palette[0], bns_end_1_img.palette->data, 16 * 2);
    memcpy(&palette[16], bns_end_2_img.palette->data, 16 * 2);
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);
    VDP_drawImageEx(BG_A, &bns_end_1_img, TILE_ATTR_FULL(PAL2, FALSE, FALSE, FALSE, TILE_USERINDEX + IMAGE_OFFSET), 0, 0, FALSE, TRUE);
    VDP_drawImageEx(BG_B, &bns_end_2_img, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, (TILE_USERINDEX + IMAGE_OFFSET + bns_end_1_img.tileset->numTile )), 0, 0, FALSE, TRUE);
    // fade in
    VDP_fadeIn(32, 63 , palette, 20, FALSE);
    if(!stack) {
        SFX_playSound(snd_bonus_nothing_ID);
    }else{
        bl_stat->score += SILVCPOINTS * stack->bl_pick->silv;
        bl_stat->score += GOLDCPOINTS * stack->bl_pick->goldc;
        bl_stat->score += GOLDPOINTS * stack->bl_pick->gold;
        bl_stat->score += GEMPOINTS * stack->bl_pick->gem;
        bl_stat->lives += stack->bl_pick->lives;
        bl_stat->balls += stack->bl_pick->balls;
        bl_stat->arrows += stack->bl_pick->arrows;

        gr_stat->score += SILVCPOINTS * stack->gr_pick->silv;
        gr_stat->score += GOLDCPOINTS * stack->gr_pick->goldc;
        gr_stat->score += GOLDPOINTS * stack->gr_pick->gold;
        gr_stat->score += GEMPOINTS * stack->gr_pick->gem;
        gr_stat->lives += stack->gr_pick->lives;
        gr_stat->balls += stack->gr_pick->balls;
        gr_stat->arrows += stack->gr_pick->arrows;
        
        VDP_setPalette(PAL0, pal_sys0.data);
        VDP_setPalette(PAL1, pal_sys1.data);

        soundSlot = 0;

        paintSlots = 0;
        
    }
    JOY_setEventHandler( &GAM_interControls );
}


void GAM_normalInter_loop(){

}


//This part of this code is horrible, but will work.

void GAM_waitFrames(u16 frames){
    for(u16 j = 0; j < frames; j++)
        VDP_waitVSync();
}

void GAM_silvcPaint(){
    SFX_playSound(snd_silver_coin_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        SLC);
        paintSlots++;
    }
}

void GAM_goldcPaint(){
    SFX_playSound(snd_gold_coin_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        GLC);
        paintSlots++;
    }
}

void GAM_goldPaint(){
    SFX_playSound(snd_goldbar_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        GLD);
        paintSlots++;
    }
}

void GAM_gemPaint(){
    SFX_playSound(snd_gem_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        GEM);
        paintSlots++;
    }
}

void GAM_livesPaint(){
    SFX_playSound(snd_1up_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        UP1);
        paintSlots++;
    }
}

void GAM_ballsPaint(){
    SFX_playSound(snd_ball_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        BAL);
                        
        paintSlots++;
    }
}

void GAM_arrowsPaint(){
    SFX_playSound(snd_arrow_ID);
    if(paintSlots < BNS_XSLOT * BNS_YSLOT){
        BLK_drawBlock(BNS_XSTART + paintSlots % BNS_XSLOT,
                        BNS_YSTART + paintSlots / BNS_XSLOT,
                        ARR);
        paintSlots++;
    }
}

void GAM_bonusInter_loop(BonusGather * gather){
    if(!gather)
        return;

    if(gather->bl_pick->silv){
        GAM_silvcPaint();
        gather->bl_pick->silv--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->silv){
        GAM_silvcPaint();
        gather->gr_pick->silv--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->bl_pick->goldc){
        GAM_goldcPaint();
        gather->bl_pick->goldc--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->goldc){
        GAM_goldcPaint();
        gather->gr_pick->goldc--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }


    if(gather->bl_pick->gold){
        GAM_goldPaint();
        gather->bl_pick->gold--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->gold){
        GAM_goldPaint();
        gather->gr_pick->gold--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }



    if(gather->bl_pick->gem){
        GAM_gemPaint();
        gather->bl_pick->gem--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->gem){
        GAM_gemPaint();
        gather->gr_pick->gem--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }



    if(gather->bl_pick->lives){
        GAM_livesPaint();
        gather->bl_pick->lives--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->lives){
        GAM_livesPaint();
        gather->gr_pick->lives--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->bl_pick->arrows){
        GAM_arrowsPaint();
        gather->bl_pick->arrows--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->arrows){
        GAM_arrowsPaint();
        gather->gr_pick->arrows--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }


    if(gather->bl_pick->balls){
        GAM_ballsPaint();
        gather->bl_pick->balls--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }

    if(gather->gr_pick->balls){
        GAM_ballsPaint();
        gather->gr_pick->balls--;
        GAM_waitFrames(COUNT_FRAMES); //ew
        return;
    }
}