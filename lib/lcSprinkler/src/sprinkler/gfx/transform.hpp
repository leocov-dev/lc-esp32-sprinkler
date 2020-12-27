#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_

namespace sprinkler::gfx {

struct Point {
  int y;
  int x;
  Point &operator+=(const Point &rhs) {
    y += rhs.y;
    x += rhs.x;
    return *this;
  }
  Point &operator-=(const Point &rhs) {
    y -= rhs.y;
    x -= rhs.x;
    return *this;
  }
};

Point operator+(Point lhs, const Point &rhs);
Point operator-(Point lhs, const Point &rhs);

struct Size {
  int height;
  int width;
};

struct Rect {
  // Upper left corner.
  Point point;
  Size size;
  [[nodiscard]] Point upperLeft() const {return point;}
  [[nodiscard]] Point lowerRight() const {
    return {
      point.y - size.height,
      point.x + size.width
    };
  }
};

}

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_TRANSFORM_HPP_
