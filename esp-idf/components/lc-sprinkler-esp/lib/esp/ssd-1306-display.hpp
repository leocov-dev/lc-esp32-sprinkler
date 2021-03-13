#ifndef LC_ESP32_SPRINKLER_ESP_IDF_COMPONENTS_SPRINKLER_ESP_SSD_1306_DISPLAY_HPP_
#define LC_ESP32_SPRINKLER_ESP_IDF_COMPONENTS_SPRINKLER_ESP_SSD_1306_DISPLAY_HPP_

#include "widgets/display.hpp"

namespace sprinkler::esp {

namespace gfx = sprinkler::gfx;

class SSD1306Display : public  gfx::Display {
 public:
  SSD1306Display(int width, int height) : Display(width, height) {}
  void Clear() override;
  void Refresh() override;

 private:
  void DrawPixelInternal(const gfx::Point &point, const gfx::Color &color) const override;
  void DrawRectInternal(const gfx::Rect &rect, const gfx::Color &color) const override;
  void FillRectInternal(const gfx::Rect &rect, const gfx::Color &color) const override;
  void DrawCircleInternal(const gfx::Point &center, int radius, const gfx::Color &color) const override;
  void FillCircleInternal(const gfx::Point &center, int radius, const gfx::Color &color) const override;
  ;
};

}

#endif//LC_ESP32_SPRINKLER_ESP_IDF_COMPONENTS_SPRINKLER_ESP_SSD_1306_DISPLAY_HPP_
