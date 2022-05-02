#include "cutscene.h"

static const frame_t * begin(
    cutscene_cb exit_callback
)
{
    return (*exit_callback)();
}

const struct cutscene_vtable_ NORMAL_STAGE_T[] = { {&begin} };