#include "app.hpp"
#include "sprinkler/gfx/display.hpp"
#include "sprinkler/gfx/color.hpp"
#include "ada-font/FreeMono9pt7b.h"

namespace {
namespace app = sprinkler::app;
namespace gfx = sprinkler::gfx;
}

//void sprinkler::app::App::init() {
//  box1_->SetParent(this);
//  box1_->SetLocalPosition(sprinkler::gfx::Point{1, 10});
//  box2_->SetParent(this);
//  box2_->SetLocalPosition(sprinkler::gfx::Point{10, 20});
//  box3_->SetParent(this);
//  box3_->SetLocalPosition(sprinkler::gfx::Point{50, 10});
//  box4_->SetParent(box3_.get());
//  box4_->SetLocalPosition(sprinkler::gfx::Point{1, 1});
//}

void app::App::Tick() {
  display_->Clear();
  Render(display_);

  {
    sprinkler::gfx::Point cursor{1, 15};
    display_->SetFont(FreeMono9pt7b);
    display_->PrintText(cursor, "Hello World", gfx::Color::K_BLACK);
  }

  display_->Refresh();
}

void app::App::Draw(gfx::Display *display) const {
  // NOTE: Intentional NOOP to just draw 'transparent'
}
