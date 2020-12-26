#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "../game/board.hpp"
#include "../game/camera.hpp"
#include "../game/panel.hpp"
#include "../game/pone.hpp"
#include "../general.hpp"

struct Texture64x64 {
  u8 chunk[512];
  Pos pos;

  void render(Camera const &camera);
};

struct Path {
  Pos from, to;

  void render(Camera const &camera);
};

struct Roulette {
  u8 num;

  void renderRoulette(Camera const &camera);
};

void renderBoard(Camera const &camera, Board const &path);
void renderPanel(Camera const &camera, Panel const &path);
void renderPone(Camera const &camera, Pone const &path);

void renderMessage(Camera const &camera, char const &message);

#endif // TEXTURE_HPP
