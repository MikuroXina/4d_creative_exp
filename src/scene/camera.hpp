#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../game/pone.hpp"
#include "../general.hpp"
#include "../lcd_renderer/frame.hpp"
#include "./camera_focus.hpp"

Size const SCREEN_SIZE = Size{128, 64};

// Camera renders around Pone into Frame.
class Camera {
public:
  Pos pos;
  CameraFocus focus;

  Camera(Pone &first_player) : pos(4, 4), focus(first_player) {}
  Camera(Camera &&) = default;
  Camera &operator=(Camera &&) { return *this; }

  void move_to_focus();
  void write(Frame &tex) const;
};

#endif // CAMERA_HPP
