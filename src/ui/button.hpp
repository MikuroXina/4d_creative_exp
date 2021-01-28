#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>

#include "../general.hpp"
#include "../lcd_renderer/frame.hpp"
#include "./text.hpp"

// SoftwareButton is a Component.
// SoftwareButton owns a Text.
// SoftwareButton implements ButtonEventHandler and Scene recieves it.
class SoftwareButton {
  Text text;

public:
  SoftwareButton(std::string text);

  void write(Frame &tex) const;
};

#endif // BUTTON_HPP
