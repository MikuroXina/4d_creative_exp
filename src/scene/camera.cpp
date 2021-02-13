#include "camera.hpp"

#include "../game/board.hpp"
#include "../game/piece.hpp"
#include "../lcd_renderer/frame.hpp"

void Camera::move_to_focus() {
  auto dst = focus.where_is_on().pos();
  // TODO: transite animation
  pos = dst;
}

constexpr u16 PIECE_PIXELS[16] = {
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

constexpr Size PIECE_SIZE{16, 16}, PANEL_SIZE{32, 32};

void Camera::write(Frame &tex) const {
  _pieces.piece_for_each([this, &tex](Piece const &piece) {
    auto local_pos = piece.where_is_on().pos() - this->pos;
    if (!SCREEN.intersects({local_pos, PIECE_SIZE})) {
      return;
    }
    tex.draw16x16(PIECE_PIXELS, local_pos);
  });
  auto const focus_panel_idx = focus.where_is_on().index();
  auto const board_size = _board.size();
  for (i8 offset = -4; offset != 5; ++offset) {
    auto const &panel =
        _board.at((focus_panel_idx + offset + board_size) % board_size);
    tex.draw_border({panel.pos(), PANEL_SIZE});
  }
}
