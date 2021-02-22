#ifndef EFFECT_HPP
#define EFFECT_HPP

#include "../controller/focus.hpp"
#include "../scene/scene.hpp"
#include "../ui/menu.hpp"
#include "coin.hpp"
#include "panel_event.hpp"
#include "piece.hpp"

namespace effect {
void revelation(Scene &scene, Piece &piece) {
  Menu options{{u"カミノ ケイジ"}, {u"ミギ", u"ヒダリ"}};
  auto &focus = scene.focus();
  focus.run(options);
  if (focus.current_button_idx() == 0) {
    piece.incr_coins(Coin{5});
  } else {
    scene.game().advance(piece, 2);
  }
};

void gamble_life(Scene &scene, Piece &piece) {
  Text text{{u"パチンコデ モウカル"}};
  scene.focus().confirm_message(text);
  piece.incr_coins(Coin{10});
}

void alcohol_detected(Scene &scene, Piece &piece) {
  Text text{{u"リョウデ\nオサケガ ミツカル"}};
  scene.focus().confirm_message(text);
  piece.decr_coins(Coin{20});
}

void destiny(Scene &scene, Piece &piece) {
  Menu options{{u"イツカクル\nウンメイ"}, {u"ミギ", u"ヒダリ"}};
  auto &focus = scene.focus();
  focus.run(options);
  if (focus.current_button_idx() == 0) {
    piece.incr_coins(Coin{10});
  } else {
    scene.game().advance(piece, 3);
  }
}

void try_cigarette(Scene &scene, Piece &piece) {
  Text text{{u"タバコニ チョウセン"}};
  scene.focus().confirm_message(text);
  piece.incr_coins(Coin{20});
}
} // namespace effect

#endif // EFFECT_HPP
