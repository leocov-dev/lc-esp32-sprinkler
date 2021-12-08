#include "sprinkler/app.hpp"

#include <iostream>

#include "app/app.hpp"

namespace {
  namespace gfx = lc::gfx;
}

void sprinkler::App::Tick() {
  display_->Clear();
  Render(display_);
  display_->Refresh();
}

// void lc::app::App::ProcessInputEvent(lc::input::InputEvent* event) {
//   std::cout << event << std::endl;
// }
