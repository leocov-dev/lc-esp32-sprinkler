#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_

#include "sprinkler/gfx/display.hpp"
#include "sprinkler/input/input-event-handler.hpp"
#include "sprinkler/widget/w-frame.hpp"
#include <nlohmann/json.hpp>

namespace sprinkler::app {

namespace gfx = sprinkler::gfx;
namespace widget = sprinkler::widget;
namespace input = sprinkler::input;

class App : public widget::Widget {
 public:
  explicit App(gfx::Display *display)
      : widget::Widget(display->getSize()),
        display_(display){};
  using widget::Widget::handleInputEvent;
  void init();
  void tick();

 protected:
  void draw(gfx::Display *display) const override;

 private:
  gfx::Display *display_;

  std::unique_ptr<widget::WFrame> box1_ =
      std::make_unique<widget::WFrame>(gfx::Size{10, 10});
  std::unique_ptr<widget::WFrame> box2_ =
      std::make_unique<widget::WFrame>(gfx::Size{10, 10});
  std::unique_ptr<widget::WFrame> box3_ =
      std::make_unique<widget::WFrame>(gfx::Size{50, 50});
  std::unique_ptr<widget::WFrame> box4_ =
      std::make_unique<widget::WFrame>(gfx::Size{10, 10});
};

}// namespace sprinkler::app

#endif//LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_APP_APP_HPP_
