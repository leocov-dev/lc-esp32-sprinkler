#ifndef LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_TRANSFORM_HPP_
#define LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_TRANSFORM_HPP_

#include <iostream>

namespace lc::gfx {

struct Point {
  Point(int x, int y) : x(x), y(y) {};

  int x, y;

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
  int width, height;
};

struct Rect {
  // Upper left corner.
  Point origin;
  Size size;

  [[nodiscard]] Point UpperLeft() const { return origin; }

  [[nodiscard]] Point LowerRight() const {
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

} // namespace sprinkler::gfx

#endif  // LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_TRANSFORM_HPP_
