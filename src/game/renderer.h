#ifndef RENDERER_H
#define RENDERER_H

#include "model/board.h"
#include "model/camera.h"
#include "model/panel.h"
#include "model/pone.h"
#include "util/general.h"
#include "util/string.h"

typedef u8 TextureChunk;
typedef TextureChunk Texture8x8[8];
typedef TextureChunk Texture16x16[32];
typedef TextureChunk Texture64x64[512];

typedef struct {
  Pos from, to;
} Path;

typedef struct {
  u8 num;
} Roulette;

void renderTex(Camera const *camera, Texture64x64 const tex, Pos pos);

void renderBoard(Camera const *camera, Board const *path);
void renderPath(Camera const *camera, Path const *path);
void renderPanel(Camera const *camera, Panel const *path);
void renderPone(Camera const *camera, Pone const *path);
void renderRoulette(Camera const *camera, Roulette const *roulette);

void renderMessage(Camera const *camera, String const *message);

#endif // RENDERER_H
