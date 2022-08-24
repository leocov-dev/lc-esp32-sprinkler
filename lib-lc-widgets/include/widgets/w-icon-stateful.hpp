#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_

#include "gfx/primitives/point.hpp"
#include "gfx/image.hpp"
#include "w-icon.hpp"
#include "widget.hpp"

namespace lc::widget {

  template <uint8_t states, uint8_t height, uint8_t width>
  class WIconStateful : public WIcon<height, width> {
  public:
    explicit WIconStateful(std::array<gfx::Image<height, width>, states> icons)
        : WIcon<height, width>(), icon_list_(icons), states_(states){};

    using WIcon<height, width>::GetOrigin;

    void SetState(uint8_t state);

  protected:
    void Draw(gfx::Display* display) override;

  private:
    std::array<gfx::Image<height, width>, states> icon_list_;
    uint8_t states_;
    uint8_t current_state_ = 0;
  };

  template <uint8_t states, uint8_t height, uint8_t width>
  void WIconStateful<states, height, width>::Draw(gfx::Display* display) {
    display->template DrawImage( GetOrigin(), icon_list_[current_state_]);
  }

  template <uint8_t states, uint8_t height, uint8_t width>
  void WIconStateful<states, height, width>::SetState(uint8_t state) {
    current_state_ = std::clamp<uint8_t>(state, 0, states-1);
  }

}  // namespace lc::widget
#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_W_ICON_STATEFUL_HPP_
