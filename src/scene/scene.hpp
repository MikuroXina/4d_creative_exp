#ifndef SCENE_HPP
#define SCENE_HPP

#include "../controller/focus.hpp"
#include "../game/game.hpp"
#include "./camera.hpp"

// Scene has Game and Camera.
// Scene updates the game process.
class Scene {
  Game _game;
  Camera camera;
  Focus _focus;

public:
  Scene(u8 numbers_of_player, Board &&board);

  void run();

  Game &game() { return _game; }
  Focus &focus() { return _focus; }
};

#endif // SCENE_HPP
