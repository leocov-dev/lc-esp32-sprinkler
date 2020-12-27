#include "display.hpp"

sprinkler::gfx::Display::Display(int height, int width) {
  component_stack_.push(Rect{Point{0, 0}, Size{height, width}});
}
