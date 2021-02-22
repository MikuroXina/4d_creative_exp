#ifndef SOFTWARE_BUTTON_HPP
#define SOFTWARE_BUTTON_HPP

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
  SoftwareButton(KatakanaString text);

  void write(Frame &tex) const;
};

#endif // SOFTWARE_BUTTON_HPP
