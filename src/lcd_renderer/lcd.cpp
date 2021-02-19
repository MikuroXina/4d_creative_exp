#include "frame.hpp"

#include <xc.h>

constexpr u8 TEX_HALF_WIDTH = 64, TEX_HEIGHT = 64;

/*
  Port:     RA4   RB4   RB5    ...     RB8 - RB15
  Signal: | CS1 | CS2 | D/I | R/W | E | D0 - D7 |
 */

void end_to_send() {
  LATBbits.LATB7 = 1;
  LATBbits.LATB7 = 0;
  busy_wait(100);
  LATBbits.LATB7 = 1;
  busy_wait(100);
}

void send_lcd_grid(u8 grid, u8 row) {
  LATBCLR = ((u16)0xff) << 8;
  LATBbits.LATB5 = 0; // Instruction mode
  LATBSET = ((u16)0b1000000 | (row & 0b111111)) << 8;
  end_to_send();

  LATBbits.LATB5 = 1; // Data mode
  LATBCLR = ((u16)0xff) << 8;
  LATBSET = ((u16)grid) << 8;
  end_to_send();
}

void send_lcd_line(u8 line[TEX_HALF_WIDTH], u8 column) {
  // Set the column
  LATBCLR = ((u16)0xff) << 8;
  LATBbits.LATB5 = 0; // Instruction mode
  LATBSET = (u16)(0b10111000 | (column & 0b111)) << 8;
  end_to_send();

  // Init the row to 0
  LATBCLR = ((u16)0xff) << 8;
  LATBSET = ((u16)0b1000000) << 8;
  end_to_send();

  for (u8 row{0}; row != TEX_HALF_WIDTH; ++row) {
    send_lcd_grid(line[row], row);
  }
}

void convert_format(u8 src[1024], u8 line_column, u8 page, u8 dst[64]) {
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
    auto const index = grid_row / 8 + line_column * 128 + (page ? 8 : 0);
    u8 bits = 0;
    for (u8 grid_col{0}; grid_col != 8; ++grid_col) {
      if (src[index + grid_col * 16] & 1 << (7 - grid_row % 8)) {
        bits |= 1 << grid_col;
      }
    }
    dst[grid_row] |= bits;
  }
}

Frame::Frame() : texture(1024, 0xaa) { // 128x64 = 1024x8
  assert(1024 == texture.size());

  LATBbits.LATB5 = 0; // Instruction mode
  LATBbits.LATB6 = 0; // Write mode
  LATBbits.LATB7 = 0; // Turn Enable low

  busy_wait(600000);

  for (u8 i = 0; i != 2; ++i) {
    if (i == 0) {
      LATAbits.LATA4 = 1;
      LATBbits.LATB4 = 0;
    } else {
      LATAbits.LATA4 = 0;
      LATBbits.LATB4 = 1;
    }

    // Reset display start line
    LATBCLR = ((u16)0xff) << 8;
    LATBSET = ((u16)0b11000000) << 8;
    end_to_send();

    // Turn LCD on
    LATBCLR = ((u16)0xff) << 8;
    LATBSET = ((u16)0b111111) << 8;
    end_to_send();
  }
}

void Frame::send_lcd() {
  std::vector<u8> line(TEX_HALF_WIDTH);
  for (u8 page{0}; page != 2; ++page) {
    if (page == 0) {
      // Select left page
      LATAbits.LATA4 = 1;
      LATBbits.LATB4 = 0;
    } else {
      // Select right page
      LATAbits.LATA4 = 0;
      LATBbits.LATB4 = 1;
    }
    for (u8 line_column{0}; line_column != 8; ++line_column) {
      //      if (!HAS_MASK(needs_flush[page], 1 << line_column)) {
      //        continue;
      //      }
      convert_format(texture.data(), line_column, page, line.data());
      send_lcd_line(line.data(), line_column);
    }
  }
}
