#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../general.hpp"

#include <xc.h>

static void __interrupt handler_button_interruption() {}

template <class Handler> class Button {
  Handler &_handler;

public:
  template <class P> Button(P port, Handler &handler) : _handler(handler) {
    port.set();
    P::field;

    IOCAN3 = 1;
    IOCIE = 1;
    GIE = 1;
  }
};

#endif // BUTTON_HPP
