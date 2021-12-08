#ifndef LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_

#include <algorithm>
#include <memory>

#include "constants/icons/wifi.hpp"
#include "widgets/w-icon.hpp"
#include "widgets/widget.hpp"

namespace sprinkler {

  namespace widget = lc::widget;
  namespace gfx = lc::gfx;
  namespace input = lc::input;

  class CInfoBar : public widget::Widget {
  public:
    explicit CInfoBar(gfx::Size size) : widget::Widget(size) {
      signal_icon_ = std::make_unique<widget::WIcon<16, 16>>(kWifiFullSignal);
      signal_icon_->SetParent(this);
    };

  protected:
    void Draw(gfx::Display* display) override;
    void ProcessInputEvent(input::InputEvent* event) override;
    void SetSignalLevel(int level);

  private:
    int signal_level_ = 0;
    std::unique_ptr<widget::WIcon<16, 16>> signal_icon_;
  };

}  // namespace sprinkler

#endif  // LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
