#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_

#include <SDL.h>

constexpr int kDisplayScaleFactor = 2;

constexpr SDL_Color kSdlBlack{0x00, 0x00, 0x00, 0xff};

constexpr SDL_Color kSdlWhite{0xff, 0xff, 0xff, 0xff};

constexpr SDL_Color kSdlDebugRed{0xff, 0x00, 0x00, 0xff};

constexpr SDL_Color kSdlDebugGreen{0x00, 0xff, 0x00, 0xff};

constexpr SDL_Color kSdlDebugBlue{0x00, 0x00, 0xff, 0xff};

#endif  // LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_CONSTANTS_HPP_
