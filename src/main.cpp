#include <xc.h>

#include "controller/button.hpp"
#include "general.hpp"
#include "lcd_renderer/frame.hpp"
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

int main() {
  ANSELA = ANSELB = 0;
  TRISA = 0b1000; // RA3 is input
  TRISB = 0b100;  // RB2 is input
  LATA = LATB = 0;

  Button determine(0), left(1), right(2);

  Frame frame{};

  u16 line[16] = {};
  for (u8 idx{0}; idx != 16; ++idx) {
    line[idx] = 1 << idx;
  }
  frame.draw16x16(line, Pos{0, 0});

  Text text(u"テスト");
  text.write(frame);

  frame.flush();

  while (1) {
  }
}
