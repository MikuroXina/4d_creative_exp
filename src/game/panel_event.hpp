#ifndef PANEL_EVENT_HPP
#define PANEL_EVENT_HPP

#include "../ui/text.hpp"
#include "./piece.hpp"

class Scene;

using PanelEventKind = void (&)(Scene &scene, Piece &piece);

// PanelEvent mutates Piece.
class PanelEvent {
  PanelEventKind _kind;

public:
  PanelEvent(PanelEventKind kind) : _kind(kind) {}

  void apply(Scene &scene, Piece &piece) const { _kind.effect(scene, piece); }
};

#endif // PANEL_EVENT_HPP
