#include "ssd-1306-display.hpp"

sprinkler::gfx::Point sprinkler::esp::SSD1306Display::PutTextInternal(
    const sprinkler::gfx::Point &cursor,
    const std::string &text,
    const sprinkler::gfx::Color &fg) const {
  return gfx::Point(0, 0);
}
void sprinkler::esp::SSD1306Display::DrawPixelInternal(
    const sprinkler::gfx::Point &point,
    const sprinkler::gfx::Color &color) const {
}
void sprinkler::esp::SSD1306Display::DrawRectInternal(
    const sprinkler::gfx::Rect &rect,
    const sprinkler::gfx::Color &color) const {
}
void sprinkler::esp::SSD1306Display::FillRectInternal(
    const sprinkler::gfx::Rect &rect,
    const sprinkler::gfx::Color &color) const {
}
void sprinkler::esp::SSD1306Display::DrawCircleInternal(
    const sprinkler::gfx::Point &center,
    int radius,
    const sprinkler::gfx::Color &color) const {
}
void sprinkler::esp::SSD1306Display::FillCircleInternal(
    const sprinkler::gfx::Point &center,
    int radius,
    const sprinkler::gfx::Color &color) const {
}
void sprinkler::esp::SSD1306Display::Clear() {
}
void sprinkler::esp::SSD1306Display::Refresh() {
}
sprinkler::gfx::Size sprinkler::esp::SSD1306Display::GetCharSize() const {
  return sprinkler::gfx::Size{5, 8};
}
