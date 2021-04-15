#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_

namespace lc::gfx {

  typedef struct {
    uint8_t height;
    uint8_t width;
    uint8_t data[];
  } Icon;

}

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_ICONS_ICON_HPP_
