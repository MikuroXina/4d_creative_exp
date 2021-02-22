#ifndef PIECE_HPP
#define PIECE_HPP

#include "../general.hpp"
#include "./coin.hpp"

#include <algorithm>
#include <vector>

class Panel;

// Piece manages Coin.
// Piece is on Panel.
class Piece {
  Coin owned_coins;
  bool is_goaled = false;

public:
  Panel &on;

  Piece(Panel &on) : owned_coins(0), on(on) {}

  void incr_coins(Coin amount) { owned_coins = owned_coins + amount; }

  void decr_coins(Coin amount) { owned_coins = owned_coins - amount; }

  void goal() { is_goaled = true; }
  bool is_goaled() const { return is_goaled; }

  Panel &where_is_on() { return on; }
  Panel const &where_is_on() const { return on; }
};

// Pieces aggregates Piece.
class Pieces {
  std::vector<Piece> _pieces;

public:
  Pieces() { _pieces.reserve(4); }

  Piece &piece(u32 idx) { return _pieces.at(idx); }

  void add_piece(Panel &to) { _pieces.push_back(Piece{to}); }

  template <class F> void piece_for_each(F f) const {
    for (auto const &piece : _pieces) {
      f(piece);
    }
  }
};

#endif // PIECE_HPP
