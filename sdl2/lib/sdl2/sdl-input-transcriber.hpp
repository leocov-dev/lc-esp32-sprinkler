#ifndef LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
#define LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_

#include "sprinkler/input/input-event-handler.hpp"

namespace sprinkler::sdl {

namespace input = sprinkler::input;

class SDLInputTranscriber {
 public:
  explicit SDLInputTranscriber(input::InputEventHandler *handler) : handler_(handler) {}

  void dispatchEvents();
  [[nodiscard]] bool shouldQuit() const;
 private:
  input::InputEventHandler *handler_;
  SDL_Event event_{};
  bool should_quit_ = false;
};

}  // namespace sprinkler::sdl

#endif //LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
