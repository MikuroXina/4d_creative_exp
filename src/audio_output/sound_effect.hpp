#ifndef SOUND_EFFECT_HPP
#define SOUND_EFFECT_HPP

#include "./wav.hpp"

using SoundEffectGenerator = u8 (&)(u32);

class SoundEffect {
  SoundEffectGenerator generator;
  u32 start, current;

public:
  SoundEffect(SoundEffectGenerator &&generator) : generator(generator) {}

  void start_to_play(u32 time) { start = current = time; }

  void write(Wav wav) {
    for (int i = 0; i < WAV_SIZE; ++i) {
      wav[i] = generator(current - start);
      ++current;
    }
  }
};

#endif // SOUND_EFFECT_HPP
