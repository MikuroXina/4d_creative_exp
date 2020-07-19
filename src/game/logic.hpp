#ifndef LOGIC_HPP
#define LOGIC_HPP

#include "model/board.hpp"
#include "model/camera.hpp"
#include "model/panel.hpp"
#include "model/pone.hpp"
#include "util/general.hpp"

class Game {
  Board _board;
  Pones _pones;
  Camera _camera;
  u8 _currentPlayerIdx;
  u8 _turnCount;

public:
  Game() : _board{}, _pones{}, _camera{}, _currentPlayerIdx(0), _turnCount(1) {}

  void start() {
    // Game process here
  }

  void handle(PanelEvent event, Pone &stepped) {
    switch (event) {
    case Nothing:
      return;
    case Good:
      stepped.incrCoins(5);
      return;
    case Bad:
      stepped.decrCoins(2);
      return;
    }
  }
};

#endif // LOGIC_HPP
