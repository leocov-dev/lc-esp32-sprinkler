#include "sprinkler/display.hpp"

#include <bitset>
#include <cstdint>
#include <iostream>

sprinkler::gfx::Display::Display(int width, int height) : size_(Size{width, height}) {
  widget_context_stack_.push(Rect{Point{0, 0}, size_});
}

void sprinkler::gfx::Display::DrawPixel(sprinkler::gfx::Point point, const sprinkler::gfx::Color &color) {
  const auto context = widget_context_stack_.top();
  point += context.origin;
  DrawPixelInternal(point, color);
}

void sprinkler::gfx::Display::DrawRect(sprinkler::gfx::Rect rect, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  DrawRectInternal(rect, color);
}

void sprinkler::gfx::Display::FillRect(sprinkler::gfx::Rect rect, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  FillRectInternal(rect, color);
}

void sprinkler::gfx::Display::DrawCircle(sprinkler::gfx::Point center, int radius, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  DrawCircleInternal(center, radius, color);
}

void sprinkler::gfx::Display::FillCircle(sprinkler::gfx::Point center, int radius, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  FillCircleInternal(center, radius, color);
}

void sprinkler::gfx::Display::PrintText(sprinkler::gfx::Point &cursor,
                                        const std::string &text,
                                        sprinkler::gfx::Color fg) {
  if (gfxfont_ == nullptr) return;

  const auto context = widget_context_stack_.top();
  Point display_space_cursor = cursor;
  display_space_cursor += context.origin;

  for (auto &c : text) {
    DrawChar(display_space_cursor, c, fg);
  }
}

const sprinkler::gfx::Size &sprinkler::gfx::Display::GetSize() const {
  return size_;
}

void sprinkler::gfx::Display::PushWidgetContext(const sprinkler::gfx::Rect &widget_rect) {
  const Rect kCurrent = widget_context_stack_.top();
  const Rect kNewContext = Rect{kCurrent.origin + widget_rect.origin, widget_rect.size};
  widget_context_stack_.push(kNewContext);
}

void sprinkler::gfx::Display::PopWidgetContext() {
  widget_context_stack_.pop();
}
void sprinkler::gfx::Display::SetFont(const GFXfont &font) {
  gfxfont_ = &font;
}
void sprinkler::gfx::Display::DrawChar(sprinkler::gfx::Point &cursor, unsigned char c, sprinkler::gfx::Color &color) {
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
