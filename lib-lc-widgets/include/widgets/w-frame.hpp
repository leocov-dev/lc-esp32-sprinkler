#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_FRAME_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_FRAME_HPP_

#include "widget.hpp"

namespace lc::widget {

  class WFrame : public Widget {
  public:
    using Widget::Widget;

  protected:
    void Draw(gfx::Display* display) override;
  };

}  // namespace lc::widget

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_FRAME_HPP_
