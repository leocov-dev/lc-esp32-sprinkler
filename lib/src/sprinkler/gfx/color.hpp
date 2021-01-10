#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_COLOR_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_COLOR_HPP_

#include <iostream>

namespace sprinkler::gfx {

enum class Color {
  kBlack,
  kWhite,
  kDebugRed,
  kDebugGreen,
  kDebugBlue
};

inline std::ostream& operator<<(std::ostream& os, const Color& color) {
  switch (color) {
    case Color::kBlack:
      return os << "Color::kBlack";
    case Color::kWhite:
      return os << "Color::kWhite";
    case Color::kDebugRed:
      return os << "Color::kDebugRed";
    case Color::kDebugGreen:
      return os << "Color::kDebugGreen";
    case Color::kDebugBlue:
      return os << "Color::kDebugBlue";
    default:
      return os << "Color::unknown";
  }
}

}

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_COLOR_HPP_
