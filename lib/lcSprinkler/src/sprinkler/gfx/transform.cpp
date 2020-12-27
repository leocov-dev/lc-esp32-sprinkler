#include "transform.hpp"

sprinkler::gfx::Point operator+(sprinkler::gfx::Point lhs, const sprinkler::gfx::Point &rhs) {
  lhs += rhs;
  return lhs;
}

sprinkler::gfx::Point operator-(sprinkler::gfx::Point lhs, const sprinkler::gfx::Point &rhs) {
  lhs -= rhs;
  return lhs;
}
