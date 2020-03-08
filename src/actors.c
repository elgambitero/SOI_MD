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

    result->sprite = MEM_alloc(sizeof(Sprite));
    result->sprite =
        SPR_addSprite(result->character->sprite_def,
        //result->pos[0], result->pos[1],
        POS_TO_PX(result->pos[0]) - SIZE_X(result->character->spr_pos) + BOARD_OFFSET_X, 
        POS_TO_PX(result->pos[1]) - SIZE_Y(result->character->spr_pos) + BOARD_OFFSET_Y,
        TILE_ATTR_FULL(result->character->palette,TRUE, FALSE, FALSE,TILE_USERINDEX));
    return result;
}

u8 ACT_remove(Actor * actor)
{
    Actor * prev;

    *actorFree++ = actor;

    prev = firstActor;
    if(prev == actor)
        firstActor = actor->next;
    else
        while(prev && prev->next != actor) prev = prev->next;

    if(prev){
        prev->next = actor->next;
        SPR_releaseSprite(actor->sprite);
        MEM_free(actor->sprite);
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

Actor * ACT_getFirst(){
    return firstActor;
}

void ACT_update(){
    Actor * current = firstActor;
    while(current){
        u8 changed = PHY_computeStatus(current);

        current->pos[X] += current->speed[X];
        current->pos[Y] += current->speed[Y];

        SPR_setPosition(current->sprite,
            POS_TO_PX(current->pos[X]) - SIZE_X(current->character->spr_pos) + BOARD_OFFSET_X,
            POS_TO_PX(current->pos[Y]) - SIZE_Y(current->character->spr_pos) + BOARD_OFFSET_Y);
        if (changed) SPR_setAnim(current->sprite, current->status);
        current = current->next;
    }

    SPR_update();
}