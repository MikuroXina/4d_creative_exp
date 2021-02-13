#ifndef CAMERA_FOCUS_HPP
#define CAMERA_FOCUS_HPP

#include <optional>

class Piece;

// CameraFocus references Piece to focus by Camera.
using CameraFocus = std::optional<Piece const &>;

#endif // CAMERA_FOCUS_HPP
