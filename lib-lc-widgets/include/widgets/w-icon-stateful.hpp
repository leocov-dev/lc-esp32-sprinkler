#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_

#include "widget.hpp"
#include "w-icon.hpp"

namespace lc::widget {

  template <uint8_t height, uint8_t width>
  class WIconStateful : public Widget, WIcon<height, width> {
  public:
    using Widget::Widget;
    explicit WIconStateful(gfx::Image<height, width> icons...);

//  private:
//    std::vector<gfx::Icon<height, width> *> iconList_;

  protected:
    void Draw(gfx::Display* display) const override;
  };

  template <uint8_t height, uint8_t width>
  void WIconStateful<height, width>::Draw(gfx::Display* display) const {}

  template <uint8_t height, uint8_t width>
  WIconStateful<height, width>::WIconStateful(gfx::Image<height, width> icons, ...) {}
}  // namespace lc::widget
#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_
