#ifndef FRAME_HPP
#define FRAME_HPP

#include "../general.hpp"

class OutputPort;

class Frame {
  u8 texture[1024] = {};
  u8 needs_flush[2][8] = {};

public:
  friend void send_lcd(Frame const &tex, OutputPort &lcd);

  Frame() {}
};

#endif // FRAME_HPP
