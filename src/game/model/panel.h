#ifndef PANEL_H
#define PANEL_H

#include "../util/general.h"

typedef enum {
  Nothing,
  Good,
  Bad,
} PanelEvent;

typedef struct Panel_ {
  Pos pos;
  PanelEvent event;
  struct Panel_ *next;
} Panel;

inline Panel newPanel(Pos pos, PanelEvent event) {
  return Panel{pos, event, NULL};
}

#endif // PANEL_H
