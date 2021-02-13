#ifndef FRAME_HPP
#define FRAME_HPP

#include <assert.h>
#include <vector>

#include "../general.hpp"

// Frmes owns its texture and support rendering it.
class Frame {
  std::vector<u8> texture;
  u8 needs_flush[2] =
      {}; // needs_flush[page] = 7 6 5 4 3 2 1 0 whether needed flush

  u8 tex_idx(Pos pos) const { return (pos.y() * 128 + pos.x()) / 8; }

  void mark_needs_flush(Rect area) {
    auto const top = area.top() / 8, bottom = (area.bottom() + 7) / 8 % 8,
               left = area.left() / 64, right = (area.right() + 63) / 64 % 2;
    for (auto col = top; col != bottom; ++col) {
      for (auto row = left; row != right; ++row) {
        needs_flush[row] |= 1 << col;
      }
    }
  }

  void send_lcd();

public:
  Frame() : texture(1024) { // 128x64 = 1024x8
    assert(1024 == texture.size());
  }

  void flush() {
    send_lcd();
    needs_flush[0] = 0;
    needs_flush[1] = 0;
  }

  void clear_whole() { std::fill(texture.begin(), texture.end(), 0); }

  void clear(Rect rect) {
    mark_needs_flush(rect);
    auto const tl = rect.top_left(), br = rect.bottom_right() - Pos{1, 1};
    auto const size = rect.size();
    for (u8 col = 0; col != size.h(); ++col) {
      for (u8 row = 0; row != size.w(); ++row) {
        i8 const px_x = row + tl.x(), px_y = col + tl.y();
        if (px_x == tl.x() || px_x == br.x() || px_y == tl.y() ||
            px_y == br.y()) {
          u8 const idx = tex_idx(Pos{px_x, px_y});
          texture[idx] &= ~(1 << (15 - row));
        }
      }
    }
  }

  void draw_border(Rect rect) {
    mark_needs_flush(rect);
    auto const tl = rect.top_left(), br = rect.bottom_right() - Pos{1, 1};
    auto const size = rect.size();
    for (u8 col = 0; col != size.h(); ++col) {
      for (u8 row = 0; row != size.w(); ++row) {
        i8 const px_x = row + tl.x(), px_y = col + tl.y();
        if (px_x == tl.x() || px_x == br.x() || px_y == tl.y() ||
            px_y == br.y()) {
          u8 const idx = tex_idx(Pos{px_x, px_y});
          texture[idx] ^= 1 << (15 - row);
        }
      }
    }
  }

  void draw16x16(u16 const src[16], Pos pos) {
    i8 const x = pos.x(), y = pos.y();
    mark_needs_flush(Rect{
        Pos{x, y},
        Size{16, 16},
    });
    for (u8 col = 0; col != 16; ++col) {
      u16 const src_bits = src[col];
      for (u8 row = 0; row != 16; ++row) {
        i8 px_x = row + x, px_y = col + y;
        if (0 <= px_x && px_x < 128 && 0 <= px_y && px_y < 64) {
          u8 const idx = tex_idx(Pos{px_x, px_y});
          texture[idx] ^= src_bits & 1 << (15 - row);
        }
      }
    }
  }
};

#endif // FRAME_HPP
