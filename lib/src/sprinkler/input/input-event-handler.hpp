#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_

#include "input-event.hpp"

namespace sprinkler::input {

class InputEventHandler {
 public:
  virtual ~InputEventHandler() = default;
  virtual void handleInputEvent(InputEvent event) = 0;
};

}  // namespace input

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_
