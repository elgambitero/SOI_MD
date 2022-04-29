#ifndef FRAME_STATE_H
#define FRAME_STATE_H

typedef struct frame_t{
    const struct frame_t * (*const calc_frame)();
}frame_t;

#endif
