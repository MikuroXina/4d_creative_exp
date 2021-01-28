#ifndef SOUND_EFFECT_HPP
#define SOUND_EFFECT_HPP

#include "./wav.hpp"

// SoundEffectGenerator generated wave form with elapsed time.
// Please note that returniong zero means it reached the end of sound effect.
using SoundEffectGenerator = u8 (&)(u32 elapsed);

// SoundEffect stores start and current time.
// SoundEffect delegates generating to a generator.
class SoundEffect {
  SoundEffectGenerator generator;
  u32 start, current;
  bool is_end = false;

public:
  SoundEffect(SoundEffectGenerator &&generator) : generator(generator) {}

  void start_to_play(u32 time) {
    start = current = time;
    is_end = false;
  }

  void write(Wav wav) {
    if (is_end)
      return;
    for (int i = 0; i < WAV_SIZE; ++i) {
      auto const elapsed =
          current < start ? ((u32)(-1) - start - current) : current - start;
      auto const sample = generator(elapsed);
      wav[i] += sample;
      if (sample == 0) {
        is_end = true;
        return;
      }
      ++current;
    }
  }

  bool reached_end() const { return is_end; }
};

#endif // SOUND_EFFECT_HPP
