/*
Inspired by deskmate by Raphael Baron https://github.com/rbaron/deskmate
*/

#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_

#include "ada-font/gfxfont.h"
#include "color.hpp"
#include "transform.hpp"
#include <stack>
#include <string>

namespace sprinkler::gfx {

// The coordinate system:
// (x, y)
// (0, 0) .----- x
//        |
//        |
//        y
class Display {
 public:
  Display(int width, int height);
  virtual ~Display() = default;

  // Changes the "apparent" drawable area. These are convenience functions for
  // rendering nested views. Pushing a window will make the apparent
  // dimensions of the display take that value temporarily, and when components
  // render themselves, they only know the "current" dimensions and should
  // position themselves accordingly.
  void pushWidgetContext(const Rect &widget_rect);
  void popWidgetContext();

  void setFont(const GFXfont &font);

  // Get the display size in pixels. This might be the "apparent" size (based on
  // the sub-windows that have been pushed via PushWindow).
  [[nodiscard]] const Size &getSize() const;

  virtual void clear() = 0;
  virtual void refresh() = 0;

  void drawPixel(Point point, const Color &color);
  void drawRect(Rect rect, Color color);
  void fillRect(Rect rect, Color color);
  void drawCircle(Point center, int radius, Color color);
  void fillCircle(Point center, int radius, Color color);
  void printText(Point &cursor, const std::string &text, Color fg);

  // Derived classes must implement PutTextAbsolute and DrawPixelAbsolute, which
  // handle absolute coordinates. This base class exposes public PutText and
  // DrawPixel, for which the y and x coordinates are taken relative to the
  // current window (top of the windows_stack_).
 private:
  void drawChar_(Point &cursor, unsigned char c, Color &color);
  virtual void drawPixel_(const Point &point, const Color &color) const = 0;
  virtual void drawRect_(const Rect &rect, const Color &color) const = 0;
  virtual void fillRect_(const Rect &rect, const Color &color) const = 0;
  virtual void drawCircle_(const Point &center, int radius, const Color &color) const = 0;
  virtual void fillCircle_(const Point &center, int radius, const Color &color) const = 0;

  std::stack<Rect> widget_context_stack_;
  Size size_;
  const GFXfont *gfxfont_ = nullptr;
  uint8_t text_scale_ = 1;
};

}// namespace sprinkler::gfx

#endif//LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_
