#ifndef COIN_HPP
#define COIN_HPP

#include "../general.hpp"

#include <algorithm>

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

#endif // COIN_HPP
