#ifndef TEXT_HPP
#define TEXT_HPP

#include "../lcd_renderer/texture.hpp"

class Text {
  std::string label;

public:
  Text(std::string label);

  void write(Texture &tex) const;
};

#endif // TEXT_HPP
