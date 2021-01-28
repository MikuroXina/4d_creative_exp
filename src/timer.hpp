#ifndef TIMER_HPP
#define TIMER_HPP

#include <xc.h>

inline void set_pr1(unsigned long us) {
  if (us < 1597) {
    PR1 = us * 40 - 1;
    T1CONbits.TCKPS = 0;
  } else if (us < 13101) {
    PR1 = us * 5 - 1;
    T1CONbits.TCKPS = 1;
  } else if (us < 104855) {
    PR1 = us * 40 / 64 - 1;
    T1CONbits.TCKPS = 2;
  } else {
    PR1 = us * 40 / 256 - 1;
    T1CONbits.TCKPS = 3;
  }
  T1CONbits.ON = 1;
}

inline void set_pr2(unsigned long us) {
  long test = 1638;
  char pace = 0;
  for (; pace < 6; ++pace) {
    if (us < test)
      break;
    test <<= 1;
  }
  if (7 <= pace && us < 256) {
    pace += 2;
  }
  us >>= pace;
  PR2 = us * 40 - 1;
  T2CONbits.TCKPS = pace;
  T2CONbits.ON = 1;
}

#endif // TIMER_HPP
