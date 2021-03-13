#include "sdl-input-transcriber.hpp"

#include <SDL.h>

lc::input::InputEvent Transcribe(SDL_Event& event) {
  const auto action = event.type == SDL_KEYDOWN ? lc::input::InputAction::K_DOWN
                                                : lc::input::InputAction::K_UP;

  switch (event.key.keysym.sym) {
    case SDLK_RIGHT:
      return {lc::input::InputType::K_NEXT, action};
    case SDLK_LEFT:
      return {lc::input::InputType::K_PREV, action};
    case SDLK_SPACE:
      return {lc::input::InputType::K_SELECT, action};
    default:
      return {lc::input::InputType::K_UNKNOWN, lc::input::InputAction::K_UNKNOWN};
  }
}

void sprinkler::sdl::SDLInputTranscriber::dispatchEvents() {
  while (SDL_PollEvent(&event_)) {
    switch (event_.type) {
      case SDL_QUIT:
        should_quit_ = true;
        break;
      case SDL_WINDOWEVENT:
        switch (event_.window.event) {
          case SDL_WINDOWEVENT_CLOSE:
            should_quit_ = true;
            break;
        }
        break;
      case SDL_KEYUP:
      case SDL_KEYDOWN:
        handler_->HandleInputEvent(Transcribe(event_));
        break;
    }
  }
}

bool sprinkler::sdl::SDLInputTranscriber::shouldQuit() const {
  return should_quit_;
}
