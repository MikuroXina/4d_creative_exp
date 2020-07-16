#ifndef CAMERA_H
#define CAMERA_H

#include "../util/general.h"
#include "pone.h"

Size const SCREEN_SIZE = Size{128, 64};

typedef struct {
  Pos pos;
  Pone const *focused;
} Camera;

inline Camera newCamera() { return Camera{Pos{4, 4}, NULL}; }

#endif // CAMERA_H
