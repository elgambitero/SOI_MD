#ifndef LEVEL_INTRO_H
#define LEVEL_INTRO_H

#include "frame_state.h"

typedef struct level_intro_t
{
    const struct level_intro_vtable_ *vtable_;
}level_intro_t;

struct level_intro_vtable_
{
    const frame_t * (*begin)(const frame_t *);
};

static inline const frame_t * begin(
    level_intro_t * self,
    const frame_t * exit_callback
)
{
    return self->vtable_->begin(exit_callback);
}

extern const struct level_intro_vtable_ NORMAL_STAGE_T[]; 

#endif