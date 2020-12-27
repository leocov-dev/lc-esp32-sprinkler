#include <SDL.h>
#include "sdl-input-transcriber.hpp"

using namespace sprinkler::input;

InputEvent Transcribe(SDL_Event &event) {
  const auto action = event.type == SDL_KEYDOWN ? InputAction::kDown : InputAction::kUp;

  switch (event.key.keysym.sym) {
    case SDLK_RIGHT:
      return {
          InputType::kNext,
          action
      };
    case SDLK_LEFT:
      return {
          InputType::kPrev,
          action
      };
    case SDLK_SPACE:
      return {
          InputType::kSelect,
          action
      };
    default:
      return {
          InputType::kUnknown,
          InputAction::kUnknown
      };
  }
}

void SDLInputTranscriber::DispatchEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      should_quit_ = true;
    } else if (event_.type == SDL_KEYDOWN ||
        event_.type == SDL_KEYUP) {
      if (handler_ != nullptr) {
        handler_->HandleInputEvent(Transcribe(event_));
      }
    }
  }
}
bool SDLInputTranscriber::ShouldQuit() {
  return should_quit_;
}
