#include "wav_player.hpp"
#include "../timer.hpp"

#include <sys/attribs.h>
#include <xc.h>

#include <algorithm>
#include <utility>
#include <vector>

WavPlayer *WavPlayer::current = nullptr;

void fixed_update();

extern "C" void __ISR(_TIMER_2_VECTOR, IPL3SOFT) Timer2Handler() {
  IFS0bits.T1IF = 0;
  fixed_update();
}

void WavPlayer::bounce_audio_frame() {
  std::fill(not_playing, not_playing + WAV_SIZE, 0);
  for (auto &se : sound_effects) {
    se.write(not_playing);
  }
  for (u8 i = 0; i < WAV_SIZE; ++i) {
    std::swap(playing[i], not_playing[i]);
  }
}

void fixed_update() {
  WavPlayer &wp = WavPlayer::get();
  // Change pulse width as possible as fast
  u32 const sample = wp.playing[wp.playing_index];
  OC3R = sample;
  OC3RS = sample >> 2;
  if (wp.playing_index != 0) {
    ++wp.playing_index;
  }
}

WavPlayer::WavPlayer() {
  TRISA &= ~(1 << 3);

  // Setup timers
  set_pr1(1000);
  IFS0bits.T1IF = 0;
  IEC0bits.T1IE = 1;
  IPC1bits.T1IP = 3;
  IPC1bits.T1IS = 0;

  set_pr2(272727);
  OC3R = PR2;
  OC3RS = 0;
  RPA3Rbits.RPA3R = 0b101;
  OC3CONbits.OCTSEL = 0;
  OC3CONbits.OCM = 0b110;
  OC3CONbits.ON = 1;

  __builtin_enable_interrupts();
}

void WavPlayer::update(u8 elapsed) {
  auto it =
      std::remove_if(sound_effects.begin(), sound_effects.end(),
                     [](SoundEffect const &se) { return se.reached_end(); });
  sound_effects.erase(it);
  if (playing_index == 0) {
    bounce_audio_frame();
    playing_index = 1;
  }
}

void WavPlayer::play_se(SoundEffect &&se) {
  sound_effects.push_back(static_cast<SoundEffect &&>(se));
}
