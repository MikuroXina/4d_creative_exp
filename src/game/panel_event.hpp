#ifndef PANEL_EVENT_HPP
#define PANEL_EVENT_HPP

#include "./pone.hpp"

enum PanelEventKind {
  Nothing,
  Good,
  Bad,
};

// PanelEvent mutates Pone.
class PanelEvent {
  PanelEventKind _kind;

public:
  PanelEvent(PanelEventKind kind) : _kind(kind) {}

  void apply(Pone &pone) const {
    switch (_kind) {
    case Nothing:
      return;
    case Good:
      pone.incr_coins(5);
      return;
    case Bad:
      pone.decr_coins(2);
      return;
    }
  }
};

#endif // PANEL_EVENT_HPP
