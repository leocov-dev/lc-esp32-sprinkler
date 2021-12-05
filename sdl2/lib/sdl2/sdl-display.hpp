#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_DISPLAY_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_DISPLAY_HPP_

#include <SDL.h>

#include <memory>

#include "gfx/primitives/point.hpp"
#include "gfx/primitives/rect.hpp"
#include "gfx/primitives/transform.hpp"
#include "sdl-constants.hpp"
#include "sdl-utils.hpp"
#include "gfx/color.hpp"
#include "display/display.hpp"

namespace {
  namespace gfx = lc::gfx;
}

namespace sprinkler::sdl {

  class SdlDisplay : public gfx::Display {
  public:
    SdlDisplay(int height, int width, gfx::Point position, int scale_factor = 1);
    ~SdlDisplay() override = default;

    void Clear() override;
    void Refresh() override;
    SDL_Window* GetWindow();

  private:
    void DrawPixelInternal(const gfx::Point& point, const gfx::Color& color) const override;
    void DrawRectInternal(const gfx::Rect& rect, const gfx::Color& color) const override;
    void FillRectInternal(const gfx::Rect& rect, const gfx::Color& color) const override;
    void DrawCircleInternal(const gfx::Point& center, int radius, const gfx::Color& color)
        const override;
    void FillCircleInternal(const gfx::Point& center, int radius, const gfx::Color& color)
        const override;

    std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer_;
    std::unique_ptr<SDL_Window, SDLWindowDeleter> window_;
  };

}  // namespace sprinkler::sdl

#endif  // LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_DISPLAY_HPP_
