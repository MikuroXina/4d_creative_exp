#ifndef LCD_HPP
#define LCD_HPP

#include "./frame.hpp"

class OutputPort;

inline void send_lcd_grid(u8 grid, OutputPort &lcd, u8 row) {}

inline void send_lcd_line(u8 line[64], OutputPort &lcd, u8 column,
                          bool is_right_page) {}

inline void send_lcd(Frame const &tex, OutputPort &lcd) {
  /*
    Texture format:
    0 | 00000000 11111111 22222222 ... 77777777
    1 | 00000000 11111111 22222222 ... 77777777
    :
    :
    7 | 00000000 11111111 22222222 ... 77777777

    Line format:
    0 1 2 ... 62 63
    0 1 2 ... 62 63
    : :
    : :
    0 1 2 ... 62 63
  */
  constexpr u8 TEX_WIDTH = 128, TEX_HEIGHT = 64;
  for (u8 page{0}; page != 2; ++page) {
    for (u8 line_column{0}; line_column != 8; ++line_column) {
      if (!HAS_MASK(tex.needs_flush[page], 1 << line_column)) {
        continue;
      }
      u8 line[64] = {};
      for (u8 grid_column{0}; grid_column != 8; ++grid_column) {
        for (u8 row{7}; row != 0; --row) {
          auto const column = line_column * 8 + grid_column;
          line[row] |= tex.texture[column * TEX_WIDTH] & (1 << row);
        }
      }
      send_lcd_line(line, lcd, line_column, page);
    }
  }
}

#endif // LCD_HPP
