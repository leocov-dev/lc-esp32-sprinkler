#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_WIDGET_WIDGET_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_WIDGET_WIDGET_HPP_

#include <vector>
#include "sprinkler/input/input-event-handler.hpp"
#include "sprinkler/input/input-event.hpp"
#include "sprinkler/gfx/display.hpp"

namespace sprinkler::widget {

/// Abstract base class for all UI display elements
class Widget : public input::InputEventHandler {
 public:
  explicit Widget(gfx::Size size) : size_(size) {};

  void HandleInputEvent(input::InputEvent event) override;
  void SetParent(Widget *parent);
  void Render(gfx::Display *display);
  [[nodiscard]] gfx::Rect GetRect() const;

  /// This sets the position of the widget relative to its parent.
  /// The default origin is (0, 0)
  /// \sa Widget.origin_
  /// \param position
  void SetLocalPosition(gfx::Point position);
 protected:
  /// Draw function handles actual pixels of the widget and
  /// MUST be implemented on all subclasses
  virtual void Draw(gfx::Display *display) const = 0;

  /// widgets by default will ignore InputEvents
  /// subclasses should implement this if they need to
  /// utilize or change based on these events
  void ProcessInputEvent(const input::InputEvent &event) {};
  Widget *parent_ = nullptr;
  std::vector<Widget *> children_;
  gfx::Point origin_{0, 0};
  gfx::Size size_;
};

}

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_WIDGET_WIDGET_HPP_
