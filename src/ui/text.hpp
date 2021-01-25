#ifndef TEXT_HPP
#define TEXT_HPP

#include "./text/align.hpp"

#include "../lcd_renderer/texture.hpp"

// Text is a Component and renders by Glyph data.
// Text has TextAlign.
class Text {
  std::string _label;
  TextAlign _align;

public:
  Text(std::string label, TextAlign align) : _label(label), _align(align) {}

  void write(Texture &tex) const;
};

#endif // TEXT_HPP
