#include "sprinkler/app.hpp"
#include "app/app.hpp"
#include <iostream>

namespace {
namespace gfx = lc::gfx;
}

void sprinkler::App::Tick() {
  display_->Clear();
  Render(display_);
  display_->Refresh();
}

void sprinkler::App::Draw(gfx::Display *display) {
  info_bar_->SetParent(this);
}

void lc::app::App::ProcessInputEvent(lc::input::InputEvent* event) {
//  std::cout << event << std::endl;
}
