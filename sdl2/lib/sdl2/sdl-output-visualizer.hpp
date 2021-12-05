#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_OUTPUT_VISUALIZER_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_OUTPUT_VISUALIZER_HPP_

#include <SDL.h>

#include <memory>

#include "sdl-utils.hpp"

// For visualizing the state of the sprinkler valve relays
//
class SdlOutputVisualizer {
public:
  SdlOutputVisualizer(int x, int y);
  void Clear();
  void Refresh();
  void BindToWindow(SDL_Window *window);
  SDL_Window *GetWindow();
  void Tick();

private:
  std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer_;
  std::unique_ptr<SDL_Window, SDLWindowDeleter> window_;
  SDL_Window *bound_window_ = nullptr;
};

#endif  // LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_OUTPUT_VISUALIZER_HPP_
