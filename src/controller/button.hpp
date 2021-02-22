#ifndef HARDWARE_BUTTON_HPP
#define HARDWARE_BUTTON_HPP

#include "../general.hpp"
#include "../timer.hpp"

#include <xc.h>

constexpr u8 IGNORE_DURATION = 200;

// HardwareButton manages port input state with delaying to prevent from
// chattering.
class HardwareButton {
  u8 _port;
  u8 _ignore_count = 0;

public:
  HardwareButton(u16 port) : _port(port) { TRISB |= 1 << port; }

  void update(u8 elapsed) {
    if (_ignore_count) {
      _ignore_count = (_ignore_count < elapsed) ? 0 : (_ignore_count - elapsed);
      return;
    }
    if (HAS_MASK(PORTA, _port)) {
      _ignore_count = IGNORE_DURATION;
    }
  }

  bool is_pressed() const { return _ignore_count != 0; }
};

#endif // HARDWARE_BUTTON_HPP
