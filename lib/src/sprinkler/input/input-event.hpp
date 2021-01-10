#ifndef LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_EVENTS_INPUT_EVENT_HPP_
#define LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_EVENTS_INPUT_EVENT_HPP_

#include <cstdint>

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
  bool consumed;
};

}

#endif //LC_ESP32_SPRINKLER_LIB_LCSPRINKLER_SRC_SPRINKLER_EVENTS_INPUT_EVENT_HPP_
