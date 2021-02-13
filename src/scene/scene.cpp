#include "scene.hpp"

Scene::Scene(u8 numbers_of_player, Board &&board)
    : game{numbers_of_player, std::move(board)}, camera{game.current_player()} {
}

void Scene::run() {
  do {
    u8 steps = game.spin_roulette();
    auto &current = game.current_player();
    game.advance(current, steps);
    auto &event = current.where_is_on().event();
    event.apply(current);
    game.next_turn();
  } while (game.is_end());
}
