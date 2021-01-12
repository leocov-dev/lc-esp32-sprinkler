#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HPP_

#include <cstdint>

namespace sprinkler::input {

enum class InputType {
  K_UNKNOWN,
  K_PREV,
  K_NEXT,
  K_SELECT,
};

enum class InputAction {
  K_UNKNOWN,
  K_UP,
  K_DOWN,
};

struct InputEvent {
  InputType type;
  InputAction action;
  bool consumed;
};

}

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_INPUT_INPUT_EVENT_HPP_
