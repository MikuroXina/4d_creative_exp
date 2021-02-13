#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../general.hpp"
#include "./camera_focus.hpp"

Rect constexpr SCREEN{{0, 0}, {128, 64}};

class Board;
class Frame;
class Piece;
class Pieces;

// Camera renders around Piece into Frame.
class Camera {
  Pieces const &_pieces;
  Board const &_board;

public:
  Pos pos;
  CameraFocus focus;

  Camera(Piece const &first_player, Pieces const &pieces, Board const &board)
      : _pieces(pieces), _board(board), pos(4, 4), focus(first_player) {}

  void move_to_focus();
  void write(Frame &tex) const;
};

#endif // CAMERA_HPP
