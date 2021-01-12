#include "w-frame.hpp"

void sprinkler::widget::WFrame::Draw(sprinkler::gfx::Display *display) const {
  display->DrawRect(GetRect(), gfx::Color::K_BLACK);
}
