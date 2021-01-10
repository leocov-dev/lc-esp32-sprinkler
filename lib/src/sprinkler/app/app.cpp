#include "app.hpp"
#include "sprinkler/gfx/display.hpp"
#include "sprinkler/gfx/color.hpp"
#include "ada-font/FreeMono9pt7b.h"


void sprinkler::app::App::init() {
//  box1_->SetParent(this);
//  box1_->SetLocalPosition(sprinkler::gfx::Point{1, 10});
//  box2_->SetParent(this);
//  box2_->SetLocalPosition(sprinkler::gfx::Point{10, 20});
//  box3_->SetParent(this);
//  box3_->SetLocalPosition(sprinkler::gfx::Point{50, 10});
//  box4_->SetParent(box3_.get());
//  box4_->SetLocalPosition(sprinkler::gfx::Point{1, 1});
}

void sprinkler::app::App::tick() {
  display_->clear();
  render(display_);

  {
    sprinkler::gfx::Point cursor{1, 15};
    display_->setFont(FreeMono9pt7b);
    display_->printText(cursor, "Hello World", sprinkler::gfx::Color::kBlack);
  }

  display_->refresh();
}

void sprinkler::app::App::draw(sprinkler::gfx::Display *display) const {
  // NOTE: Intentional NOOP to just draw 'transparent'
}
