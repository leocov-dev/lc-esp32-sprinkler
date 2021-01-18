/*
Inspired by deskmate by Raphael Baron https://github.com/rbaron/deskmate
*/

#ifndef LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_DISPLAY_HPP_
#define LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_DISPLAY_HPP_

#include "gfxfont.h"
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
  void PushWidgetContext(const Rect &widget_rect);
  void PopWidgetContext();

  void SetFont(const GFXfont &font);

  // Get the display size in pixels. This might be the "apparent" size (based on
  // the sub-windows that have been pushed via PushWindow).
  [[nodiscard]] const Size &GetSize() const;

  virtual void Clear() = 0;
  virtual void Refresh() = 0;

  void DrawPixel(Point point, const Color &color);
  void DrawRect(Rect rect, Color color);
  void FillRect(Rect rect, Color color);
  void DrawCircle(Point center, int radius, Color color);
  void FillCircle(Point center, int radius, Color color);
  void PrintText(Point &cursor, const std::string &text, Color fg);

  // Derived classes must implement PutTextAbsolute and DrawPixelAbsolute, which
  // handle absolute coordinates. This base class exposes public PutText and
  // DrawPixel, for which the y and x coordinates are taken relative to the
  // current window (top of the windows_stack_).
 private:
  void DrawChar(Point &cursor, unsigned char c, Color &color);
  virtual void DrawPixelInternal(const Point &point, const Color &color) const = 0;
  virtual void DrawRectInternal(const Rect &rect, const Color &color) const = 0;
  virtual void FillRectInternal(const Rect &rect, const Color &color) const = 0;
  virtual void DrawCircleInternal(const Point &center, int radius, const Color &color) const = 0;
  virtual void FillCircleInternal(const Point &center, int radius, const Color &color) const = 0;

  std::stack<Rect> widget_context_stack_;
  Size size_;
  const GFXfont *gfxfont_ = nullptr;
  uint8_t text_scale_ = 1;
};

}// namespace sprinkler::gfx

#endif//LC_ESP32_SPRINKLER_LIB_SRC_SPRINKLER_GFX_DISPLAY_HPP_
