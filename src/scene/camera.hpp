#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../game/pone.hpp"
#include "../general.hpp"
#include "./camera_focus.hpp"

Size const SCREEN_SIZE = Size{128, 64};

class Camera {
public:
  Pos pos;
  CameraFocus focus;

  Camera(Pone &first_player) : pos(4, 4), focus(first_player) {}

  void move_to_focus();
  void write(Texture &tex) const;
};

#endif // CAMERA_HPP
