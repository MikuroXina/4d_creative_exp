#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include "../general.hpp"
#include "../ui/text.hpp"

class Pone;

// Roulette keeps Menu having Text says 1 to 4.
// Roulette moves MenuFocus by time and decreases its speed.
// Roulette results the integer from 1 to 4.
template <class R> class Roulette {
  R _generator;
  Text texts[4];

public:
  Roulette(R generator) : _generator(generator) {}

  u8 roll();
};

#endif // ROULETTE_HPP
