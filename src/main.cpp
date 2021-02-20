#include <fftc.h>
#include <sys/attribs.h>
#include <xc.h>

#include "audio_output/sound_effect.hpp"
#include "audio_output/wav_player.hpp"
#include "controller/button.hpp"
#include "general.hpp"
#include "lcd_renderer/frame.hpp"
#include "scene/scene.hpp"
#include "timer.hpp"
#include "ui/text.hpp"

// Use Fast RC Oscillator (8 Mhz) with System PLL
#pragma config FNOSC = FRCPLL
// ÷ 2
#pragma config FPLLIDIV = DIV_2
// × 20
#pragma config FPLLMUL = MUL_20
// ÷ 2
#pragma config FPLLODIV = DIV_2
// System clock is 40 MHz

#pragma config FSOSCEN = OFF
#pragma config IESO = OFF
#pragma config FPBDIV = DIV_1
#pragma config FWDTEN = OFF
#pragma config JTAGEN = OFF

static u8 t1if;

extern "C" void __ISR(_TIMER_1_VECTOR, IPL3SOFT) Timer1Handler() {
  IFS0bits.T1IF = 0;
  ++t1if;
}

u8 square(u32 t) { return (t % 227 < 110) ? 1 : 255; }

int main() {
  ANSELA = ANSELB = 0;
  TRISA = 0b1000; // RA3 is input
  TRISB = 0b100;  // RB2 is input
  LATA = LATB = 0;

  SoundEffect se{square};

  WavPlayer wp;

  wp.play_se(static_cast<SoundEffect &&>(se));

  //  Board board;
  //
  //  board.add_panels({
  //      {{0, 0}, {PanelEventKind::Nothing}},
  //      {{32, 0}, {PanelEventKind::Good}},
  //      {{32, 32}, {PanelEventKind::Bad}},
  //      {{0, 32}, {PanelEventKind::Good}},
  //  });
  //
  //  Scene scene(1, static_cast<Board &&>(board));
  //
  //  HardwareButton determine(0), left(1), right(2);

  //  Frame frame{};

  //  u16 line[16] = {};
  //  for (u8 idx{0}; idx != 16; ++idx) {
  //    line[idx] = 1 << idx;
  //  }
  //  frame.draw16x16(line, Pos{0, 0});

  //  Text text(u"テスト");
  //  text.write(frame);

  while (1) {
    if (!t1if) {
      continue;
    }
    //    frame.flush();
    wp.fixed_update();
    wp.update(t1if);
    t1if = 0;
  }
}
