#include "widgets/transform.hpp"

namespace {
namespace gfx = lc::gfx;
}

gfx::Point gfx::operator+(const gfx::Point &lhs, const gfx::Point &rhs) {
  return gfx::Point{lhs.x + rhs.x, lhs.y + rhs.y};
}

gfx::Point gfx::operator-(const gfx::Point &lhs, const gfx::Point &rhs) {
  return gfx::Point{lhs.x - rhs.x, lhs.y - rhs.y};
}