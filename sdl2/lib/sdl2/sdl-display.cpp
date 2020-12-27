#include <iostream>
#include <SDL2_gfxPrimitives.h>
#include "sdl-display.hpp"
#include "sdl-window-icon.hpp"

using namespace sprinkler::gfx;

constexpr SDL_Color kSDLBlack{0x00, 0x00, 0x00, 0xff};
constexpr SDL_Color kSDLWhite{0xff, 0xff, 0xff, 0xff};

constexpr int kTTFFontInitSizePt = 36;

constexpr int kDisplayScaleFactor = 3;

const SDL_Color &FromColor(Color color) {
  return color == Color::kBlack ? kSDLBlack : kSDLWhite;
}

Uint32 HexFromColor(Color color) {
  return color == Color::kBlack ? 0xFF000000 : 0xFFFFFFFF;
}

void SetRenderDrawColor(SDL_Renderer *renderer, Color color) {
  const SDL_Color &sdl_color = FromColor(color);
  SDL_SetRenderDrawColor(renderer, sdl_color.r, sdl_color.g, sdl_color.b,
                         sdl_color.a);
}

SDL_Rect FromRect(const Rect &rect) {
  SDL_Rect sdl_rect;
  sdl_rect.x = rect.point.x;
  sdl_rect.y = rect.point.y;
  sdl_rect.w = rect.size.width;
  sdl_rect.h = rect.size.height;
  return sdl_rect;
}

SDLDisplay::SDLDisplay(int height, int width, const std::string &font_path)
    : Display(height, width) {
  window_ = std::unique_ptr<SDL_Window, SDLWindowDeleter>(
      SDL_CreateWindow(
          "lcSprinkler",
          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
          width * kDisplayScaleFactor, height * kDisplayScaleFactor,
          SDL_WINDOW_SHOWN)
  );

  if (window_ == nullptr) {
    std::cerr << "Unable to initialize window\n";
    exit(-1);
  }

  SDL_Surface *surface;     // Declare an SDL_Surface to be filled in with pixel data from an image file
  surface = SDL_CreateRGBSurfaceFrom(window_icon_pixels,16,16,16,16*2,0x0f00,0x00f0,0x000f,0xf000);

  // The icon is attached to the window pointer
  SDL_SetWindowIcon(window_.get(), surface);

  // ...and the surface containing the icon pixel data is no longer required.
  SDL_FreeSurface(surface);

  renderer_ = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(
      SDL_CreateRenderer(window_.get(), /*index=*/-1, /*flags=*/0));
  SDL_RenderSetLogicalSize(renderer_.get(), width, height);
  if (!renderer_) {
    std::cerr << "Unable to initialize renderer\n";
    exit(-1);
  }
}

void SDLDisplay::Clear() {
  SetRenderDrawColor(renderer_.get(), Color::kWhite);
  SDL_RenderClear(renderer_.get());
}

void SDLDisplay::Refresh() {
  SDL_SetRenderDrawColor(renderer_.get(), 200, 200, 200, 255);
  SDL_RenderDrawLine(renderer_.get(), 0, 16, 128, 16);
  SDL_RenderPresent(renderer_.get());
}

Size SDLDisplay::GetCharSize() const {
  return {kCharHeight, kCharWidth};
}

void SDLDisplay::PutTextAbsolute(int y, int x, const std::string &text, int scale, Color fg, Color bg) {

  const SDL_Color &text_color = FromColor(fg);

  // Draw text.
  // Low quality, fast.
  // auto text_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(
  //     TTF_RenderText_Solid(font_.get(), text.c_str(), text_color));
  // Mid quality, slow.
  // auto text_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(
  //     TTF_RenderText_Shaded(font_.get(), text.c_str(), text_color,
  //     back_color));
  // High quality, very slow.
  // auto text_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(
  //     TTF_RenderText_Blended(font_.get(), text.c_str(), text_color));
//  auto text_surface = std::unique_ptr<SDL_Surface, SDLSurfaceDeleter>(
//      TTF_RenderUTF8_Blended(font_.get(), text.c_str(), text_color));
//  auto text_texture = std::unique_ptr<SDL_Texture, SDLTextureDeleter>(
//      SDL_CreateTextureFromSurface(renderer_.get(), text_surface.get()));

  // Get texture size.
  SDL_Rect dest{x, y, static_cast<int>(kCharWidth * scale * text.length()),
      static_cast<int>(scale * kCharHeight)};
  // SDL_Rect dest{x, y, static_cast<int>(kCharWidth * scale * text.length())};
  // SDL_QueryTexture(text_texture.get(), nullptr, nullptr, &dest.w, &dest.h);

  // Draw background.
  SetRenderDrawColor(renderer_.get(), bg);
  SDL_RenderFillRect(renderer_.get(), &dest);

  // Render.
//  SDL_RenderCopy(renderer_.get(), text_texture.get(), nullptr, &dest);
}

void SDLDisplay::DrawPixelAbsolute(int y, int x, Color color) {
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderDrawPoint(renderer_.get(), x, y);
}

void SDLDisplay::DrawRectAbsolute(const Rect &rect, Color color) {
  SDL_Rect sdl_rect = FromRect(rect);
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderDrawRect(renderer_.get(), &sdl_rect);
}

void SDLDisplay::FillRectAbsolute(const Rect &rect, Color color) {
  SDL_Rect sdl_rect = FromRect(rect);
  SetRenderDrawColor(renderer_.get(), color);
  SDL_RenderFillRect(renderer_.get(), &sdl_rect);
}

void SDLDisplay::DrawCircleAbsolute(Point center, int radius,
                                    Color color) {
  circleColor(renderer_.get(), center.x, center.y, radius, HexFromColor(color));
}

void SDLDisplay::FillCircleAbsolute(Point center, int radius,
                                    Color color) {
  filledCircleColor(renderer_.get(), center.x, center.y, radius, HexFromColor(color));
}