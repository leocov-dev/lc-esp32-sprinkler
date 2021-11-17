#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_

namespace lc::gfx {

  template <uint8_t height, uint8_t width>
  struct Icon {
    static const uint8_t k_height = height;
    static const uint8_t k_width = width;
    static const uint16_t size = k_height * k_width;
    const uint8_t data[size];
  };

}

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_
