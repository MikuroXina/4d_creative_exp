#include "scene.hpp"

Scene::Scene(u8 numbers_of_player, Board &&board)
    : game{numbers_of_player, std::move(board)}, camera{game.current_player()} {
}

void Scene::run() {
  while (true) {
    u8 steps = game.spin_roulette();
    auto current = game.current_player();
    // TODO: Advance a pone
    // TODO: Activate an effect of the panel
    game.next_turn();
  }
}
