#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_

#include <SDL.h>

constexpr int kCharHeight = 8;

constexpr int kCharWidth = 6;

constexpr int kDisplayScaleFactor = 2;

constexpr SDL_Color kSDLBlack{0x00, 0x00, 0x00, 0xff};

constexpr SDL_Color kSDLWhite{0xff, 0xff, 0xff, 0xff};

constexpr SDL_Color kSDLDebugRed{0xff, 0x00, 0x00, 0xff};

constexpr SDL_Color kSDLDebugGreen{0x00, 0xff, 0x00, 0xff};

constexpr SDL_Color kSDLDebugBlue{0x00, 0x00, 0xff, 0xff};

#endif //LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_
