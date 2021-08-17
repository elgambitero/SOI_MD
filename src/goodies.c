#include "SOI.h"

#include "sound.h"
#include "sprites.h"

void GD_obtain();

void GD_update();

void GD_points_SILV();
const Entity GD_silvCoin = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            500,
            snd_silver_coin,
            sizeof(snd_silver_coin),
            &GD_obtain,
            &GD_points_SILV
        }
    }
};

void GD_give_arrow();
const Entity GD_arrow = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_arrow,
            sizeof(snd_arrow),
            &GD_obtain,
            &GD_give_arrow
        }
    }
};

void GD_clk3h_pickup();
const Entity GD_clk3h = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            &GD_clk3h_pickup
        }
    }
};

void GD_clk6h_pickup();
const Entity GD_clk6h = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            &GD_clk6h_pickup
        }
    }
};

void GD_clk9h_pickup();
const Entity GD_clk9h = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            &GD_clk9h_pickup
        }
    }
};

void GD_clk12h_pickup();
const Entity GD_clk12h = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_clock,
            sizeof(snd_clock),
            &GD_obtain,
            &GD_clk12h_pickup
        }
    }
};

void GD_reveal_hidden();
const Entity GD_glass = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_glass,
            sizeof(snd_glass),
            &GD_obtain,
            &GD_reveal_hidden
        }
    }
};

void GD_protectPlayer();
const Entity GD_shield = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_shield,
            sizeof(snd_shield),
            &GD_obtain,
            &GD_protectPlayer
        }
    }
};

void GD_speedUpPlayer();
const Entity GD_boot = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_boot,
            sizeof(snd_boot),
            &GD_obtain,
            &GD_speedUpPlayer
        }
    }
};

void GD_killAll();
void GD_killSpawned();
const Entity GD_thnball = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_thunderball,
            sizeof(snd_thunderball),
            &GD_obtain,
            &GD_killSpawned
        }
    }
};

void GD_openRdDoor();
const Entity GD_rdkey = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            &GD_openRdDoor
        }
    }
};

const Entity GD_blkey = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_rddoor = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

const Entity GD_bldoor = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

void GD_enterRdDoor();
const Entity GD_rddoor_open = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            &GD_enterRdDoor,
            NULL
        }
    }
};

const Entity GD_bddoor_open = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS0,
    &gd_sys0_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            NULL,
            NULL
        }
    }
};

void GD_points_GOLDC();
const Entity GD_goldCoin = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_gold_coin,
            sizeof(snd_gold_coin),
            &GD_obtain,
            &GD_points_GOLDC
        }
    }
};

void GD_give_1UP();
const Entity GD_1UP = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_1up,
            sizeof(snd_1up),
            &GD_obtain,
            GD_give_1UP
        }
    }
};

void GD_give_2x();
const Entity GD_2x = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            &GD_give_2x
        }
    }
};

void GD_give_3x();
const Entity GD_3x = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            &GD_give_3x
        }
    }
};

void GD_give_4x();
const Entity GD_4x = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            &GD_give_4x
        }
    }
};

void GD_give_5x();
const Entity GD_5x = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_multiplier,
            sizeof(snd_multiplier),
            &GD_obtain,
            &GD_give_5x
        }
    }
};

void GD_give_ball();
const Entity GD_ball = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_ball,
            sizeof(snd_ball),
            &GD_obtain,
            &GD_give_ball
        }
    }
};

void GD_points_GEM();
const Entity GD_gem = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_gem,
            sizeof(snd_gem),
            &GD_obtain,
            &GD_points_GEM
        }
    }
};

void GD_points_GOLD();
const Entity GD_gold = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_goldbar,
            sizeof(snd_goldbar),
            &GD_obtain,
            &GD_points_GOLD
        }
    }
};

void GD_slowDownMonsters();
const Entity GD_turtl = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_turtle,
            sizeof(snd_turtle),
            &GD_obtain,
            &GD_slowDownMonsters
        }
    }
};

const Entity GD_star = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            0,
            0,
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_grkey = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_key,
            sizeof(snd_key),
            &GD_obtain,
            NULL
        }
    }
};

const Entity GD_grdoor = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            0,
            0,
            NULL,
            NULL
        }
    }
};

const Entity GD_grdoor_open = {
    GOODY,
    {7, 15},
    {7, 15},
    PAL_SYS1,
    &gd_sys1_spr,
    NULL,
    &GD_update,
    NULL,
    {.goodie =
        {
            0,
            snd_door_exit,
            sizeof(snd_door_exit),
            NULL,
            NULL
        }
    }
};





