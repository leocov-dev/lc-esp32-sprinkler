#ifndef LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
#define LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_

#include <memory>
#include <SDL_ttf.h>
#include <SDL.h>
#include "sprinkler/gfx/color.hpp"
#include "sprinkler/gfx/transform.hpp"
#include "sprinkler/gfx/display.hpp"

using namespace sprinkler::gfx;

constexpr int kCharHeight = 8;
constexpr int kCharWidth = 6;

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

struct SDLFontDeleter {
  void operator()(TTF_Font *font) { TTF_CloseFont(font); }
};

class SDLDisplay : public Display {
 public:
  SDLDisplay(int height, int width, const std::string &font_path);
  ~SDLDisplay() override = default;

  Size GetCharSize() const override;

  void Clear() override;
  void Refresh() override;

 private:
  void PutTextAbsolute(int y, int x, const std::string &text, int scale, Color fg, Color bg) override;
  void DrawPixelAbsolute(int y, int x, Color color) override;
  void DrawRectAbsolute(const Rect &rect,
                        Color color) override;
  void FillRectAbsolute(const Rect &rect,
                        Color color) override;
  void DrawCircleAbsolute(Point center, int radius,
                          Color color) override;
  void FillCircleAbsolute(Point center, int radius,
                          Color color) override;

  std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer_;
  std::unique_ptr<TTF_Font, SDLFontDeleter> font_;
  std::unique_ptr<SDL_Window, SDLWindowDeleter> window_;
};

#endif //LCESP32SPRINKLER_SDL2_LIB_SDL_DISPLAY_HPP_
