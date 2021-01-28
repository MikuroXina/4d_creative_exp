#ifndef SCENE_HPP
#define SCENE_HPP

#include "../game/game.hpp"
#include "./camera.hpp"

// Scene has Game and Camera.
// Scene updates the game process.
class Scene {
  Game game;
  Camera camera;

public:
  Scene(u8 numbers_of_player);

  void update();
};

#endif // SCENE_HPP
