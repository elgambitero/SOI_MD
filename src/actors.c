#include <genesis.h>

#include "actors.h"

#define MAX_ACTORS 25

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
    if(lastActor) lastActor->next = result;
    result->next = NULL;

    memcpy(result, actor, sizeof(Actor));

    result->sprite = MEM_alloc(sizeof(Sprite));
    result->sprite =
        SPR_addSprite(result->character->sprite_def,
        result->pos[0], result->pos[1],
        TILE_ATTR_FULL(result->character->palette,TRUE, FALSE, FALSE,TILE_USERINDEX));

    VDP_setPalette(result->character->palette, result->character->sprite_def->palette->data); //SHOULD BE DONE ELSEWHERE
    return result;
}

u8 ACT_remove(Actor * actor)
{
    Actor * prev;

    *actorFree++ = actor;

    prev = firstActor;
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
    SPR_update();
}