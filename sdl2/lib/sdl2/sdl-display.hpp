#ifndef LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
#define LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_

#include <SDL.h>

#include <memory>

#include "sdl-constants.hpp"
#include "sdl-utils.hpp"
#include "sprinkler/color.hpp"
#include "sprinkler/display.hpp"
#include "sprinkler/transform.hpp"

namespace {
  namespace gfx = sprinkler::gfx;
}

namespace sprinkler::sdl {

  class SDLDisplay : public gfx::Display {
  public:
    SDLDisplay(int height, int width, gfx::Point position);
    ~SDLDisplay() override = default;

    void Clear() override;
    void Refresh() override;
    SDL_Window* getWindow();

  private:
    void DrawPixelInternal(const gfx::Point& point, const gfx::Color& color) const override;
    void DrawRectInternal(const gfx::Rect& rect, const gfx::Color& color) const override;
    void FillRectInternal(const gfx::Rect& rect, const gfx::Color& color) const override;
    void DrawCircleInternal(const gfx::Point& center,
                            int radius,
                            const gfx::Color& color) const override;
    void FillCircleInternal(const gfx::Point& center,
                            int radius,
                            const gfx::Color& color) const override;

    std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer_;
    std::unique_ptr<SDL_Window, SDLWindowDeleter> window_;
  };

}  // namespace sprinkler::sdl

#endif  // LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
