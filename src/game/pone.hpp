#ifndef PONE_HPP
#define PONE_HPP

#include "../general.hpp"
#include "./coin.hpp"
#include "./panel.hpp"

#include <algorithm>
#include <vector>

class Pone {
  Coin owned_coins;
  Panel &on;

public:
  Pone(Panel &on) : owned_coins(0), on(on) {}

  void incrCoins(Coin amount) { owned_coins = owned_coins + amount; }

  void decrCoins(Coin amount) { owned_coins = owned_coins - amount; }
};

class Pones {
  std::vector<Pone> _pones;

public:
  Pones() : _pones(4) {}

  void addPone(Panel &to) { _pones.emplace_back(to); }

  template <class F> void poneForEach(F f) const {
    for (auto const &pone : _pones) {
      f(pone);
    }
  }
};

#endif // PONE_HPP
