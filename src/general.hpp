#ifndef GENERAL_HPP
#define GENERAL_HPP

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned long;

using i8 = signed char;
using i16 = short;
using i32 = long;

using f16 = float;
using f32 = double;

#define HAS_MASK(v, mask) ((v & mask) == mask)

inline void busy_wait(u16 count) {
  for (; count != 0; --count)
    ;
}

inline u8 reverse_bits(u8 bits) {
  bits = (bits & 0x0f) << 4 | (bits >> 4) & 0x0f;
  bits = (bits & 0x33) << 2 | (bits >> 2) & 0x33;
  bits = (bits & 0x55) << 1 | (bits >> 1) & 0x55;
  return bits;
}

inline u16 reverse_bits(u16 bits) {
  bits = (bits & 0x00ff) << 8 | (bits >> 8) & 0x00ff;
  bits = (bits & 0x0f0f) << 4 | (bits >> 4) & 0x0f0f;
  bits = (bits & 0x3333) << 2 | (bits >> 2) & 0x3333;
  bits = (bits & 0x5555) << 1 | (bits >> 1) & 0x5555;
  return bits;
}

class Pos {
  i8 _x, _y;

public:
  Pos(i8 x, i8 y) : _x(x), _y(y) {}

  i8 x() const { return _x; }
  i8 y() const { return _y; }

  static Pos zero() { return Pos{0, 0}; }
};

class Size {
  u8 _w, _h;

public:
  Size(u8 w, u8 h) : _w(w), _h(h) {}

  u8 w() const { return _w; }
  u8 h() const { return _h; }

  static Size zero() { return Size{0, 0}; }
};

class Rect {
  Pos _pos;
  Size _size;

public:
  Rect(Pos pos, Size size) : _pos(pos), _size(size) {}

  Pos pos() const { return _pos; }
  Size size() const { return _size; }

  i8 top() const { return _pos.y(); }
  i8 bottom() const { return _pos.y() + _size.h(); }
  i8 left() const { return _pos.x(); }
  i8 right() const { return _pos.x() + _size.w(); }

  static Rect zero() { return Rect{Pos::zero(), Size::zero()}; }
};

#endif // GENERAL_HPP
