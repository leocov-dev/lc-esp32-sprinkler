#include "widgets/w-frame.hpp"

namespace {
  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
}

void widget::WFrame::Draw(gfx::Display* display) const {
  display->DrawRect(GetRect(), gfx::Color::K_BLACK);
}