const Entity * const goodies_vector[] = {
    &GD_silvCoin,
    &GD_arrow,
    &GD_clk3h,
    &GD_clk6h,
    &GD_clk9h,
    &GD_clk12h,
    &GD_glass,
    &GD_shield,
    &GD_boot,
    &GD_thnball,
    &GD_rdkey,
    &GD_blkey,
    &GD_rddoor,
    &GD_bldoor,
    &GD_rddoor_open,
    &GD_bddoor_open,
    &GD_goldCoin,
    &GD_goldCoin,
    &GD_1UP,
    &GD_2x,
    &GD_3x,
    &GD_4x,
    &GD_5x,
    &GD_ball,
    &GD_gem,
    &GD_gold,
    &GD_turtl,
    &GD_star,
    &GD_grkey,
    &GD_grdoor,
    &GD_grdoor_open,
};


void GD_reveal_hidden(){
    Actor * act;
    fx.status = 0;
    fx.frames = 0;
    fx.timer = 0;
    fx.character = &FX_hidden;
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    for(u8 i = 0; i<BOARD_BUFFER; i++){
        if((env->back_blocks[i] & GOODIE) == GOODIE){
            fx.pos[X] = BLOCK_TO_PX(IND_TO_X(i)) + 8;
            fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(i)) + 8;
            ACT_add(&fx, &fx_buf);
        }
    }
    SPR_update();
    stop_time(REVEAL_TIME);
    act = ACT_getFirst(&fx_buf);
    if(act){
        Actor * next;
        do{
            next = act->next;
            if(!ACT_remove(act, &fx_buf)) SYS_die("NOT EMPTYING LIST");
            act = next;
        }while(next);
    }
}

void GD_obtain(){
    fx.status = 0;
    //FIX ME: Usage of center_ind here creates referencing errors.
    fx.pos[X] = BLOCK_TO_PX(IND_TO_X(center_ind)) + 8;
    fx.pos[Y] = BLOCK_TO_PX(IND_TO_Y(center_ind)) + 8;
    fx.frames = 0;
    fx.timer = 0;
    fx.character = goodies_vector[gd_index];
    fx.speed[X] = 0;
    fx.speed[Y] = -BRK_SPEED;
    Actor * result = ACT_add(&fx, &fx_buf);
    if(result){
        if(gd_index >= GD_GET_INDEX( GDi_KNGOOD ) ) gd_index -= (GD_GET_INDEX( GDi_KNGOOD ) + 1);
        SPR_setFrame(result->sprite, gd_index);
    }
    set_block(env, 0, center_ind);
    eraseBlock_ind(center_ind);
}

void GD_killAll(){
    Actor * nastie = ACT_getFirst(&nasties);
    while(nastie){
        kill(nastie, 0, -2*FALLSPEED);
        nastie = nastie->next;
    }
}

void GD_killSpawned(){
    Actor * nastie = ACT_getFirst(&nasties);
    while(nastie){
        if((nastie->character->attr & ENT_CHECK_BITMSK) == NASTIE){ //Why check this???
            if(nastie->timer) kill(nastie, 0, -2*FALLSPEED);
        }
        nastie = nastie->next;
    }
}

void GD_openRdDoor(){
    u16 index = seek_block(env, (GOODIE | GDi_RDDOOR) );
    if(index != BOARD_NOTFOUND){
        set_block(env, (GOODIE | GDi_RDDOOR_open), index);
    }else{
        //this crashes the game on purpose
        SYS_die("Red Door not found");
    }
}

void GD_enterRdDoor(){
    curr->character->role.player.statistics->effect = PASSING;
    if(curr == blue_player) blue_player = NULL;
    if(curr == green_player) green_player = NULL;
    result = ACT_DELETION;
    return;
}

void GD_speedUpPlayer(){
    if(pl_stat->effect == SPEEDUP){
        //Seeks for the player's indicator and restarts it's timer.
        Actor * prev = ACT_seek(&FX_shield_ind, &fx_buf);
        while(prev){
            if(prev->actorData.fxData.following == curr){
                prev->timer = (MAX_FRAMES - SHIELD_FRAMES);
                return;
            }
            prev = ACT_seek_from(&FX_shield_ind, prev);
        }
        return;
    }
    pl_stat->speed = PL_FASTSPEED;
    pl_stat->effect = SPEEDUP;
    fx.status = 0;
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.timer = (MAX_FRAMES - SPEED_FRAMES);
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    fx.character = &FX_boot_ind;
    fx.actorData.fxData.following = curr;
    ACT_add(&fx, &fx_buf);
}

