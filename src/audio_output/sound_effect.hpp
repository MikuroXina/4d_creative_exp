#ifndef SOUND_EFFECT_HPP
#define SOUND_EFFECT_HPP

#include "./wav.hpp"

// SoundEffectGenerator generated wave form with elapsed time.
using SoundEffectGenerator = u8 (&)(u32 elapsed);

// SoundEffect stores start and current time.
// SoundEffect delegates generation to a generator.
class SoundEffect {
  SoundEffectGenerator generator;
  u32 start, current;

public:
  SoundEffect(SoundEffectGenerator &&generator) : generator(generator) {}

  void start_to_play(u32 time) { start = current = time; }

  void write(Wav wav) {
    for (int i = 0; i < WAV_SIZE; ++i) {
      auto const elapsed =
          current < start ? ((u32)(-1) - start - current) : current - start;
      wav[i] = generator(elapsed);
      ++current;
    }
  }
};

#endif // SOUND_EFFECT_HPP
