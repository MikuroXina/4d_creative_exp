#ifndef PONE_H
#define PONE_H

#include "../util/general.h"
#include "panel.h"

typedef u8 Coin;
Coin const MAX_COIN = 99;

typedef struct {
  Coin owned_coins;
  Panel *on;
} Pone;

inline Pone newPone(Panel *on) { return Pone{0, on}; }

inline void incrCoins(Pone *p, Coin amount) {
  p->owned_coins = MAX(p->owned_coins + amount, MAX_COIN);
}

inline void decrCoins(Pone *p, Coin amount) {
  p->owned_coins = (u8)MIN((i8)p->owned_coins - (i8)amount, 0);
}

typedef struct {
  u8 nPones;
  Pone container[4];
} Pones;

inline Pones newPones() { return {0, {}}; }

void addPone(Pones *pones, Panel *to) {
  pones->container[pones->nPones] = newPone(to);
  pones->nPones += 1;
}

inline Pone *endPone(Pones *pones) { return &pones->container[pones->nPones]; }

#endif // PONE_H
