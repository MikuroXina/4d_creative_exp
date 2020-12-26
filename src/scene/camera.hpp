#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../game/pone.hpp"
#include "../general.hpp"

Size const SCREEN_SIZE = Size{128, 64};

class Camera {
  Pos pos;
  Pone const *focused;

public:
  Camera() : pos(4, 4), focused(nullptr) {}
};

#endif // CAMERA_HPP
