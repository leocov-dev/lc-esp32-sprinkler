#include "widgets/w-frame.hpp"
#include "icons/wifi.hpp"

namespace {
  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
}

void widget::WFrame::Draw(gfx::Display* display) const {
  display->DrawRect(GetRect(), gfx::Color::K_DEBUG_GREEN);
  display->DrawIcon(GetRect().UpperLeft(), WifiFullSignal16);
}
