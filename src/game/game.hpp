#ifndef GAME_HPP
#define GAME_HPP

#include "../general.hpp"
#include "./board.hpp"
#include "./camera.hpp"
#include "./panel.hpp"
#include "./pone.hpp"

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

#endif // GAME_HPP
