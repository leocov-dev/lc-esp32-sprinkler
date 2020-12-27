#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_

namespace sprinkler::input {

enum class InputType {
  kUnknown,
  kPrev,
  kNext,
  kSelect,
};

enum class InputAction {
  kUnknown,
  kUp,
  kDown,
};

struct InputEvent {
  InputType type;
  InputAction action;
};

class InputEventHandler {
 public:
  virtual ~InputEventHandler() = default;
  virtual void HandleInputEvent(InputEvent event) = 0;
};

}  // namespace input

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_INPUT_INPUT_EVENT_HANDLER_HPP_
