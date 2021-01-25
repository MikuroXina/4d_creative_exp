#ifndef PANEL_HPP
#define PANEL_HPP

#include "../general.hpp"

enum PanelEvent {
  Nothing,
  Good,
  Bad,
};

class Panel {
  Pos _pos;
  PanelEvent _event;
  u32 _idx;

public:
  Panel(Pos pos, PanelEvent event, u32 index)
      : _pos(pos), _event(event), _idx(index) {}
};

#endif // PANEL_HPP
