#ifndef LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_W_FRAME_HPP_
#define LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_W_FRAME_HPP_

#include "widget.hpp"

namespace lc::widget {

class WFrame : public Widget {
 public:
  using Widget::Widget;
 protected:
  void Draw(gfx::Display *display) const override;
};

}

#endif  // LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_W_FRAME_HPP_
