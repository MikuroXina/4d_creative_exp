#include <vector>

#include "wav_player.hpp"

#include <algorithm>

void WavPlayer::bounce_audio_frame() {
  std::fill(not_playing, not_playing + WAV_SIZE, 0);
  for (auto &se : sound_effects) {
    se.write(not_playing);
  }
  std::swap(playing, not_playing);
}

WavPlayer::WavPlayer() {
  TRISA &= ~(1 << 3);
  // TODO: Do I need to setup the Output Comparator?
}

void WavPlayer::update(u8 elapsed) {
  auto it =
      std::remove_if(sound_effects.begin(), sound_effects.end(),
                     [](SoundEffect const &se) { return se.reached_end(); });
  sound_effects.erase(it);
}

void WavPlayer::fixed_update() {
  auto const sample = playing[playing_index];
  // TODO: output the sample
  ++playing_index;
  if (playing_index == 0) {
    bounce_audio_frame();
  }
}

void WavPlayer::play_se(SoundEffect &&se) { sound_effects.push_back(se); }
