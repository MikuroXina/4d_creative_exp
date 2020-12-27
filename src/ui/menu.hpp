#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

#include "./button.hpp"
#include "./text.hpp"

class Menu {
  Text title;
  std::vector<Button> buttons;
  u8 current_button_index;

public:
  Menu(std::string title, std::initializer_list<std::string> options);

  void next_button() {
    ++current_button_index;
    if (current_button_index == buttons.size()) {
      current_button_index = 0;
    }
  }
  void prev_button() {
    --current_button_index;
    if (current_button_index == 255) {
      current_button_index = buttons.size() - 1;
    }
  }
  u8 current_button_idx() const { return current_button_index; }

  void write(Texture &tex) const;
};

#endif // MENU_HPP
