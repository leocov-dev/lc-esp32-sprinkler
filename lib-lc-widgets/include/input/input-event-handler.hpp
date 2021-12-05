#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_INPUT_EVENT_HANDLER_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_INPUT_EVENT_HANDLER_HPP_

#include "input-event.hpp"

namespace lc::input {

  class InputEventHandler {
  public:
    virtual ~InputEventHandler() = default;
    virtual void HandleInputEvent(InputEvent* event) = 0;
  };

}  // namespace lc::input

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_WIDGETS_INPUT_EVENT_HANDLER_HPP_
