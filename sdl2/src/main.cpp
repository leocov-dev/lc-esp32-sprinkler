#include "SDL.h"
#include "sdl2/sdl-display.hpp"
#include "sdl2/sdl-input-transcriber.hpp"
#include "sprinkler/app/app.hpp"

using namespace sprinkler::app;

constexpr char kFontPath[] = "./assets/fonts/DejaVu/DejaVuSansMono.ttf";
constexpr int kDisplayHeight = 64;
constexpr int kDisplayWidth = 128;

int main() {

  SDLDisplay display(kDisplayHeight, kDisplayWidth, kFontPath);
  App app(&display);
  app.init();

  SDLInputTranscriber input_transcriber(app.GetInputEventHandler());

  while (!input_transcriber.ShouldQuit()) {
    input_transcriber.DispatchEvents();
    app.tick();
    SDL_Delay(10);
  }
}