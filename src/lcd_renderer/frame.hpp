#ifndef FRAME_HPP
#define FRAME_HPP

#include "../general.hpp"

class OutputPort;

class Frame {
  u8 texture[1024] = {}; // 128x64 = 1024x8
  u8 needs_flush[2] =
      {}; // needs_flush[page] = 7 6 5 4 3 2 1 0 whether needed flush

  u8 tex_idx(Pos pos) const { return (pos.y() * 128 + pos.x()) / 8; }

  void mark_needs_flush(Rect area) {
    auto const top = area.top() / 8, bottom = (area.bottom() + 7) / 8 % 8,
               left = area.left() / 64, right = (area.right() + 63) / 64 % 2;
    for (auto col{top}; col != bottom; ++col) {
      for (auto row{left}; row != right; ++row) {
        needs_flush[row] |= 1 << col;
      }
    }
  }

public:
  friend void send_lcd(Frame const &tex, OutputPort &lcd);

  Frame() {}

  void flush(OutputPort &lcd) {
    send_lcd(*this, lcd);
    needs_flush[0] = 0;
    needs_flush[1] = 0;
  }

  void draw16x16(u16 src[16], Pos pos) {
    i8 const x = pos.x(), y = pos.y();
    mark_needs_flush(Rect{
        Pos{x, y},
        Size{16, 16},
    });
    for (u8 col{0}; col != 16; ++col) {
      u16 const src_bits = src[col];
      for (u8 row{0}; row != 16; ++row) {
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
