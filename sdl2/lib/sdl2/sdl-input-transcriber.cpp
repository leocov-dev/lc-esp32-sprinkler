#include <SDL.h>
#include "sdl-input-transcriber.hpp"

sprinkler::input::InputEvent Transcribe(SDL_Event &event) {
  const auto action = event.type == SDL_KEYDOWN ? sprinkler::input::InputAction::kDown : sprinkler::input::InputAction::kUp;

  switch (event.key.keysym.sym) {
    case SDLK_RIGHT:
      return {
          sprinkler::input::InputType::kNext,
          action
      };
    case SDLK_LEFT:
      return {
          sprinkler::input::InputType::kPrev,
          action
      };
    case SDLK_SPACE:
      return {
          sprinkler::input::InputType::kSelect,
          action
      };
    default:
      return {
          sprinkler::input::InputType::kUnknown,
          sprinkler::input::InputAction::kUnknown
      };
  }
}

void sprinkler::sdl::SDLInputTranscriber::dispatchEvents() {
  while (SDL_PollEvent(&event_)) {
    switch (event_.type) {
      case SDL_QUIT:should_quit_ = true;
        break;
      case SDL_WINDOWEVENT:
        switch (event_.window.event) {
          case SDL_WINDOWEVENT_CLOSE:should_quit_ = true;
            break;
        }
        break;
      case SDL_KEYUP:
      case SDL_KEYDOWN:
        handler_->handleInputEvent(Transcribe(event_));
        break;
    }
  }
}

bool sprinkler::sdl::SDLInputTranscriber::shouldQuit() const {
  return should_quit_;
}
