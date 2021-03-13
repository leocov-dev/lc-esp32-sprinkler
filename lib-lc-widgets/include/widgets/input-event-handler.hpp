#ifndef LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HANDLER_HPP_
#define LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HANDLER_HPP_

#include "input-event.hpp"

namespace lc::input {

class InputEventHandler {
 public:
  virtual ~InputEventHandler() = default;
  virtual void HandleInputEvent(InputEvent event) = 0;
};

}  // namespace input

#endif  // LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HANDLER_HPP_
