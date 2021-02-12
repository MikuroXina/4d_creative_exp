#ifndef GAME_HPP
#define GAME_HPP

#include "../general.hpp"
#include "./board.hpp"
#include "./camera.hpp"
#include "./panel.hpp"
#include "./pone.hpp"

// Game mediates board, pones and roulette.
class Game {
  Board _board;
  Pones _pones;
  Camera _camera;
  u8 _current_player_idx;
  u8 _turn_count;
  u8 _numbers_of_player;

public:
  Game(u8 numbers_of_player, Board &&board)
      : _board{std::move(board)}, _pones{}, _camera{_pones.pone(0)},
        _current_player_idx(0), _turn_count(1),
        _numbers_of_player(numbers_of_player) {
    auto &first_panel = _board.first();

    for (u8 i = 0; i != numbers_of_player; ++i) {
      _pones.add_pone(first_panel);
    }
  }

  Pone &current_player() { return _pones.pone(_current_player_idx); }

  void next_turn() {
    ++_turn_count;
    ++_current_player_idx;
    if (_current_player_idx == _numbers_of_player) {
      _current_player_idx = 0;
    }
  }

  void handle(PanelEvent event, Pone &stepped) { event.apply(stepped); }
};

#endif // GAME_HPP
