#ifndef WAV_PLAYER_HPP
#define WAV_PLAYER_HPP

#include <vector>

#include "./sound_effect.hpp"

class InputPort;
class OutputPort;

class WavPlayer {
  std::vector<SoundEffect> sound_effects = {};
  Wav playing = {}, not_playing = {};
  u8 playing_index = 0;
  InputPort &timer;
  OutputPort &speaker;

  void audio_frame();

public:
  WavPlayer(InputPort &timer, OutputPort &speaker);
};

#endif // WAV_PLAYER_HPP
