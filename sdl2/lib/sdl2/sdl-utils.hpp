#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_UTILS_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_UTILS_HPP_

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "sdl-constants.hpp"
#include "sprinkler/gfx/color.hpp"
#include "sprinkler/gfx/transform.hpp"

namespace gfx = sprinkler::gfx;

struct SDLRendererDeleter {
  void operator()(SDL_Renderer *renderer) { SDL_DestroyRenderer(renderer); }
};

struct SDLWindowDeleter {
  void operator()(SDL_Window *window) { SDL_DestroyWindow(window); }
};

struct SDLTextureDeleter {
  void operator()(SDL_Texture *texture) { SDL_DestroyTexture(texture); }
};

struct SDLSurfaceDeleter {
  void operator()(SDL_Surface *surface) { SDL_FreeSurface(surface); }
};

inline
const SDL_Color &FromColor(gfx::Color color) {
  switch (color) {
    case gfx::Color::K_BLACK:
      return kSdlBlack;
    case gfx::Color::K_WHITE:
      return kSdlWhite;
    case gfx::Color::K_DEBUG_RED:
      return kSdlDebugRed;
    case gfx::Color::K_DEBUG_GREEN:
      return kSdlDebugGreen;
    case gfx::Color::K_DEBUG_BLUE:
      return kSdlDebugBlue;
    default:
      return kSdlBlack;
  }
}

inline
Uint32 HexFromColor(gfx::Color color) {
  switch (color) {
    case gfx::Color::K_BLACK:
      return 0xFF000000;
    case gfx::Color::K_WHITE:
      return 0xFFFFFFFF;
    case gfx::Color::K_DEBUG_RED:
      return 0xFFFF0000;
    case gfx::Color::K_DEBUG_GREEN:
      return 0xFF00FF00;
    case gfx::Color::K_DEBUG_BLUE:
      return 0xFF0000FF;
    default:
      return 0xFF000000;
  }
}

inline
void SetRenderDrawColor(SDL_Renderer *renderer, gfx::Color color) {
  const SDL_Color &sdl_color = FromColor(color);
  SDL_SetRenderDrawColor(renderer, sdl_color.r, sdl_color.g, sdl_color.b,
                         sdl_color.a);
}

inline
SDL_Rect FromRect(const gfx::Rect &rect) {
  SDL_Rect sdl_rect;
  sdl_rect.x = rect.origin.x;
  sdl_rect.y = rect.origin.y;
  sdl_rect.w = rect.size.width;
  sdl_rect.h = rect.size.height;
  return sdl_rect;
}

#endif //LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_UTILS_HPP_
