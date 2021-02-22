#include "scene.hpp"

Scene::Scene(u8 numbers_of_player, Board &&board)
    : _game{numbers_of_player, static_cast<Board &&>(board)},
      camera{_game.current_player(), _game.players(), board}, _focus{} {}

void Scene::run() {
  do {
    u8 steps = _game.spin_roulette();
    auto &current = _game.current_player();
    _game.advance(current, steps);
    auto &event = current.where_is_on().event();
    event.apply(*this, current);
    _game.next_turn();
  } while (_game.is_end());
}
