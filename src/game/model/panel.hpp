#ifndef PANEL_HPP
#define PANEL_HPP

#include "../util/general.hpp"

#include <memory>

enum PanelEvent {
  Nothing,
  Good,
  Bad,
};

class Panel {
  Pos _pos;
  PanelEvent _event;
  std::unique_ptr<Panel> _next;

public:
  Panel(Pos pos, PanelEvent event) : _pos(pos), _event(event), _next(nullptr) {}
};

#endif // PANEL_HPP
