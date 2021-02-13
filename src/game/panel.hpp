#ifndef PANEL_HPP
#define PANEL_HPP

#include "../general.hpp"
#include "./panel_event.hpp"

// Panel has position, index and PanelEvent.
class Panel {
  Pos _pos;
  PanelEvent _event;
  u32 _idx;

public:
  Panel(Pos pos, PanelEvent event, u32 index)
      : _pos(pos), _event(event), _idx(index) {}

  u32 index() const { return _idx; }
};

#endif // PANEL_HPP
