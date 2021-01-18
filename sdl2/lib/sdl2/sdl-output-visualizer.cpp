#include "sdl-output-visualizer.hpp"

#include <iostream>

#include "sdl-constants.hpp"
#include "sdl-utils.hpp"
#include "sdl-window-icon.hpp"

SDLOutputVisualizer::SDLOutputVisualizer(int x, int y) {
  window_ = std::unique_ptr<SDL_Window, SDLWindowDeleter>(
      SDL_CreateWindow("lcSprinkler", x, y, 128 * kDisplayScaleFactor, 16 * kDisplayScaleFactor,
                       SDL_WINDOW_SHOWN + SDL_WINDOW_BORDERLESS));

  if (window_ == nullptr) {
    std::cerr << "Unable to initialize window\n";
    exit(-1);
  }

  auto icon_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(SDL_CreateRGBSurfaceFrom(
      (void *)window_icon_pixels, 16, 16, 16, 16 * 2, 0x0f00, 0x00f0, 0x000f, 0xf000));
  SDL_SetWindowIcon(window_.get(), icon_surface.get());

  renderer_ = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(
      SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED));

  // this established the actual hardware OLED pixel accurate dimensions regardless of the window
  // size
  SDL_RenderSetLogicalSize(renderer_.get(), 128, 16);

  if (!renderer_) {
    std::cerr << "Unable to initialize renderer\n";
    exit(-1);
  }
};

void SDLOutputVisualizer::Clear() {
  SetRenderDrawColor(renderer_.get(), gfx::Color::K_WHITE);
  SDL_RenderClear(renderer_.get());
}

void SDLOutputVisualizer::Refresh() { SDL_RenderPresent(renderer_.get()); }

void SDLOutputVisualizer::BindToWindow(SDL_Window *window) { bound_window_ = window; }

void SDLOutputVisualizer::Tick() {
  Clear();
  Refresh();

  // adjust the position of bound_window_ to line up with the main window
  if (bound_window_ != nullptr) {
    int pos_x;
    int pos_y;
    int width;
    int height;
    int top_border_width;
    int left_border_width;
    int bottom_border_width;
    int right_border_width;

    SDL_GetWindowPosition(bound_window_, &pos_x, &pos_y);
    SDL_GL_GetDrawableSize(bound_window_, &width, &height);
    SDL_GetWindowBordersSize(bound_window_, &top_border_width, &left_border_width,
                             &bottom_border_width, &right_border_width);
    SDL_SetWindowPosition(window_.get(), pos_x, pos_y + height + bottom_border_width);
  }
}
SDL_Window *SDLOutputVisualizer::GetWindow() { return window_.get(); }
