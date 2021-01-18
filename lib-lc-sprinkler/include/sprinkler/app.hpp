#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_APP_APP_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_APP_APP_HPP_

#include <memory>

#include "sprinkler/display.hpp"
#include "sprinkler/input-event-handler.hpp"
#include "sprinkler/w-frame.hpp"

namespace sprinkler::app {

  namespace gfx = sprinkler::gfx;
  namespace widget = sprinkler::widget;
  namespace input = sprinkler::input;

  class App : public widget::Widget {
  public:
    explicit App(gfx::Display* display) : widget::Widget(display->GetSize()), display_(display){};
    using widget::Widget::HandleInputEvent;
    void Tick();

  protected:
    void Draw(gfx::Display* display) const override;

  private:
    gfx::Display* display_;

    std::unique_ptr<widget::WFrame> box1_ = std::make_unique<widget::WFrame>(gfx::Size{10, 10});
    std::unique_ptr<widget::WFrame> box2_ = std::make_unique<widget::WFrame>(gfx::Size{10, 10});
    std::unique_ptr<widget::WFrame> box3_ = std::make_unique<widget::WFrame>(gfx::Size{50, 50});
    std::unique_ptr<widget::WFrame> box4_ = std::make_unique<widget::WFrame>(gfx::Size{10, 10});
  };

}  // namespace sprinkler::app

#endif  // LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_APP_APP_HPP_
