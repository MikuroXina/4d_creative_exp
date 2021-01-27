#ifndef FRAME_HPP
#define FRAME_HPP

#include "../general.hpp"

class OutputPort;

class Frame {
  u8 texture[1024] = {}; // 128x64 = 1024x8
  u8 needs_flush[2] =
      {}; // needs_flush[page] = 7 6 5 4 3 2 1 0 whether needed flush

  void mark_needs_flush(Rect area) {
    auto const top = area.pos().y() / 8,
               bottom = (area.pos().y() + area.size().h() + 7) / 8 % 8,
               left = area.pos().x() / 64,
               right = (area.pos().x() + area.size().w() + 63) / 64 % 2;
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

  void draw16x16(u16 tex[16], Pos pos) {
    auto const x = pos.x(), y = pos.y();
    mark_needs_flush(Rect{
        Pos{x, y},
        Size{16, 16},
    });
    // TODO
  }
};

#endif // FRAME_HPP
