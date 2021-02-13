#ifndef PIECE_HPP
#define PIECE_HPP

#include "../general.hpp"
#include "./coin.hpp"
#include "./panel.hpp"

#include <algorithm>
#include <vector>

// Piece manages Coin.
// Piece is on Panel.
class Piece {
  Coin owned_coins;
  Panel &on;

public:
  Piece(Panel &on) : owned_coins(0), on(on) {}

  void incr_coins(Coin amount) { owned_coins = owned_coins + amount; }

  void decr_coins(Coin amount) { owned_coins = owned_coins - amount; }

  Panel &where_is_on() { return on; }
  Panel const &where_is_on() const { return on; }

  void move_to(Panel &new_panel) { on = new_panel; }
};

// Pieces aggregates Piece.
class Pieces {
  std::vector<Piece> _pieces;

public:
  Pieces() : _pieces(4) {}

  Piece &piece(u32 idx) { return _pieces.at(idx); }

  void add_piece(Panel &to) { _pieces.emplace_back(to); }

  template <class F> void piece_for_each(F f) const {
    for (auto const &piece : _pieces) {
      f(piece);
    }
  }
};

#endif // PIECE_HPP
