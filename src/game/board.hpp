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

  Board(Board &&moved) : _panels(std::move(moved._panels)) {}
  Board &operator=(Board &&) = default;

  template <class F> void panel_for_each(F f) const {
    for (auto const &panel : _panels) {
      f(panel);
    }
  }

  void add_panel(Pos pos, PanelEvent event) {
    _panels.emplace_back(pos, event, _panels.size());
  }

  Panel &last() { return _panels.back(); }

  Panel &at(u32 index) { return _panels.at(index); }
};

#endif // BOARD_HPP
