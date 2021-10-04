#include "SOI.h"

u8 ACT_init(ActorList * actors, u8 max_actors)
{
    actors->actorBank = NULL;
    actors->actorStack = NULL;
    actors->actorBank = (Actor *) MEM_alloc(max_actors * sizeof(Actor));
    actors->actorStack = (Actor **) MEM_alloc(max_actors * sizeof(Actor*));
    
    if(actors->actorBank == NULL || actors->actorStack == NULL)
        return NULL;

    memset(actors->actorBank, 0 , sizeof(Actor) * max_actors);

    for(u8 i = 0; i < max_actors; i++)
        actors->actorStack[i] = &(actors->actorBank[i]);

    actors->actorFree = actors->actorStack + max_actors;

    actors->lastActor = NULL;
    actors->firstActor = NULL;
    return actors->actorBank != NULL && actors->actorStack != NULL;
}

Actor * ACT_add(Actor * actor, ActorList * actors)
{
    if(actors->actorFree == actors->actorStack){
        return NULL;
    }
    
    Actor * result = *--(actors->actorFree);
    if(actors->lastActor) {
        actors->lastActor->next = result;
    }
    if(!(actors->firstActor)) actors->firstActor = result;
    actors->lastActor = result;

    memcpy(result, actor, sizeof(Actor));

    result->pos[X] = PX_TO_POS(result->pos[X]);
    result->pos[Y] = PX_TO_POS(result->pos[Y]);

    result->next = NULL;

    if(result->character->sprite_def){
        result->sprite =
        SPR_addSprite(result->character->sprite_def,
        POS_TO_PX(result->pos[0]) - result->character->spr_pos[X] + BOARD_OFFSET_X, 
        POS_TO_PX(result->pos[1]) - result->character->spr_pos[Y] + BOARD_OFFSET_Y,
        TILE_ATTR_FULL(result->character->palette,TRUE, FALSE, FALSE,TILE_USERINDEX));
        
    }else{
        result->sprite = NULL;
    }
    if(result->sprite) SPR_setAnim(result->sprite, result->status);
    if(result->character->onCreate) result->character->onCreate();
    return result;
}

u8 ACT_remove(Actor * actor, ActorList * actors)
{
    if(actor->character->onDestroy) actor->character->onDestroy();
    Actor * prev;

    prev = actors->firstActor;
    if(prev == actor)
        actors->firstActor = actor->next;
    else
        while(prev && prev->next != actor) prev = prev->next;

    if(prev){
        if(actor == actors->lastActor) actors->lastActor = prev;
        prev->next = actor->next;
        if(actor->sprite) SPR_releaseSprite(actor->sprite);
        *(actors->actorFree)++ = actor;
        return 1;
    }else{
        return 0;
    }
}

void ACT_end(ActorList * actors){
    Actor * current = ACT_getFirst(actors);
    //Maybe unnecessary, but it wears off some effects.
    while(current){
        ACT_remove(current, actors);
        current = current->next;
    }
    MEM_free(actors->actorBank);
    actors->actorBank = NULL;
    MEM_free(actors->actorStack);
    actors->actorStack = NULL;
    //MEM_free(actors->actorFree); //why is this commented??
    actors->actorFree = NULL;
}

Actor * ACT_seek(const Entity * ent, ActorList * actors){
    Actor * result = actors->firstActor;
    while(result){
        if(result->character == ent) break;
        result = result->next;
    }
    return result;
}

Actor * ACT_seek_from(const Entity * ent, Actor * act){
    Actor * result = act;
    while(result){
        if(result->character == ent) break;
        result = result->next;
    }
    return result;
}

u8 ACT_collision(Actor * act1, Actor * act2){
    if((act1->status & ANIM_MSK) == DEAD || (act2->status & ANIM_MSK) == DEAD)
        return FALSE;
    if(act1->pos[Y] < act2->pos[Y] - PX_TO_POS(act2->character->size[Y]) ||
        act2->pos[Y] < act1->pos[Y] - PX_TO_POS(act1->character->size[Y]))
        return FALSE;
    if(act1->pos[X] + PX_TO_POS(act1->character->size[X]) < act2->pos[X] - PX_TO_POS(act2->character->size[X]) ||
        act2->pos[X] + PX_TO_POS(act2->character->size[X]) < act1->pos[X] - PX_TO_POS(act1->character->size[X]))
        return FALSE;
    return TRUE;
}

Actor * ACT_getFirst(ActorList * actors){
    return actors->firstActor;
}

void ACT_update(ActorList * actors){
    Actor * current = actors->firstActor;
    Actor * next = 0;
    u8 phy_result;
    while(current){
        if(!(actors->effects & ~ACTOR_CLK)){
            phy_result  = PHY_computeStatus(current);
            current->pos[X] += current->speed[X];
            current->pos[Y] += current->speed[Y];
            if(current->sprite) SPR_setPosition(current->sprite,
                POS_TO_PX(current->pos[X]) - current->character->spr_pos[X] + BOARD_OFFSET_X,
                POS_TO_PX(current->pos[Y]) - current->character->spr_pos[Y] + BOARD_OFFSET_Y);
        }else{
            //Needs refactor if we need some other ActorList wide effect.
            if(actors->effects & FROZEN_MSK){
                if(current->sprite){
                    if(current->sprite->timer & ACTOR_CLK) current->sprite->timer++;
                }
                next = current->next;
                current = next;
                continue;
            }
            if(actors->effects & SLOW_MSK){

                phy_result  = PHY_computeStatus(current);
                current->pos[X] += (current->speed[X] >> 1);
                current->pos[Y] += (current->speed[Y] >> 1);
                if(current->frames && actors->effects & ACTOR_CLK) current->frames++;
                if(current->sprite){ SPR_setPosition(current->sprite,
                    POS_TO_PX(current->pos[X]) - current->character->spr_pos[X] + BOARD_OFFSET_X,
                    POS_TO_PX(current->pos[Y]) - current->character->spr_pos[Y] + BOARD_OFFSET_Y);
                    if(actors->effects & ACTOR_CLK) current->sprite->timer++;}
            }
        }

        
        switch(phy_result){
            case ACT_CHANGED:
                if(current->sprite) SPR_setAnim(current->sprite, current->status);
            break;
            case ACT_DELETION:
                ACT_remove(current, actors);
            break;
        }

        next = current->next;
        current = next;
    }
    if(actors->effects & ACTOR_CLK) actors->effects &= ~ACTOR_CLK;
    else actors->effects |= ACTOR_CLK;

}

void ACT_freeze(ActorList * actors){
    actors->effects |= FROZEN_MSK;
}

void ACT_unfreeze(ActorList * actors){
    actors->effects &= ~FROZEN_MSK;
}


void ACT_collide_lists(ActorList * winning, ActorList * losing, void (*action)(Actor * a, Actor * b)){
    Actor * act1 = ACT_getFirst(winning);
    while(act1){
        Actor * act2 = ACT_getFirst(losing);
        while(act2){
            if(ACT_collision(act1, act2)){
                if(action){
                    (*action)(act1, act2);
                }
            }
            act2 = act2->next;
        }
        act1 = act1->next;
    }
}

u8 ACT_contains(Actor * actor, ActorList * actors){
    Actor * a = actors->firstActor;
    while(a){
        if(a == actor)
            return 1;
        a = a->next;
    }
    return 0;
}