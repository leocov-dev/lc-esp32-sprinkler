#ifndef LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
#define LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_

#include "sprinkler/input/input-event-handler.hpp"

using namespace sprinkler::input;

class SDLInputTranscriber {
 public:
  explicit SDLInputTranscriber(InputEventHandler *handler) : handler_(handler) {}
  void DispatchEvents();
  bool ShouldQuit();
 private:
  InputEventHandler *handler_;
  SDL_Event event_{};
  bool should_quit_ = false;
};

#endif //LCESP32SPRINKLER_SDL2_LIB_SDL2_SDL_INPUT_TRANSCRIBER_HPP_
