#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

#include "./button.hpp"
#include "./text.hpp"

// Menu is a Component.
// Menu has Button as selection items.
// Menu has Text, the title.
class Menu {
  Text title;
  std::vector<Button> buttons;

public:
  Menu(std::string title, std::initializer_list<std::string> options);

  Button &button(u32 index) { return buttons.at(index); }
  u32 buttons_count() const { return buttons.size(); }

  void write(Texture &tex) const;
};

#endif // MENU_HPP
