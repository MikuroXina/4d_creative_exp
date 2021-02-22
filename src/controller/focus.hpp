#ifndef FOCUS_HPP
#define FOCUS_HPP

#include "../general.hpp"
#include "../ui/menu.hpp"
#include "button.hpp"

// Focus occupies button inputs and controls Menu.
class Focus {
  HardwareButton left, right, confirm;
  Menu *target = nullptr;
  u8 current_button_index = 0;

public:
  Focus() : left{0}, right{1}, confirm{2} {}

  static Focus &get();

  void run(Menu &menu);

  void next_button() {
    if (!target) {
      return;
    }
    ++current_button_index;
    if (current_button_index == target->buttons_count()) {
      current_button_index = 0;
    }
  }
  void prev_button() {
    if (!target) {
      return;
    }
    --current_button_index;
    if (current_button_index == 255) {
      current_button_index = target->buttons_count() - 1;
    }
  }
  u8 current_button_idx() const { return current_button_index; }
};

#endif // FOCUS_HPP
