#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_COLOR_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_COLOR_HPP_

#include <iostream>

namespace sprinkler::gfx {

enum class Color {
  K_BLACK,
  K_WHITE,
  K_DEBUG_RED,
  K_DEBUG_GREEN,
  K_DEBUG_BLUE
};

inline std::ostream& operator<<(std::ostream& os, const Color& color) {
  switch (color) {
    case Color::K_BLACK:
      return os << "Color::kBlack";
    case Color::K_WHITE:
      return os << "Color::kWhite";
    case Color::K_DEBUG_RED:
      return os << "Color::kDebugRed";
    case Color::K_DEBUG_GREEN:
      return os << "Color::kDebugGreen";
    case Color::K_DEBUG_BLUE:
      return os << "Color::kDebugBlue";
    default:
      return os << "Color::unknown";
  }
}

}

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_COLOR_HPP_
