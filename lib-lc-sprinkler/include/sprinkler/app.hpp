#ifndef LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_

#include <memory>

#include "components/info-bar.hpp"
#include "widgets/display.hpp"
#include "widgets/w-frame.hpp"
#include "widgets/widget.hpp"

namespace sprinkler {

  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
  namespace input = lc::input;

  class App : public widget::Widget {
  public:
    explicit App(gfx::Display* display) : widget::Widget(display->GetSize()), display_(display) {
      Init();
    };
    using widget::Widget::HandleInputEvent;
    void Tick();
    void Init();

  protected:
    void Draw(gfx::Display* display) const override;

  private:
    gfx::Display* display_;

    std::unique_ptr<sprinkler::CInfoBar> info_bar_ = std::make_unique<sprinkler::CInfoBar>(
        gfx::Size{display_->GetSize().width, display_->GetSize().height / 4});
  };

}  // namespace sprinkler

#endif  // LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_
