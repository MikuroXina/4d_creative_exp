#ifndef BOARD_HPP
#define BOARD_HPP

#include "../general.hpp"
#include "./panel.hpp"

#include <vector>

// Board aggregates Panel objects.
class Board {
  std::vector<Panel> _panels;

public:
  template <class F> void panel_for_each(F f) const {
    for (auto const &panel : _panels) {
      f(panel);
    }
  }

  void add_panel(Pos pos, PanelEvent event) {
    _panels.emplace_back(pos, event, _panels.size());
  }

  Panel &first() { return _panels.at(0); }
};

#endif // BOARD_HPP
