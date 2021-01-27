#ifndef LCD_HPP
#define LCD_HPP

#include "../general.hpp"
#include "./frame.hpp"

#include <xc.h>

class OutputPort;

inline void send_to_lcd() {
  LATBbits.RB6 = 1; // Send
  busy_wait(100);
  LATBbits.RB6 = 0;
}

inline void send_lcd_grid(u8 grid, OutputPort &lcd, u8 row) {
  LATBCLR = ((u16)0xff) << 8;
  LATBSET = grid << 8;
  send_to_lcd();
}

inline void send_lcd_line(u8 line[64], OutputPort &lcd, u8 column,
                          bool is_right_page) {
  // Set the column
  LATBCLR = reverse_bits((u16)0b111111);
  LATBbits.RB4 = 0; // Instruction mode
  const auto instruction = (0b10111000 | (column & 0b111)) << 8;
  LATBSET = instruction;
  send_to_lcd();

  // Init the row to 0
  LATBCLR = reverse_bits((u16)0b111111);
  LATBSET = 0b01000000 << 8;
  send_to_lcd();

  LATBbits.RB4 = 1; // Data mode
  for (u8 row{0}; row != 64; ++row) {
    send_lcd_grid(line[row], lcd, row);
  }
}

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
    if (page == 0) {
      // Select left page
      LATAbits.RA4 = 1;
      LATBbits.RB3 = 0;
    } else {
      // Select right page
      LATAbits.RA4 = 0;
      LATBbits.RB3 = 1;
    }
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
