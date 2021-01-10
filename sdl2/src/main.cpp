#include <iostream>
#include <filesystem>
#include <sstream>
#include <string>
#include "SDL.h"
#include "sdl2/sdl-display.hpp"
#include "sdl2/sdl-input-transcriber.hpp"
#include "sprinkler/app/app.hpp"
#include "sprinkler/util/string-utils.hpp"
#include "sdl2/sdl-output-visualizer.hpp"
#include "mini/ini.h"

namespace {
namespace app = sprinkler::app;
namespace sdl = sprinkler::sdl;
namespace fs = std::filesystem;
}

constexpr int kDisplayWidth = 128;
constexpr int kDisplayHeight = 64;

int main() {
  SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
  SDL_Log("Starting...");

  // preferences file
  char *pref_root = SDL_GetPrefPath("lc-esp32-sprinkler", "app");
  fs::path dir(pref_root);
  fs::path file("preferences.ini");
  mINI::INIFile pref_file(dir/file);
  mINI::INIStructure pref_ini;
  pref_file.read(pref_ini);

  int app_x = SDL_WINDOWPOS_CENTERED;
  int app_y = SDL_WINDOWPOS_CENTERED;
//  int vis_x = SDL_WINDOWPOS_CENTERED;
//  int vis_y = SDL_WINDOWPOS_CENTERED;

  // reposition main window
  if (pref_ini["window"].has("pos")) {
    auto pos = StringUtils::split(pref_ini["window"]["pos"], ' ');
    if (pos.size() == 2) {
      app_x = std::stoi(pos[0]);
      app_y = std::stoi(pos[1]);
    }
  }
//  if (pref_ini["visualizer"].has("pos")) {
//    auto pos = StringUtils::split(pref_ini["visualizer"]["pos"], ' ');
//    if (pos.size() == 2) {
//      vis_x = std::stoi(pos[0]);
//      vis_y = std::stoi(pos[1]);
//    }
//  }

  // SDL
//  SDLOutputVisualizer output_visualizer(vis_x, vis_y);
  sdl::SDLDisplay display(kDisplayHeight, kDisplayWidth, app_x, app_y);
//  output_visualizer.BindToWindow(display.getWindow());

  app::App app(&display);
  app.init();

  sdl::SDLInputTranscriber input_transcriber(&app);

  app.tick();

  while (!input_transcriber.shouldQuit()) {
    input_transcriber.dispatchEvents();

//    app.tick();
//    output_visualizer.Tick();

//    SDL_Delay(10);  // required to prevent stalling draw thread
    SDL_Delay(250);
  }

  std::stringstream ss;
  // save window position
  SDL_GetWindowPosition(display.getWindow(), &app_x, &app_y);
  ss << app_x << " " << app_y;
  pref_ini["window"]["pos"] = ss.str();
//  ss.str(std::string()); // clear stream
//  SDL_GetWindowPosition(output_visualizer.GetWindow(), &vis_x, &vis_y);
//  ss << vis_x << " " << vis_y;
//  pref_ini["visualizer"]["pos"] = ss.str();
  pref_file.write(pref_ini);

  SDL_free(pref_root);

  SDL_Log("Closing...");
  SDL_Delay(1000);
  SDL_Quit();
}