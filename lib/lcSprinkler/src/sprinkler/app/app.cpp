#include "app.hpp"

void sprinkler::app::App::init() {
//  const Size &size = display_->GetSize();
}
void sprinkler::app::App::tick() {
  display_->Clear();
  display_->Refresh();
}
InputEventHandler *sprinkler::app::App::GetInputEventHandler() {
  return nullptr;
}