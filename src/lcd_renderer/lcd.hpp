#ifndef LCD_HPP
#define LCD_HPP

#include "./frame.hpp"

class OutputPort;

void send_lcd_grid(u8 bitmap, OutputPort &lcd, u8 row) {}

void send_lcd_line(u8 bitmaps[8][8], OutputPort &lcd, u8 column,
                   bool is_left_row) {}

void send_lcd(Frame const &tex, OutputPort &lcd) {}

#endif // LCD_HPP
