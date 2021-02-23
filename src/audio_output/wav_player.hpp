#ifndef WAV_PLAYER_HPP
#define WAV_PLAYER_HPP

#include <vector>

#include "./sound_effect.hpp"

// WavPlayer keeps playing and not playing Wav.
// WavPlayer swaps between playing and not playing when output the whole of
// playing Wav.
// WavPlayer initiates not playing Wav with SoundEffect generations when it is
// not dirty.
class WavPlayer {
  std::vector<SoundEffect> sound_effects = {};
  Wav playing = {}, not_playing = {};
  u8 playing_index = 0;

  static WavPlayer *current;

  WavPlayer();

  void bounce_audio_frame();

  friend void fixed_update();

public:
  static WavPlayer &get() {
    if (!current) {
      current = new WavPlayer;
    }
    return *current;
  }

  void update(u8 elapsed);

  void play_se(SoundEffect &&se);
};

#endif // WAV_PLAYER_HPP
