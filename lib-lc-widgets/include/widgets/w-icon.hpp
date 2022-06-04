//
// Created by leocov on 12/4/21.
//

#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_HPP_

#include "gfx/primitives/point.hpp"
#include "gfx/image.hpp"
#include "widget.hpp"

namespace lc::widget {

  template <uint8_t height, uint8_t width> class WIcon : public Widget {
  public:
    WIcon() : Widget(gfx::Size{height, width}){};
    explicit WIcon(gfx::Image<height, width> icon) : Widget(gfx::Size{height, width}), icon_(icon){};

  protected:
    void Draw(gfx::Display* display) override;

  private:
    gfx::Image<height, width> icon_;
  };

  template <uint8_t height, uint8_t width>
  void WIcon<height, width>::Draw(gfx::Display* display) {
    display->template DrawImage(GetOrigin(), icon_);
  }

}  // namespace lc::widget

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_HPP_
