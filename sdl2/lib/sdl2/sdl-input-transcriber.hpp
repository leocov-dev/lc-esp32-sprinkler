#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_

#include <SDL.h>

#include "input/input-event-handler.hpp"

namespace {
  namespace input = lc::input;
}

namespace sprinkler::sdl {

  class SdlInputTranscriber {
  public:
    explicit SdlInputTranscriber(input::InputEventHandler* handler) : handler_(handler) {}

    void DispatchEvents();
    [[nodiscard]] bool ShouldQuit() const;

  private:
    input::InputEventHandler* handler_;
    SDL_Event event_{};
    bool should_quit_ = false;
  };

}  // namespace sprinkler::sdl

#endif  // LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
