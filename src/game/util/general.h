#ifndef GENERAL_H
#define GENERAL_H

#include <stddef.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

typedef signed char i8;
typedef signed int i16;
typedef signed long i32;

typedef float f16;
typedef double f32;

typedef u8 BOOL;

BOOL const YES = 1;
BOOL const NO = 0;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define SWAP(T, a, b)                                                          \
  {                                                                            \
    T tmp = (a);                                                               \
    (a) = (b);                                                                 \
    (b) = tmp;                                                                 \
  }

#define HAS_MASK(v, mask) ((v & mask) == mask)

#define FOR_INCR(T, i, N)                                                      \
  T i = 0;                                                                     \
  for (; i != N; ++i)
#define FOR_DECR(T, i, N)                                                      \
  T i = N;                                                                     \
  for (; 0 != i; --i)

inline u8 reverseBits(u8 bits) {
  bits = (bits & 0xF0) >> 4 | (bits & 0x0F) << 4;
  bits = (bits & 0xCC) >> 2 | (bits & 0x33) << 2;
  bits = (bits & 0xAA) >> 1 | (bits & 0x55) << 1;
  return bits;
}

typedef struct {
  u8 x, y;
} Pos;

inline Pos zeroPos() { return Pos{0, 0}; }

typedef struct {
  u8 w, h;
} Size;

inline Size zeroSize() { return Size{0, 0}; }

typedef struct {
  Pos pos;
  Size size;
} Rect;

inline Rect zeroRect() { return Rect{Pos{0, 0}, Size{0, 0}}; }

#endif // GENERAL_H
