#include <genesis.h>

#include "actors.h"
#include "physics.h"

#include "globals.h"

#define MAX_ACTORS 80

Actor * actorBank;
Actor * lastActor;
Actor * firstActor;
Actor **actorFree;
Actor **actorStack;

u8 ACT_init()
{
    actorBank = NULL;
    actorStack = NULL;
    actorBank = (Actor *) MEM_alloc(MAX_ACTORS * sizeof(Actor));
    actorStack = (Actor **) MEM_alloc(MAX_ACTORS);
    
    memset(actorBank, 0 , sizeof(Actor) * MAX_ACTORS);

    for(u8 i = 0; i < MAX_ACTORS; i++)
        actorStack[i] = &actorBank[i];

    actorFree = actorStack + MAX_ACTORS;

    lastActor = NULL;
    firstActor = NULL;
    return actorBank != NULL && actorStack != NULL;
}

Actor * ACT_add(Actor * actor)
{
    if(actorFree == actorStack){
        return NULL;
    }
    
    Actor * result = *--actorFree;
    if(lastActor) {
        lastActor->next = result;
    }
    if(!firstActor) firstActor = result;
    lastActor = result;

    memcpy(result, actor, sizeof(Actor));

    result->pos[X] = PX_TO_POS(result->pos[X]);
    result->pos[Y] = PX_TO_POS(result->pos[Y]);

    result->next = NULL;

    result->sprite =
        SPR_addSprite(result->character->sprite_def,
        POS_TO_PX(result->pos[0]) - SIZE_X(result->character->spr_pos) + BOARD_OFFSET_X, 
        POS_TO_PX(result->pos[1]) - SIZE_Y(result->character->spr_pos) + BOARD_OFFSET_Y,
        TILE_ATTR_FULL(result->character->palette,TRUE, FALSE, FALSE,TILE_USERINDEX));
    if(result) SPR_setAnim(result->sprite, result->status);
    return result;
}

u8 ACT_remove(Actor * actor)
{
    Actor * prev;

    prev = firstActor;
    if(prev == actor)
        firstActor = actor->next;
    else
        while(prev && prev->next != actor) prev = prev->next;

    if(prev){
        if(actor == lastActor) lastActor = prev;
        prev->next = actor->next;
        SPR_releaseSprite(actor->sprite);
        *actorFree++ = actor;
        return 1;
    }else{
        return 0;
    }
}

void ACT_end(){
    MEM_free(actorBank);
    actorBank = NULL;
    MEM_free(actorStack);
    actorStack = NULL;
    MEM_free(actorFree);
    actorFree = NULL;
    
}

Actor * ACT_seek(Entity * ent){
    Actor * result = firstActor;
    while(result){
        if(result->character == ent) break;
        result = result->next;
    }
    return result;
}

Actor * ACT_getFirst(){
    return firstActor;
}

void ACT_update(){
    Actor * current = firstActor;
    Actor * next = 0;
    while(current){
        u8 phy_result = PHY_computeStatus(current);

        current->pos[X] += current->speed[X];
        current->pos[Y] += current->speed[Y];

        SPR_setPosition(current->sprite,
            POS_TO_PX(current->pos[X]) - SIZE_X(current->character->spr_pos) + BOARD_OFFSET_X,
            POS_TO_PX(current->pos[Y]) - SIZE_Y(current->character->spr_pos) + BOARD_OFFSET_Y);
        next = current->next;
        switch(phy_result){
            case ACT_CHANGED:
                SPR_setAnim(current->sprite, current->status);
            break;
            case ACT_DELETION:
                ACT_remove(current);
            break;
        }
        current = next;
    }

    SPR_update();
}