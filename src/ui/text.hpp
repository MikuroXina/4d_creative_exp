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
  Pos _anchor;
  TextAlign _align;
  u8 height;

public:
  Text(KatakanaString label, Pos anchor = Pos::zero(),
       TextAlign align = TextAlign::Left)
      : _label(label), _anchor(anchor), _align(align) {

    for (auto const character : _label) {
      if (character == '\n') {
        height += 16;
      }
    }
  }

  Rect region() const { return Rect{_anchor, {124, height}}; }

  void write(Frame &tex) const {
    auto x = _anchor.x(), y = _anchor.y();
    std::vector<u16> buf(16);
    for (auto const character : _label) {
      Glyph::katakana(character).write(buf.data());
      tex.draw16x16(buf.data(), Pos{x, y});
      x += 16;
      if (128 < x || character == '\n') {
        x = _anchor.x();
        y += 16;
      }
    }
  }
};

#endif // TEXT_HPP
