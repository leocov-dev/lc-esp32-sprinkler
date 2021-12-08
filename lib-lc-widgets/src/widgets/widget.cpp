#include "widgets/widget.hpp"

#include "display/display.hpp"
#include "gfx/primitives/point.hpp"
#include "gfx/primitives/rect.hpp"
#include "input/input-event.hpp"

namespace {
  namespace gfx = lc::gfx;
  namespace widget = lc::widget;
}  // namespace

void widget::Widget::HandleInputEvent(input::InputEvent* event) {
  ProcessInputEvent(event);

  if (event->consumed) return;

  for (auto child : children_) {
    child->HandleInputEvent(event);
  }
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

gfx::Point widget::Widget::GetOrigin() const {
  return origin_;
}
