#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../game/piece.hpp"
#include "../general.hpp"
#include "../lcd_renderer/frame.hpp"
#include "./camera_focus.hpp"

Size constexpr SCREEN_SIZE = Size{128, 64};

// Camera renders around Piece into Frame.
class Camera {
public:
  Pos pos;
  CameraFocus focus;

  Camera(Piece &first_player) : pos(4, 4), focus(first_player) {}

  void move_to_focus();
  void write(Frame &tex) const;
};

#endif // CAMERA_HPP
