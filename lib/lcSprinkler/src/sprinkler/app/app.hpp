#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_

#include "sprinkler/input/input-event-handler.hpp"
#include "sprinkler/gfx/display.hpp"
#include <nlohmann/json.hpp>

namespace {
using namespace sprinkler::gfx;
using namespace sprinkler::input;
}

namespace sprinkler::app {

class App {
 public:
  explicit App(Display *display)
      : display_(display) {}
  void init();
  void tick();

  InputEventHandler *GetInputEventHandler();

 private:
  Display *display_;
};

}  // namespace lc::app

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_
