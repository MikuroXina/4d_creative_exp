#ifndef TEXT_HPP
#define TEXT_HPP

#include "../lcd_renderer/frame.hpp"
#include "./text/align.hpp"
#include "./text/glyph.hpp"

#include <string>

using KatakanaString = std::basic_string<Katakana>;

// Text is a Component and renders by Glyph data.
// Text has TextAlign.
class Text {
  KatakanaString _label;
  Pos _pos;
  TextAlign _align;

public:
  Text(KatakanaString label, Pos pos, TextAlign align)
      : _label(label), _pos(pos), _align(align) {}

  void write(Frame &tex) const {
    u8 x = _pos.x(), y = _pos.y();
    u16 buf[16];
    for (auto const character : _label) {
      Glyph::katakana(character).write(buf);
      tex.draw16x16(buf, Pos{x, y});
      x += 16;
      if (128 < x) {
        x = _pos.x();
        y += 16;
      }
    }
  }
};

#endif // TEXT_HPP
