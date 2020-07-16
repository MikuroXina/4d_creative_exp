#ifndef BOARD_H
#define BOARD_H

#include "../util/general.h"
#include "panel.h"

#include <stdlib.h>

typedef struct {
  Panel *start;
  u8 nPanels;
} Board;

inline Panel *startPanel(Board *b) { return b->start; }

inline Panel *endPanel(Board *b) {
  Panel *end = b->start;
  if (end == NULL)
    return NULL;

  while (end->next != NULL) {
    end = end->next;
  }
  return end;
}

inline void addPanel(Board *b, Pos pos, PanelEvent event) {
  Panel *end = endPanel(b);
  end->next = (Panel *)malloc(sizeof(Panel));
  *end->next = newPanel(pos, event);
  b->nPanels += 1;
}

inline Board newBoard() {
  Board b = Board{NULL, 0};
  return b;
}

inline void dropBoard(Board *b) {
  Panel *end = endPanel(b);
  while (end != NULL) {
    free(end);
    end = endPanel(b);
  }
}

#endif // BOARD_H
