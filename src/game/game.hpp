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
  Game()
      : _board{}, _pones{}, _camera{_pones.pone(0)}, _currentPlayerIdx(0),
        _turnCount(1) {}

  void start() {
    // Game process here
  }

  void handle(PanelEvent event, Pone &stepped) {
    switch (event) {
    case Nothing:
      return;
    case Good:
      stepped.incr_coins(5);
      return;
    case Bad:
      stepped.decr_coins(2);
      return;
    }
  }
};

#endif // GAME_HPP
