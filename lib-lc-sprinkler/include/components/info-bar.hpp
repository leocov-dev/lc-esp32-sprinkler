#ifndef LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_

#include "widgets/widget.hpp"

namespace sprinkler {

  namespace widget = lc::widget;
  namespace gfx = lc::gfx;

  class CInfoBar : public widget::Widget {
  public:
    using Widget::Widget;

    void SetSignalLevel(uint8_t level) { signal_level_ = level; };

  protected:
    void Draw(gfx::Display* display) const override;

  private:
    void DrawSignalLevel(gfx::Display* display) const;

    uint8_t signal_level_ = 0;
  };

}  // namespace sprinkler

#endif  // LC_ESP32_SPRINKLER_LIB_LC_SPRINKLER_INCLUDE_COMPONENTS_INFO_BAR_HPP_
