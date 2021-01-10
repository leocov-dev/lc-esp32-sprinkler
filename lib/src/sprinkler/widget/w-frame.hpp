#ifndef LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_WIDGET_W_FRAME_HPP_
#define LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_WIDGET_W_FRAME_HPP_

#include "widget.hpp"

namespace sprinkler::widget {

class WFrame : public Widget {
 public:
  using Widget::Widget;
 protected:
  void draw(gfx::Display *display) const override;
};

}

#endif //LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_WIDGET_W_FRAME_HPP_
