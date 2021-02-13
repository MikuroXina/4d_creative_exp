#ifndef PANEL_EVENT_HPP
#define PANEL_EVENT_HPP

#include "./piece.hpp"

enum PanelEventKind {
  Nothing,
  Good,
  Bad,
};

// PanelEvent mutates Piece.
class PanelEvent {
  PanelEventKind _kind;

public:
  PanelEvent(PanelEventKind kind) : _kind(kind) {}

  void apply(Piece &piece) const {
    switch (_kind) {
    case Nothing:
      return;
    case Good:
      piece.incr_coins(5);
      return;
    case Bad:
      piece.decr_coins(2);
      return;
    }
  }
};

#endif // PANEL_EVENT_HPP
