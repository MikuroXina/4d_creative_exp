#ifndef MENU_FOCUS_HPP
#define MENU_FOCUS_HPP

class Menu;

class MenuFocus {
  Menu &menu;

public:
  MenuFocus(Menu &menu) : menu(menu) {}

  void focus_prev();
  void focus_next();
  void press();
  void blur();
};

#endif // MENU_FOCUS_HPP
