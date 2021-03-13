#include "widgets/display.hpp"

#include <bitset>
#include <cstdint>

namespace {
  namespace gfx = lc::gfx;
}

gfx::Display::Display(int width, int height) : size_(Size{width, height}) {
  widget_context_stack_.push(Rect{Point{0, 0}, size_});
}

void gfx::Display::DrawPixel(gfx::Point point, const gfx::Color &color) {
  const auto context = widget_context_stack_.top();
  point += context.origin;
  DrawPixelInternal(point, color);
}

void gfx::Display::DrawRect(gfx::Rect rect, gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  DrawRectInternal(rect, color);
}

void gfx::Display::FillRect(gfx::Rect rect, gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  FillRectInternal(rect, color);
}

void gfx::Display::DrawCircle(gfx::Point center, int radius, gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  DrawCircleInternal(center, radius, color);
}

void gfx::Display::FillCircle(gfx::Point center, int radius, gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  FillCircleInternal(center, radius, color);
}

void gfx::Display::PrintText(gfx::Point &cursor,
                                        const std::string &text,
                                        gfx::Color fg) {
  if (gfxfont_ == nullptr) return;

  const auto context = widget_context_stack_.top();
  Point display_space_cursor = cursor;
  display_space_cursor += context.origin;

  for (auto &c : text) {
    DrawChar(display_space_cursor, c, fg);
  }
}

const gfx::Size &gfx::Display::GetSize() const {
  return size_;
}

void gfx::Display::PushWidgetContext(const gfx::Rect &widget_rect) {
  const Rect kCurrent = widget_context_stack_.top();
  const Rect kNewContext = Rect{kCurrent.origin + widget_rect.origin, widget_rect.size};
  widget_context_stack_.push(kNewContext);
}

void gfx::Display::PopWidgetContext() {
  widget_context_stack_.pop();
}
void gfx::Display::SetFont(const GFXfont &font) {
  gfxfont_ = &font;
}
void gfx::Display::DrawChar(gfx::Point &cursor, unsigned char c, gfx::Color &color) {
  if (gfxfont_ == nullptr) return;

  // NOTE: Adafruit GFX Font compatible character drawing
  //  https://github.com/adafruit/Adafruit-GFX-Library

  GFXglyph *glyph = gfxfont_->glyph + (c - gfxfont_->first);

  uint16_t x, y, bitmap_offset = glyph->bitmapOffset;
  uint8_t bits_chunk = 0, counter = 0;

  // this iterates along the x axis, loading 8 bit chunks from the bitmap
  // until all pixel positions for the character are exhausted
  for (y = 0; y < glyph->height; y++) {
    for (x = 0; x < glyph->width; x++) {

      // count by 8 and load the next 8 bit chunk from the bitmap
      if (!(counter++ & 0x7)) {
        bits_chunk = gfxfont_->bitmap[bitmap_offset++];
      }

      // if the first bit of the loaded chunk is a 1 we draw a pixel
      if (bits_chunk & 0x80) {
        DrawPixel(cursor + Point{glyph->xOffset + x, glyph->yOffset + y}, color);
      }

      // shift bits and loop
      bits_chunk <<= 1;
    }
  }

  cursor.x += glyph->xAdvance;
}
