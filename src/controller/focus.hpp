#ifndef FOCUS_HPP
#define FOCUS_HPP

#include "button.hpp"

class Menu;

// Focus occupies button inputs and controls Menu.
class Focus {
  HardwareButton left, right, confirm;
  Menu *target = nullptr;

public:
  Focus(HardwareButton left, HardwareButton right, HardwareButton confirm)
      : left(left), right(right), confirm(confirm) {}

  void update(u8 elapsed);

  void set_target(Menu &menu) { target = &menu; }
};

#endif // FOCUS_HPP
