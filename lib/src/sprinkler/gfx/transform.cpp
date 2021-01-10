#include "transform.hpp"

sprinkler::gfx::Point sprinkler::gfx::operator+(const sprinkler::gfx::Point &lhs, const sprinkler::gfx::Point &rhs) {
  return sprinkler::gfx::Point{lhs.x + rhs.x, lhs.y + rhs.y};
}

sprinkler::gfx::Point sprinkler::gfx::operator-(const sprinkler::gfx::Point &lhs, const sprinkler::gfx::Point &rhs) {
  return sprinkler::gfx::Point{lhs.x - rhs.x, lhs.y - rhs.y};
}