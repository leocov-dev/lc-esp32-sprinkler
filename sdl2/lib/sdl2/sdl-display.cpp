#include "sdl-display.hpp"

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include <iostream>

#include "gfx/primitives/point.hpp"
#include "gfx/primitives/rect.hpp"
#include "sdl-constants.hpp"
#include "sdl-utils.hpp"
#include "sdl-window-icon.hpp"

sprinkler::sdl::SdlDisplay::SdlDisplay(int height, int width, gfx::Point position, int scale_factor)
    : Display(width, height) {
  window_ = std::unique_ptr<SDL_Window, SDLWindowDeleter>(SDL_CreateWindow(
      "lcSprinkler",
      position.x,
      position.y,
      width * scale_factor,
      height * scale_factor,
      SDL_WINDOW_SHOWN));

  if (window_ == nullptr) {
    std::cerr << "Unable to initialize window\n";
    exit(-1);
  }

  auto icon_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(SDL_CreateRGBSurfaceFrom(
      (void*)window_icon_pixels, 16, 16, 16, 16 * 2, 0x0f00, 0x00f0, 0x000f, 0xf000));
  SDL_SetWindowIcon(window_.get(), icon_surface.get());

  renderer_ = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(
      SDL_CreateRenderer(window_.get(), -1, SDL_RENDERER_ACCELERATED));

  // this established the actual hardware OLED pixel accurate dimensions regardless of the window
  // size
  SDL_RenderSetLogicalSize(renderer_.get(), width, height);

  SDL_SetRenderDrawBlendMode(renderer_.get(), SDL_BLENDMODE_BLEND);

  if (!renderer_) {
    std::cerr << "Unable to initialize renderer\n";
    exit(-1);
  }
}

void sprinkler::sdl::SdlDisplay::Clear() {
  SetRenderDrawColor(renderer_.get(), gfx::Color::K_WHITE);
  SDL_RenderClear(renderer_.get());
}

void sprinkler::sdl::SdlDisplay::Refresh() {
  SDL_SetRenderDrawColor(renderer_.get(), 200, 200, 200, 128);
  if (kDebug) {
    SDL_RenderDrawLine(
        renderer_.get(),
        0,
        this->GetSize().height / 4,
        this->GetSize().width,
        this->GetSize().height / 4);
  }
  SDL_RenderPresent(renderer_.get());
}

void sprinkler::sdl::SdlDisplay::DrawPixelInternal(const gfx::Point& point, const gfx::Color& color)
    const {
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderDrawPoint(renderer_.get(), point.x, point.y);
}

void sprinkler::sdl::SdlDisplay::DrawRectInternal(const gfx::Rect& rect, const gfx::Color& color)
    const {
  SDL_Rect sdl_rect = FromRect(rect);
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderDrawRect(renderer_.get(), &sdl_rect);
}

void sprinkler::sdl::SdlDisplay::FillRectInternal(const gfx::Rect& rect, const gfx::Color& color)
    const {
  SDL_Rect sdl_rect = FromRect(rect);
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderFillRect(renderer_.get(), &sdl_rect);
}

void sprinkler::sdl::SdlDisplay::DrawCircleInternal(
    const gfx::Point& center,
    int radius,
    const gfx::Color& color) const {
  circleColor(renderer_.get(), center.x, center.y, radius, HexFromColor(color));
}

void sprinkler::sdl::SdlDisplay::FillCircleInternal(
    const gfx::Point& center,
    int radius,
    const gfx::Color& color) const {
  filledCircleColor(renderer_.get(), center.x, center.y, radius, HexFromColor(color));
}

SDL_Window* sprinkler::sdl::SdlDisplay::GetWindow() {
  return window_.get();
}
