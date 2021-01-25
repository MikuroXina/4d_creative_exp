#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include "../general.hpp"

class Pone;

// Roulette keeps Menu having MenuItem 1 to 4.
// Roulette moves MenuFocus by time and decreases its speed.
// Roulette results the integer from 1 to 4.
template <class R> class Roulette {
  R _generator;

public:
  Roulette(R generator) : _generator(generator) {}

  u8 roll();
};

#endif // ROULETTE_HPP
