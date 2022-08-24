#include "components/info-bar.hpp"

#include <string>

#include "fonts/medium.h"
#include "fonts/small.h"
#include "gfx/primitives/point.hpp"
#include "widgets/w-icon.hpp"

void sprinkler::CInfoBar::Draw(lc::gfx::Display* display) {
  lc::gfx::Point cursor{110, 0};
  w_signal_icon_->SetLocalPosition(cursor);
  cursor = lc::gfx::Point{80, 0};
  w_signal_->SetLocalPosition(cursor);

  cursor = lc::gfx::Point{1, 13};
  display->SetFont(lc::font::kFontSmall);
  display->PrintText(cursor, "Signal: " + std::to_string(signal_level_), gfx::Color::K_BLACK);

  display->SetFont(lc::font::kFontMedium);
  cursor = lc::gfx::Point{1, 28};
  display->PrintText(cursor, "Sprinkler B", gfx::Color::K_BLACK);
  cursor = lc::gfx::Point{1, 44};
  display->PrintText(cursor, "Sprinkler C", gfx::Color::K_BLACK);
  cursor = lc::gfx::Point{1, 60};
  display->PrintText(cursor, "Sprinkler D", gfx::Color::K_BLACK);
}

void sprinkler::CInfoBar::ProcessInputEvent(input::InputEvent* event) {
  if (event->action != input::InputAction::K_DOWN) {
    switch (event->type) {
      case input::InputType::K_NEXT:
        SetSignalLevel(signal_level_ + 1);
        event->Consume();
        break;
      case input::InputType::K_PREV:
        SetSignalLevel(signal_level_ - 1);
        event->Consume();
        break;
      default:
        break;
    }
  }
}

void sprinkler::CInfoBar::SetSignalLevel(int level) {
  signal_level_ = std::clamp<int>(level, 0, 3);
  w_signal_->SetState(signal_level_);
}
