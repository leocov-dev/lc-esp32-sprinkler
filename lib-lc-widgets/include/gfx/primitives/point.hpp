#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_POINT_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_POINT_HPP_

#include <iostream>

namespace lc::gfx {
  struct Point {
    Point(int x, int y) : x(x), y(y){};

    int x, y;

    Point& operator+=(const Point& rhs) {
      x += rhs.x;
      y += rhs.y;
      return *this;
    }

    Point& operator-=(const Point& rhs) {
      x -= rhs.x;
      y -= rhs.y;
      return *this;
    }
  };
  Point operator+(const Point& lhs, const Point& rhs);
  Point operator-(const Point& lhs, const Point& rhs);
  inline std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "Point{ "
              << "x: " << point.x << ", "
              << "y: " << point.y << " }";
  }
}  // namespace lc::gfx
#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_POINT_HPP_
