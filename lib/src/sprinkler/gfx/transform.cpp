#include "transform.hpp"

namespace {
namespace gfx = sprinkler::gfx;
}

gfx::Point sprinkler::gfx::operator+(const gfx::Point &lhs, const gfx::Point &rhs) {
  return gfx::Point{lhs.x + rhs.x, lhs.y + rhs.y};
}

gfx::Point sprinkler::gfx::operator-(const gfx::Point &lhs, const gfx::Point &rhs) {
  return gfx::Point{lhs.x - rhs.x, lhs.y - rhs.y};
}