#ifndef LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_INPUT_INPUT_EVENT_HPP_
#define LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_INPUT_INPUT_EVENT_HPP_

#include <cstdint>
#include <ostream>

namespace lc::input {

  enum class InputType {
    K_UNKNOWN,
    K_PREV,
    K_NEXT,
    K_SELECT,
  };

  constexpr const char* InputTypeToString(InputType e) noexcept {
    switch (e) {
      case InputType::K_UNKNOWN:
        return "UNKNOWN";
      case InputType::K_PREV:
        return "PREV";
      case InputType::K_NEXT:
        return "NEXT";
      case InputType::K_SELECT:
        return "SELECT";
      default:
        return "DEFAULT";
    }
  }

  enum class InputAction {
    K_UNKNOWN,
    K_UP,
    K_DOWN,
  };

  constexpr const char* InputActionToString(InputAction e) noexcept {
    switch (e) {
      case InputAction::K_UNKNOWN:
        return "UNKNOWN";
      case InputAction::K_UP:
        return "UP";
      case InputAction::K_DOWN:
        return "DOWN";
      default:
        return "DEFAULT";
    }
  }

  struct InputEvent {
    InputType type;
    InputAction action;
    bool consumed;

    void Consume() { consumed = true; }
  };

  inline std::ostream& operator<<(std::ostream& os, InputEvent const& arg) {
    return os << "type: " << InputTypeToString(arg.type)
              << ", action: " << InputActionToString(arg.action) << ", handled: " << arg.consumed;
  }

}  // namespace lc::input

#endif  // LC_ESP32_SPRINKLER_LIB_LC_WIDGETS_INCLUDE_INPUT_INPUT_EVENT_HPP_
