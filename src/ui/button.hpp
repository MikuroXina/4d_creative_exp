#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>

#include "../general.hpp"
#include "../lcd_renderer/texture.hpp"
#include "./text.hpp"

// Button is a Component.
// Button owns a Text.
// Button implements ButtonEventHandler and Scene recieves it.
class Button {
  Text text;

public:
  Button(std::string text);

  void write(Texture &tex) const;
};

#endif // BUTTON_HPP
