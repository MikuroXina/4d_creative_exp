#ifndef PONE_HPP
#define PONE_HPP

#include "../util/general.hpp"
#include "panel.hpp"

#include <algorithm>
#include <vector>

class Coin {
  static constexpr u8 MAX_COIN = 99;
  u8 _amount = 0;

public:
  Coin(u8 amount) { _amount = std::min(std::max<u8>(amount, 0), MAX_COIN); }

  Coin operator+(Coin const &r) const {
    return Coin(std::max<u8>(_amount + r._amount, MAX_COIN));
  }
  Coin operator-(Coin const &r) const {
    return Coin((u8)std::max<i8>((i8)_amount - (i8)r._amount, 0));
  }
};

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
