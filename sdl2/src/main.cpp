#include <SDL.h>

#include <sprinkler/app.hpp>

#include "sdl2/sdl-display.hpp"
#include "sdl2/sdl-input-transcriber.hpp"
#include "sdl2/sdl-preferences.hpp"

namespace {
  namespace sdl = sprinkler::sdl;
}  // namespace

int main() {
  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
  SDL_Log("Starting...");

  preferences::SdlPreferences prefs;
  auto restore_position = prefs.GetWindowPosition();

  sdl::SdlDisplay display(64, 128, restore_position);
  sprinkler::App app(&display);
  sdl::SdlInputTranscriber input_transcriber(&app);

  while (!input_transcriber.ShouldQuit()) {
    input_transcriber.DispatchEvents();
    app.Tick();
    SDL_Delay(250);  // required to prevent stalling draw thread
  }

  SDL_Log("Closing...");
  prefs.SaveWindowPosition(display.GetWindow());
  SDL_Quit();
}