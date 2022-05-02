#ifndef LEVEL_INTRO_H
#define LEVEL_INTRO_H

//VRAM offset for images
#define IMAGE_OFFSET 128

#include "frame_state.h"

typedef struct cutscene_t
{
    const struct cutscene_vtable_ *vtable_;
}cutscene_t;

typedef const frame_t * (*cutscene_cb)();

struct cutscene_vtable_
{
    const frame_t * (*begin)( cutscene_cb );
};

static inline const frame_t * CTS_play(
    cutscene_t * self,
    cutscene_cb exit_callback
)
{
    return self->vtable_->begin(exit_callback);
}

extern const struct cutscene_vtable_ NORMAL_STAGE_T[], BONUS_STAGE_T[], TITLE_SCREEN_T[];

#endif