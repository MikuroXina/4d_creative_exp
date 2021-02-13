#include "camera.hpp"

#include "../game/piece.hpp"
#include "../lcd_renderer/frame.hpp"

void Camera::move_to_focus() {
  auto dst = focus.where_is_on().pos();
  // TODO: transite animation
  pos = dst;
}

void Camera::write(Frame &tex) const {
  // TODO: render Piece
  // TODO: render Board
}