void GD_protectPlayer(){
    if(pl_stat->effect == SHIELDED){
        //Seeks for the player's indicator and restarts it's timer.
        Actor * prev = ACT_seek(&FX_shield_ind, &fx_buf);
        while(prev){
            if(prev->actorData.fxData.following == curr){
                prev->timer = (MAX_FRAMES - SHIELD_FRAMES);
                return;
            }
            prev = ACT_seek_from(&FX_shield_ind, prev);
        }
        return;
    }
    pl_stat->effect = SHIELDED;
    fx.status = 0;
    fx.pos[X] = POS_TO_PX(curr->pos[X]);
    fx.pos[Y] = POS_TO_PX(curr->pos[Y]);
    fx.timer = (MAX_FRAMES - SHIELD_FRAMES);
    fx.speed[X] = 0;
    fx.speed[Y] = 0;
    fx.character = &FX_shield_ind;
    fx.actorData.fxData.following = curr;
    ACT_add(&fx, &fx_buf);
}

void GD_slowDownMonsters(){
    nasties.effects |= SLOW_MSK;
    projectiles.effects |= SLOW_MSK;
    fx.status = 0;
    fx.pos[X] = 0;
    fx.pos[Y] = 0;
    fx.timer = (MAX_FRAMES - TURTLE_FRAMES);
    fx.speed[0] = 0;
    fx.speed[Y] = 0;
    fx.character = &FX_turtle;
    ACT_add(&fx, &fx_buf);
    return;
}

void GD_update(){
    if(curr->pos[X] >= PX_TO_POS(BOARD_X_PX) || curr->pos[Y] >= PX_TO_POS(BOARD_Y_PX) ){
        result = ACT_DELETION;
    }
    curr->speed[Y] += GRAVITY;
}

void GD_clk3h_pickup(){
    if(GAM_gameType == COOPERATE){
        if(bl_stat->bonus <= 1000){
            XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
        }
        bl_stat->bonus += 2000;
        gr_stat->bonus += 2000;
    }else{
        //only current player
    }
}

void GD_clk6h_pickup(){
    if(GAM_gameType == COOPERATE){
        if(bl_stat->bonus <= 1000){
            XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
        }
        bl_stat->bonus += 4000;
        gr_stat->bonus += 4000;
    }else{
        //only current player
    }
}

void GD_clk9h_pickup(){
    if(GAM_gameType == COOPERATE){
        if(bl_stat->bonus <= 1000){
            XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
        }
        bl_stat->bonus += 6000;
        gr_stat->bonus += 6000;
    }else{
        //only current player
    }
}

void GD_clk12h_pickup(){
    if(GAM_gameType == COOPERATE){
        if(bl_stat->bonus <= 1000){
            XGM_setMusicTempo(3 * XGM_getMusicTempo() / 4);
        }
        bl_stat->bonus += 8000;
        gr_stat->bonus += 8000;
    }else{
        //only current player
    }
}

void GD_points_SILV(){
    if(GAM_gameType == COOPERATE){
        bl_stats.score += 500;
        GAM_updateScore();
    }
}

void GD_points_GOLDC(){
    if(GAM_gameType == COOPERATE){
        bl_stats.score += 1000;
        GAM_updateScore();
    }
}

void GD_points_GOLD(){
    if(GAM_gameType == COOPERATE){
        bl_stats.score += 2000;
        GAM_updateScore();
    }
}

void GD_points_GEM(){
    if(GAM_gameType == COOPERATE){
        bl_stats.score += 5000;
        GAM_updateScore();
    }
}


void GD_give_arrow(){
    bl_stats.arrows++;
}

void GD_give_ball(){
    bl_stats.balls++;
}

void GD_give_1UP(){
    bl_stats.lives++;
    GAM_updateLives();
}

void GD_give_2x(){
    if(GAM_gameType == COOPERATE){
        bl_stats.mult = 2;
    }
}

void GD_give_3x(){
    if(GAM_gameType == COOPERATE){
        bl_stats.mult = 3;
    }
}

void GD_give_4x(){
    if(GAM_gameType == COOPERATE){
        bl_stats.mult = 4;
    }
}

void GD_give_5x(){
    if(GAM_gameType == COOPERATE){
        bl_stats.mult = 5;
    }
}