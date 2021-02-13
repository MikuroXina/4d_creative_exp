#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../general.hpp"
#include "./camera_focus.hpp"

Rect constexpr SCREEN{{0, 0}, {128, 64}};

class Frame;
class Piece;
class Pieces;

// Camera renders around Piece into Frame.
class Camera {
  Pieces const &_pieces;

public:
  Pos pos;
  CameraFocus focus;

  Camera(Piece const &first_player, Pieces const &pieces)
      : _pieces(pieces), pos(4, 4), focus(first_player) {}

  void move_to_focus();
  void write(Frame &tex) const;
};

#endif // CAMERA_HPP
