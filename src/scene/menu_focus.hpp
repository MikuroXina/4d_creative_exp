#ifndef MENU_FOCUS_HPP
#define MENU_FOCUS_HPP

#include "../general.hpp"
#include "../ui/menu.hpp"

// MenuFocus navigates focusing by listening button-inputs.
class MenuFocus {
  Menu &menu;
  u8 current_button_index;

public:
  MenuFocus(Menu &menu) : menu(menu) {}

  void next_button() {
    ++current_button_index;
    if (current_button_index == menu.buttons_count()) {
      current_button_index = 0;
    }
  }
  void prev_button() {
    --current_button_index;
    if (current_button_index == 255) {
      current_button_index = menu.buttons_count() - 1;
    }
  }
  u8 current_button_idx() const { return current_button_index; }

  void press();
  void blur();
};

#endif // MENU_FOCUS_HPP
