#ifndef PONE_HPP
#define PONE_HPP

#include "../general.hpp"
#include "./coin.hpp"
#include "./panel.hpp"

#include <algorithm>
#include <vector>

// Pone manages Coin.
// Pone is on Panel.
class Pone {
  Coin owned_coins;
  Panel &on;

public:
  Pone(Panel &on) : owned_coins(0), on(on) {}

  void incr_coins(Coin amount) { owned_coins = owned_coins + amount; }

  void decr_coins(Coin amount) { owned_coins = owned_coins - amount; }
};

// Pones aggregates Pone.
class Pones {
  std::vector<Pone> _pones;

public:
  Pones() : _pones(4) {}

  Pone &pone(u32 idx) { return _pones.at(idx); }

  void add_pone(Panel &to) { _pones.emplace_back(to); }

  template <class F> void pone_for_each(F f) const {
    for (auto const &pone : _pones) {
      f(pone);
    }
  }
};

#endif // PONE_HPP
