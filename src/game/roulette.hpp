#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include "../general.hpp"
#include "../ui/text.hpp"

#include <random>

// Roulette keeps Menu having Text says 1 to 4.
// Roulette moves MenuFocus by time and decreases its speed.
// Roulette results the integer from 1 to 4.
class Roulette {
  Text texts[4];
  std::random_device gen;
  std::uniform_int_distribution<u8> dist;

public:
  Roulette() : texts{
    Text(u"1", {64, 8}),
    Text(u"2", {64, 24}),
    Text(u"3", {64, 40}),
    Text(u"4", {64, 56}),
  }, dist(1, 4) {}

  u8 roll() {
    auto result = dist(gen);
    // TODO: Animate rolling
    return result;
  }
};

#endif // ROULETTE_HPP
