#include "sprinkler/widget.hpp"

#include "sprinkler/display.hpp"
#include "sprinkler/transform.hpp"
#include "sprinkler/input-event.hpp"

void sprinkler::widget::Widget::HandleInputEvent(sprinkler::input::InputEvent event) {
  for (auto child : children_) {
    child->HandleInputEvent(event);
  }
  ProcessInputEvent(event);
}

void sprinkler::widget::Widget::SetParent(sprinkler::widget::Widget* parent) {
  parent_ = parent;
  parent_->children_.push_back(this);
}

void sprinkler::widget::Widget::Render(sprinkler::gfx::Display* display) {
  Draw(display);
  for (auto child : children_) {
    // child widgets are rendered in the context of their parent
    display->PushWidgetContext(GetRect());
    child->Render(display);
    display->PopWidgetContext();
  }
}

sprinkler::gfx::Rect sprinkler::widget::Widget::GetRect() const {
  return sprinkler::gfx::Rect{origin_, size_};
}

void sprinkler::widget::Widget::SetLocalPosition(sprinkler::gfx::Point position) {
  origin_ = position;
}
