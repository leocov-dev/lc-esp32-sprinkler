#include "widget.hpp"
#include "sprinkler/input/input-event.hpp"
#include "sprinkler/gfx/display.hpp"
#include "sprinkler/gfx/transform.hpp"

void sprinkler::widget::Widget::handleInputEvent(sprinkler::input::InputEvent event) {
  for (auto child : children_) {
    child->handleInputEvent(event);
  }
  processInputEvent(event);
}

void sprinkler::widget::Widget::setParent(sprinkler::widget::Widget *parent) {
  parent_ = parent;
  parent_->children_.push_back(this);
}

void sprinkler::widget::Widget::render(sprinkler::gfx::Display *display) {
  draw(display);
  for (auto child : children_) {
    // child widgets are rendered in the context of their parent
    display->pushWidgetContext(getRect());
    child->render(display);
    display->popWidgetContext();
  }
}

sprinkler::gfx::Rect sprinkler::widget::Widget::getRect() const {
  return sprinkler::gfx::Rect{origin_, size_};
}

void sprinkler::widget::Widget::setLocalPosition(sprinkler::gfx::Point position) {
  origin_ = position;
}
