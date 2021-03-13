#include "widgets/widget.hpp"

#include "widgets/display.hpp"
#include "widgets/input-event.hpp"
#include "widgets/transform.hpp"

namespace {
  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
}

void widget::Widget::HandleInputEvent(input::InputEvent event) {
  for (auto child : children_) {
    child->HandleInputEvent(event);
  }
  ProcessInputEvent(event);
}

void widget::Widget::SetParent(widget::Widget* parent) {
  parent_ = parent;
  parent_->children_.push_back(this);
}

void widget::Widget::Render(gfx::Display* display) {
  Draw(display);
  for (auto child : children_) {
    // child widgets are rendered in the context of their parent
    display->PushWidgetContext(GetRect());
    child->Render(display);
    display->PopWidgetContext();
  }
}

gfx::Rect widget::Widget::GetRect() const {
  return gfx::Rect{origin_, size_};
}

void widget::Widget::SetLocalPosition(gfx::Point position) {
  origin_ = position;
}
