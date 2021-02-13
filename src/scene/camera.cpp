#include "camera.hpp"

void Camera::move_to_focus() {
  // TODO: transite animation
  pos = focus.focused_pos();
}

void Camera::write(Frame &tex) const {
  // TODO: render Piece
  // TODO: render Board
}
