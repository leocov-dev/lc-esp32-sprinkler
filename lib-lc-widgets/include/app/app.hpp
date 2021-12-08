#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_APP_APP_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_APP_APP_HPP_

#include <vector>

#include "display/display.hpp"
#include "gfx/primitives/rect.hpp"
#include "gfx/primitives/transform.hpp"
#include "input/input-event-handler.hpp"
#include "widgets/widget.hpp"

namespace lc::app {

  /// Abstract base class for all UI display elements
  class App : public widget::Widget {
  public:
    explicit App(gfx::Display* display) : widget::Widget(display->GetSize()), display_(display){};
    //    using widget::Widget::HandleInputEvent;
    virtual void Tick() = 0;

  protected:
    gfx::Display* display_;

  private:
  };
}  // namespace lc::app

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_APP_APP_HPP_
