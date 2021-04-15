#include "components/info-bar.hpp"

#include <string>

#include "fonts/medium.h"
#include "fonts/small.h"

void sprinkler::CInfoBar::Draw(lc::gfx::Display* display) const {
  DrawSignalLevel(display);
//  lc::gfx::Point cursor{1, 13};
//  display->SetFont(lc::font::kFontSmall);
//  display->PrintText(cursor, "Sprinkler POOP", gfx::Color::K_BLACK);
//
//  display->SetFont(lc::font::kFontMedium);
//  cursor = lc::gfx::Point{1, 28};
//  display->PrintText(cursor, "Sprinkler POOP", gfx::Color::K_BLACK);
//  cursor = lc::gfx::Point{1, 44};
//  display->PrintText(cursor, "Sprinkler POOP", gfx::Color::K_BLACK);
//  cursor = lc::gfx::Point{1, 60};
//  display->PrintText(cursor, "Sprinkler POOP", gfx::Color::K_BLACK);
}

void sprinkler::CInfoBar::DrawSignalLevel(lc::gfx::Display* display) const {
  lc::gfx::Point cursor{120, 13};
  display->SetFont(lc::font::kFontMedium);
  display->PrintText(cursor, std::to_string(signal_level_), gfx::Color::K_BLACK);
}
