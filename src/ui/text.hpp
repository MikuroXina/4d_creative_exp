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
  TextAlign _align;

public:
  Text(KatakanaString label, TextAlign align) : _label(label), _align(align) {}

  void write(Frame &tex) const;
};

#endif // TEXT_HPP
