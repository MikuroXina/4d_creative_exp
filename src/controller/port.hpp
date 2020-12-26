#ifndef PORT_HPP
#define PORT_HPP

#include "../general.hpp"

#include <xc.h>

template <u8 Field> struct PortA {
  static constexpr u8 field = Field;
  bool is_input;

  void set() const {
    if (is_input) {
      TRISA |= field;
    } else {
      TRISA &= ~field;
    }
  }
};

template <u8 Field> struct PortB {
  static constexpr u8 field = Field;
  bool is_input;

  void set() const {
    if (is_input) {
      TRISB |= field;
    } else {
      TRISB &= ~field;
    }
  }
};

#endif // PORT_HPP
