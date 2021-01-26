#ifndef LCD_HPP
#define LCD_HPP

#include "./frame.hpp"

class OutputPort;

void render_lcd_grid(u8 bitmap, OutputPort &lcd, u8 row) {}

void render_lcd_line(u8 bitmaps[8][8], OutputPort &lcd, bool is_left_low) {}

void render_lcd(Frame tex, OutputPort &lcd) {}

#endif // LCD_HPP
