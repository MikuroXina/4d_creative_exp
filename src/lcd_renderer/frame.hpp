#ifndef FRAME_HPP
#define FRAME_HPP

#include "../general.hpp"

class OutputPort;

class Frame {
  u8 texture[1024] = {}; // 128x64 = 1024x8
  u8 needs_flush[2] =
      {}; // needs_flush[page] = 7 6 5 4 3 2 1 0 whether needed flush

public:
  friend void send_lcd(Frame const &tex, OutputPort &lcd);

  Frame() {}
};

#endif // FRAME_HPP
