#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HANDLER_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HANDLER_HPP_

#include "input-event.hpp"

namespace sprinkler::input {

class InputEventHandler {
 public:
  virtual ~InputEventHandler() = default;
  virtual void HandleInputEvent(InputEvent event) = 0;
};

}  // namespace input

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HANDLER_HPP_
