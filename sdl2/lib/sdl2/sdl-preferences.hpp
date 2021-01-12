#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_

#include <SDL.h>
#include "mini/ini.h"
#include "sprinkler/gfx/transform.hpp"

namespace preferences {
namespace gfx = sprinkler::gfx;

class SDLPreferences {
 public:
  SDLPreferences();
  ~SDLPreferences();

  gfx::Point GetWindowPosition();

  void SaveWindowPosition(SDL_Window *window);

 private:
  mINI::INIStructure pref_ini_;
  char *pref_root_;
  std::unique_ptr<mINI::INIFile> pref_file_;
};

} // namespace preferences

#endif//LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_
