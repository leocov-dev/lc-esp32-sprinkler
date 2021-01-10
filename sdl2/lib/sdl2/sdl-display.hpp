#ifndef LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
#define LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_

#include <memory>
#include <SDL.h>
#include "sprinkler/gfx/color.hpp"
#include "sprinkler/gfx/transform.hpp"
#include "sprinkler/gfx/display.hpp"
#include "sdl-utils.hpp"
#include "sdl-constants.hpp"

namespace sprinkler::sdl {

namespace gfx = sprinkler::gfx;

class SDLDisplay : public gfx::Display {
 public:
  SDLDisplay(int height, int width, int x, int y);
  ~SDLDisplay() override = default;

  void clear() override;
  void refresh() override;
  SDL_Window *getWindow();

 private:
  void drawPixel_(const gfx::Point &point, const gfx::Color &color) const override;
  void drawRect_(const gfx::Rect &rect, const gfx::Color &color) const override;
  void fillRect_(const gfx::Rect &rect, const gfx::Color &color) const override;
  void drawCircle_(const gfx::Point &center, int radius, const gfx::Color &color) const override;
  void fillCircle_(const gfx::Point &center, int radius, const gfx::Color &color) const override;

  std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer_;
  std::unique_ptr<SDL_Window, SDLWindowDeleter> window_;
};

}  // namespace sprinkler::sdl

#endif //LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
