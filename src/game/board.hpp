#ifndef BOARD_HPP
#define BOARD_HPP

#include "../general.hpp"
#include "./panel.hpp"

#include <vector>

// Board aggregates Panel objects.
class Board {
  std::vector<Panel> _panels;

public:
  Board() = default;

  Board(Board &&moved)
      : _panels(static_cast<std::vector<Panel> &&>(moved._panels)) {}
  Board &operator=(Board &&) = default;

  template <class F> void panel_for_each(F f) const {
    for (auto const &panel : _panels) {
      f(panel);
    }
  }

  void add_panel(Pos pos, PanelEvent event) {
    _panels.push_back(Panel{pos, event, _panels.size()});
  }

  void add_panels(std::initializer_list<std::pair<Pos, PanelEvent>> &&args) {
    for (auto &&arg : args) {
      add_panel(arg.first, arg.second);
    }
  }

  Panel &last() { return _panels.back(); }

  Panel &at(u32 index) { return _panels.at(std::min(size() - 1, index)); }
  Panel const &at(u32 index) const {
    return _panels.at(std::min(size() - 1, index));
  }

  u32 size() const { return _panels.size(); }
};

#endif // BOARD_HPP
