#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../general.hpp"
#include "./camera_focus.hpp"

Size constexpr SCREEN_SIZE = Size{128, 64};

class Frame;
class Piece;

// Camera renders around Piece into Frame.
class Camera {
public:
  Pos pos;
  CameraFocus focus;

  Camera(Piece const &first_player) : pos(4, 4), focus(first_player) {}

  void move_to_focus();
  void write(Frame &tex) const;
};

#endif // CAMERA_HPP
