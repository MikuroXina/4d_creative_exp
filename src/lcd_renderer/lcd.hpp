#ifndef LCD_HPP
#define LCD_HPP

#include "./texture.hpp"

class OutputPort;

class LcdGrid {
  u8 is_left_row : 1;
  u8 page : 3;

public:
  LcdGrid(u8 is_left_row, u8 column) : is_left_row(is_left_row), page(column) {}

  void render(u8 bitmap, OutputPort &lcd);
};

class Lcd {
  LcdGrid grids[16];

public:
  Lcd();

  void render(Texture tex, OutputPort &lcd);
};

#endif // LCD_HPP
