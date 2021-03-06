#include "sdl-preferences.hpp"

#include <SDL.h>
#include <mini/ini.h>

#include <filesystem>

#include "widgets/string-utils.hpp"

namespace {
  namespace fs = std::filesystem;
  namespace gfx = lc::gfx;
}  // namespace

preferences::SDLPreferences::SDLPreferences()
    : pref_root_(SDL_GetPrefPath("lc-esp32-sprinkler", "app")) {
  fs::path dir(pref_root_);
  fs::path file("preferences.ini");
  pref_file_ = std::make_unique<mINI::INIFile>(dir / file);
  pref_file_->read(pref_ini_);
}

gfx::Point preferences::SDLPreferences::GetWindowPosition() {
  gfx::Point position{SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED};

  if (pref_ini_["window"].has("pos")) {
    auto pos = StringUtils::Split(pref_ini_["window"]["pos"], ' ');
    if (pos.size() == 2) {
      position.x = std::stoi(pos[0]);
      position.y = std::stoi(pos[1]);
    }
  }

  return position;
}

preferences::SDLPreferences::~SDLPreferences() {
  SDL_free(pref_root_);
}

void preferences::SDLPreferences::SaveWindowPosition(SDL_Window* window) {
  int x, y, top_border;

  std::stringstream ss;
  SDL_GetWindowPosition(window, &x, &y);
  SDL_GetWindowBordersSize(window, &top_border, nullptr, nullptr, nullptr);
  ss << x << " " << (y - top_border);
  pref_ini_["window"]["pos"] = ss.str();
  pref_file_->write(pref_ini_);
}
