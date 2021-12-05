#ifndef LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_

#include <memory>

#include "components/info-bar.hpp"
#include "display/display.hpp"
#include "widgets/w-frame.hpp"
#include "widgets/widget.hpp"
#include "app/app.hpp"

namespace sprinkler {

  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
  namespace input = lc::input;
  namespace app = lc::app;

  class App : public app::App {
  public:
    using app::App::App;
    void Tick() override;

  protected:
    void Draw(gfx::Display* display) override;

  private:
    std::unique_ptr<sprinkler::CInfoBar> info_bar_ = std::make_unique<sprinkler::CInfoBar>(
        gfx::Size{display_->GetSize().width, display_->GetSize().height / 4});
  };

}  // namespace sprinkler

#endif  // LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_SPRINKLER_APP_HPP_
