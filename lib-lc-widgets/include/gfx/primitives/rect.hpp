#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_RECT_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_RECT_HPP_

#include "transform.hpp"

namespace lc::gfx {
  struct Rect {
    // Upper left corner.
    Point origin;
    Size size;

    [[nodiscard]] Point UpperLeft() const { return origin; }

    [[nodiscard]] Point LowerRight() const {
      return {origin.y - size.height, origin.x + size.width};
    }
  };
  inline std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os, const Rect& rect) {
    return os << "Rect{ "
              << "origin: (" << rect.origin.x << ", " << rect.origin.y << ") "
              << "size: (" << rect.size.width << ", " << rect.size.height << ")"
              << " }";
  }
}  // namespace lc::gfx
#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_GFX_PRIMITIVES_RECT_HPP_
