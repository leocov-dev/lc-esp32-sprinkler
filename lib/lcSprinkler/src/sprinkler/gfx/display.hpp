#ifndef LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_
#define LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_

#include "color.hpp"
#include "transform.hpp"
#include <string>
#include <stack>

namespace sprinkler::gfx {

// Display is an interface for LCD/OLED/Software-based displays.
// The coordinate system has its origin begin in the upper left corner:
// (0, 0) .-----> x
//        |
//        |
//        v
//        y
class Display {
 public:
  Display(int height, int width);
  virtual ~Display() = default;

  // Changes the "apparent" drawable area. These are convenience functions for
  // rendering nested views. Pushing a window will make the apparent
  // dimensions of the display take that value temporarily, and when components
  // render themselves, they only know the "current" dimensions and should
  // position themselves accordingly.
  void PushComponent(const Rect &component);
  void PopComponent();

  // Get the display size in pixels. This might be the "apparent" size (based on
  // the sub-windowss that have been pushed via PushWindow).
  const Size &GetSize() const;

  // Returns the Size of a single char. For now we assume monospace fonts.
  virtual Size GetCharSize() const = 0;
  virtual void Clear() = 0;
  virtual void Refresh() = 0;

  void DrawPixel(int y, int x, Color color);
  void DrawRect(Rect rect, Color color);
  void FillRect(Rect rect, Color color);
  void DrawCircle(Point center, int radius, Color color);
  void FillCircle(Point center, int radius, Color color);

  // TODO: pass coordinates via Point.
  void PutText(int y, int x, const std::string &text, int scale, Color fg,
               Color bg);

  void PutText(int y, int x, const std::string &text, int scale, Color fg) {
    return PutText(y, x, text, scale, fg, Color::kWhite);
  };

 private:
  // Derived classes must implement PutTextAbsolute and DrawPixelAbsolute, which
  // handle absolute coordinates. This base class exposes public PutText and
  // DrawPixel, for which the y and x coordinates are taken relative to the
  // current window (top of the windows_stack_).
  virtual void PutTextAbsolute(int y, int x, const std::string &text, int scale,
                               Color fg, Color bg) = 0;

  virtual void DrawPixelAbsolute(int y, int x, Color color) = 0;
  virtual void DrawRectAbsolute(const Rect &rect, Color color) = 0;
  virtual void FillRectAbsolute(const Rect &rect, Color color) = 0;
  virtual void DrawCircleAbsolute(Point center, int radius, Color color) = 0;
  virtual void FillCircleAbsolute(Point center, int radius, Color color) = 0;

  std::stack<Rect> component_stack_;
};

}  // namespace gfx

#endif //LCESP32SPRINKLER_LIB_LCESP32SPRINKLER_SRC_GFX_DISPLAY_HPP_
