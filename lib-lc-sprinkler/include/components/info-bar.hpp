#ifndef LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_

#include <algorithm>

#include "widgets/widget.hpp"

namespace sprinkler {

  namespace widget = lc::widget;
  namespace gfx = lc::gfx;
  namespace input = lc::input;

  class CInfoBar : public widget::Widget {
  public:
    using Widget::Widget;

  protected:
    void Draw(gfx::Display* display) override;
    void ProcessInputEvent(input::InputEvent* event) override;
    void SetSignalLevel(int level);

  private:
    int signal_level_ = 0;
  };

}  // namespace sprinkler

#endif  // LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
