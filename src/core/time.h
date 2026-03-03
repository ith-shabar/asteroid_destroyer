#ifndef TIME_H
#define TIME_H

#ifdef __cplusplus
extern "C" {
#endif

#define FPS 60
#define FRAME_TICKS 1000/FPS

#include <stdint.h>

float deltaTime();
void updateTime();

void setFPS(uint64_t start_frame);

#ifdef __cplusplus
}
#endif

#endif
