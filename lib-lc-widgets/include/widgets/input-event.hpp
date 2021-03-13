#ifndef LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HPP_
#define LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HPP_

#include <cstdint>

namespace lc::input {

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

#endif  // LCWIDGETS_LIB_LC_WIDGETS_INCLUDE_INPUT_EVENT_HPP_
