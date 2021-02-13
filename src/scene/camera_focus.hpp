#ifndef CAMERA_FOCUS_HPP
#define CAMERA_FOCUS_HPP

#include "../general.hpp"

class Piece;

// CameraFocus references Piece to focus by Camera.
class CameraFocus {
  Piece &piece;

public:
  CameraFocus(Piece &piece) : piece(piece) {}

  void change_focus(Piece &piece);
  Pos focused_pos() const;
  void blur();
};

#endif // CAMERA_FOCUS_HPP
