#include "frame.hpp"

#include <xc.h>

constexpr u8 TEX_HALF_WIDTH = 64, TEX_HEIGHT = 64;

void send_to_lcd() {
  LATBbits.LATB6 = 1; // Send
  busy_wait(100);
  LATBbits.LATB6 = 0;
}

void send_lcd_grid(u8 grid, u8 row) {
  LATBCLR = ((u16)0xff) << 8;
  LATBSET = grid << 8;
  send_to_lcd();
}

void send_lcd_line(u8 line[64], u8 column) {
  // Set the column
  LATBCLR = reverse_bits((u16)0b111111);
  LATBbits.LATB4 = 0; // Instruction mode
  const auto instruction = (0b10111000 | (column & 0b111)) << 8;
  LATBSET = instruction;
  send_to_lcd();

  // Init the row to 0
  LATBCLR = reverse_bits((u16)0b111111);
  LATBSET = 0b01000000 << 8;
  send_to_lcd();

  LATBbits.LATB4 = 1; // Data mode
  for (u8 row{0}; row != 64; ++row) {
    send_lcd_grid(line[row], row);
  }
}

void convert_format(u8 src[1024], u8 column, u8 page, u8 dst[64]) {
  /*
    Texture(src) format:
    0 | 00000000 11111111 22222222 ... 77777777
    1 | 00000000 11111111 22222222 ... 77777777
    :
    :
    7 | 00000000 11111111 22222222 ... 77777777

    Line(dst) format:
    0 | 0 1 2 ... 62 63
    1 | 0 1 2 ... 62 63
    : | : :
    : | : :
    7 | 0 1 2 ... 62 63
  */
  for (u8 grid_row{0}; grid_row != 64; ++grid_row) {
    auto const index = column * 16 + grid_row / 8 + (page ? TEX_HALF_WIDTH : 0);
    auto const bits = src[index];
    dst[grid_row] |= bits & 1 << (7 - grid_row % 8);
  }
}

void Frame::send_lcd() {
  for (u8 page{0}; page != 2; ++page) {
    if (page == 0) {
      // Select left page
      LATAbits.LATA4 = 1;
      LATBbits.LATB3 = 0;
    } else {
      // Select right page
      LATAbits.LATA4 = 0;
      LATBbits.LATB3 = 1;
    }
    for (u8 line_column{0}; line_column != 8; ++line_column) {
      if (!HAS_MASK(needs_flush[page], 1 << line_column)) {
        continue;
      }
      std::vector<u8> line(64);
      convert_format(texture.data(), line_column, page, line.data());
      send_lcd_line(line.data(), line_column);
    }
  }
}
