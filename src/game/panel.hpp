#ifndef PANEL_HPP
#define PANEL_HPP

#include "../general.hpp"
#include "./panel_event.hpp"

// Panel has position, index and PanelEvent.
class Panel {
  Pos _pos;
  PanelEvent _event;
  u32 _idx;

  Panel(Pos pos, PanelEvent event, u32 index)
      : _pos(pos), _event(event), _idx(index) {}

public:
  friend class Board;

  Panel(Panel const &p) : _pos(p._pos), _event(p._event), _idx(p._idx) {}
  Panel &operator=(Panel const &p) { return *this = p; }

  Pos pos() const { return _pos; }

  PanelEvent const &event() const { return _event; }

  u32 index() const { return _idx; }
};

#endif // PANEL_HPP
