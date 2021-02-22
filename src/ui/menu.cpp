#include "menu.hpp"

Menu::Menu(KatakanaString title, std::initializer_list<KatakanaString> options)
    : title{title}, buttons{} {
  u8 y = 16;
  for (auto const &option : options) {
    buttons.push_back(SoftwareButton{Text{option, Pos{0, y}}});
    y += 16;
  }
}

void Menu::write(Frame &tex) const {
  title.write(tex);
  for (auto const &button : buttons) {
    button.write(tex);
  }
}
