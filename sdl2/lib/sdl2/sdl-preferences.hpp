#ifndef LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_
#define LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_

#include <SDL.h>
#include <mini/ini.h>

#include "gfx/primitives/transform.hpp"
#include "gfx/primitives/point.hpp"

namespace {
  namespace gfx = lc::gfx;
}

namespace preferences {
  class SdlPreferences {
  public:
    SdlPreferences();
    ~SdlPreferences();

    gfx::Point GetWindowPosition();

    void SaveWindowPosition(SDL_Window* window);

  private:
    mINI::INIStructure pref_ini_;
    char* pref_root_;
    std::unique_ptr<mINI::INIFile> pref_file_;
  };

}  // namespace preferences

#endif  // LC_ESP32_SPRINKLER_SDL2_LIB_SDL2_SDL_PREFERENCES_HPP_
