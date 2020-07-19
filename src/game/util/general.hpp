#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <cstdint>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;

using f16 = float;
using f32 = double;

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

class Pos {
  u8 _x, _y;

public:
  Pos(u8 x, u8 y) : _x(x), _y(y) {}

  static Pos zero() { return Pos{0, 0}; }
};

class Size {
  u8 _w, _h;

public:
  Size(u8 w, u8 h) : _w(w), _h(h) {}

  static Size zero() { return Size{0, 0}; }
};

class Rect {
  Pos _pos;
  Size _size;

public:
  Rect(Pos pos, Size size) : _pos(pos), _size(size) {}

  static Rect zero() { return Rect{Pos::zero(), Size::zero()}; }
};

#endif // GENERAL_HPP
