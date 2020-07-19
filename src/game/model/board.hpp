#ifndef BOARD_HPP
#define BOARD_HPP

#include "../util/general.hpp"
#include "panel.hpp"

#include <vector>

class Board {
  std::vector<Panel> _panels;

public:
  template <class F> void panelForEach(F f) const {
    for (auto const &panel : _panels) {
      f(panel);
    }
  }

  void addPanel(Pos pos, PanelEvent event) { _panels.emplace_back(pos, event); }
};

#endif // BOARD_HPP
