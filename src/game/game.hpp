#ifndef GAME_HPP
#define GAME_HPP

#include "../general.hpp"
#include "./board.hpp"
#include "./camera.hpp"
#include "./panel.hpp"
#include "./piece.hpp"
#include "./roulette.hpp"

// Game mediates board, pieces and roulette.
class Game {
  Board _board;
  Pieces _pieces;
  Roulette _roulette;
  u8 _current_player_idx;
  u8 _turn_count;
  u8 _numbers_of_player;

public:
  Game(u8 numbers_of_player, Board &&board)
      : _board{std::move(board)}, _pieces{}, _current_player_idx(0),
        _turn_count(1), _numbers_of_player(numbers_of_player) {
    auto &first_panel = _board.at(0);

    for (u8 i = 0; i != numbers_of_player; ++i) {
      _pieces.add_piece(first_panel);
    }
  }

  Piece &current_player() { return _pieces.piece(_current_player_idx); }
  Pieces const &players() const { return _pieces; }

  u8 spin_roulette() { return _roulette.roll(); }

  void advance(Piece &target, u8 steps) {
    auto dst = _board.at(target.where_is_on().index() + steps);
    target.move_to(dst);
  }

  void next_turn() {
    ++_turn_count;
    ++_current_player_idx;
    if (_current_player_idx == _numbers_of_player) {
      _current_player_idx = 0;
    }
  }

  bool is_end() const { return _turn_count == 9; }
};

#endif // GAME_HPP
