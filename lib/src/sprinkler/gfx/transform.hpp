#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_

#include <iostream>

namespace sprinkler::gfx {

class Point {
 public:

  Point(int x, int y) : x(x), y(y) {};
  int x;
  int y;

  Point &operator+=(const Point &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Point &operator-=(const Point &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
};

Point operator+(const Point &lhs, const Point &rhs);
Point operator-(const Point &lhs, const Point &rhs);

struct Size {
  int width;
  int height;
};

struct Rect {
  // Upper left corner.
  Point origin;
  Size size;

  [[nodiscard]] Point upper_left() const { return origin; }

  [[nodiscard]] Point lower_right() const {
    return {
        origin.y - size.height,
        origin.x + size.width
    };
  }
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
  return os << "Point{ "
            << "x: " << point.x << ", "
            << "y: " << point.y
            << " }";
}

inline std::ostream& operator<<(std::ostream& os, const Rect& rect) {
  return os << "Rect{ "
            << "origin: (" << rect.origin.x << ", " << rect.origin.y << ") "
            << "size: (" << rect.size.width <<  ", " << rect.size.height << ")"
            << " }";
}

} // namespace sprinker::gfx

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_
