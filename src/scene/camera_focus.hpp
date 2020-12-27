#ifndef CAMERA_FOCUS_HPP
#define CAMERA_FOCUS_HPP

#include "../general.hpp"

class Pone;

class CameraFocus {
  Pone &pone;

public:
  CameraFocus(Pone &pone) : pone(pone) {}

  void change_focus(Pone &pone);
  Pos focused_pos() const;
  void blur();
};

#endif // CAMERA_FOCUS_HPP
