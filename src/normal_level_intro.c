#include "cutscene.h"

static const frame_t * begin(
    level_intro_cb exit_callback
)
{
    return (*exit_callback)();
}

const struct level_intro_vtable_ NORMAL_STAGE_T[] = { {&begin} };