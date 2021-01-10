#include "w-frame.hpp"

void sprinkler::widget::WFrame::draw(sprinkler::gfx::Display *display) const {
  display->drawRect(getRect(), gfx::Color::kBlack);
}
