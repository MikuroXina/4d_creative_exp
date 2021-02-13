#include "camera.hpp"

#include "../game/piece.hpp"
#include "../lcd_renderer/frame.hpp"

void Camera::move_to_focus() {
  auto dst = focus.where_is_on().pos();
  // TODO: transite animation
  pos = dst;
}

constexpr u16 piece_pixels[16] = {
    0b0000000000000000, //
    0b0000001111000000, //
    0b0000111111110000, //
    0b0001111111111000, //
    0b0000111111110000, //
    0b0000011111100000, //
    0b0000000110000000, //
    0b0000001111000000, //
    0b0000111111110000, //
    0b0000000110000000, //
    0b0000111111110000, //
    0b0000011111100000, //
    0b0001111111111000, //
    0b0111111111111110, //
    0b0011111111111100, //
    0b0000000000000000, //
};

void Camera::write(Frame &tex) const {
  _pieces.piece_for_each([this, &tex](Piece const &piece) {
    auto local_pos = piece.where_is_on().pos() - this->pos;
    if (!SCREEN.intersects({local_pos, {16, 16}})) {
      return;
    }
    tex.draw16x16(piece_pixels, local_pos);
  });
  // TODO: render Board
}
