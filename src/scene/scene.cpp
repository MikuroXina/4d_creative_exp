#include "scene.hpp"

Scene::Scene(u8 numbers_of_player, Board &&board)
    : game{numbers_of_player, std::move(board)}, camera{game.current_player()} {
}

void Scene::run() {
  while (true) {
    // TODO: Spin a roulette and read its number
    // TODO: Advance a pone
    // TODO: Activate an effect of the panel
    game.next_turn();
  }
}
