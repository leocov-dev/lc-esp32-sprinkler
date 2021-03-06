#include <SDL.h>

#include <sprinkler/app.hpp>
#include <sprinkler/constants.hpp>

#include "sdl2/sdl-display.hpp"
#include "sdl2/sdl-input-transcriber.hpp"
#include "sdl2/sdl-preferences.hpp"

namespace {
  namespace app = sprinkler::app;
  namespace sdl = sprinkler::sdl;
}  // namespace

int main() {
  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
  SDL_Log("Starting...");

  preferences::SDLPreferences prefs;
  auto restore_position = prefs.GetWindowPosition();

  sdl::SDLDisplay display(kDisplayHeight, kDisplayWidth, restore_position);
  app::App app(&display);
  sdl::SDLInputTranscriber input_transcriber(&app);

  while (!input_transcriber.shouldQuit()) {
    input_transcriber.dispatchEvents();
    app.Tick();
    SDL_Delay(10);  // required to prevent stalling draw thread
  }

  SDL_Log("Closing...");
  prefs.SaveWindowPosition(display.getWindow());
  SDL_Quit();
}