#include "sprinkler/app.hpp"

namespace {
namespace gfx = lc::gfx;
}

void sprinkler::App::Init() {
  info_bar_->SetParent(this);
}

void sprinkler::App::Tick() {
  display_->Clear();
  Render(display_);
  display_->Refresh();
}

void sprinkler::App::Draw(gfx::Display *display) const {
  // NOTE: Intentional NOOP to just draw 'transparent'
}
