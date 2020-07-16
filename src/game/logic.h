#ifndef LOGIC_H
#define LOGIC_H

#include "model/board.h"
#include "model/camera.h"
#include "model/panel.h"
#include "model/pone.h"
#include "util/general.h"

typedef struct {
  Board board;
  Pones pones;
  Camera camera;
  Pone *currentPlayerPone;
  u8 turnCount;
} Game;

inline Game newGame() {
  return Game{newBoard(), newPones(), newCamera(), NULL, 1};
}

inline void advanceTurn(Game *game) {
  game->currentPlayerPone += 1;
  if (game->currentPlayerPone == endPone(&game->pones)) {
    game->currentPlayerPone = &game->pones.container[0];
    game->turnCount += 1;
  }
}

inline void handle(PanelEvent event, Pone *stepped) {
  switch (event) {
  case Nothing:
    return;
  case Good:
    incrCoins(stepped, 5);
    return;
  case Bad:
    decrCoins(stepped, 2);
    return;
  }
}

#endif // LOGIC_H
