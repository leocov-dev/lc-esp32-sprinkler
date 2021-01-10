#include "display.hpp"
#include <cstdint>
#include <iostream>
#include <bitset>

sprinkler::gfx::Display::Display(int width, int height) : size_(Size{width, height}) {
  widget_context_stack_.push(Rect{Point{0, 0}, size_});
}

void sprinkler::gfx::Display::drawPixel(sprinkler::gfx::Point point, const sprinkler::gfx::Color &color) {
  const auto context = widget_context_stack_.top();
  point += context.origin;
  drawPixel_(point, color);
}

void sprinkler::gfx::Display::drawRect(sprinkler::gfx::Rect rect, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  drawRect_(rect, color);
}

void sprinkler::gfx::Display::fillRect(sprinkler::gfx::Rect rect, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  rect.origin += context.origin;
  fillRect_(rect, color);
}

void sprinkler::gfx::Display::drawCircle(sprinkler::gfx::Point center, int radius, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  drawCircle_(center, radius, color);
}

void sprinkler::gfx::Display::fillCircle(sprinkler::gfx::Point center, int radius, sprinkler::gfx::Color color) {
  const auto context = widget_context_stack_.top();
  center += context.origin;
  fillCircle_(center, radius, color);
}

void sprinkler::gfx::Display::printText(sprinkler::gfx::Point &cursor,
                                        const std::string &text,
                                        sprinkler::gfx::Color fg) {
  if (gfxfont_ == nullptr) return;

  const auto context = widget_context_stack_.top();
  Point display_space_cursor = cursor;
  display_space_cursor += context.origin;

  for (auto &c : text) {
    drawChar_(display_space_cursor, c, fg);
  }
}

const sprinkler::gfx::Size &sprinkler::gfx::Display::getSize() const {
  return size_;
}

void sprinkler::gfx::Display::pushWidgetContext(const sprinkler::gfx::Rect &widget_rect) {
  const Rect current = widget_context_stack_.top();
  const Rect new_context = Rect{current.origin + widget_rect.origin, widget_rect.size};
  widget_context_stack_.push(new_context);
}

void sprinkler::gfx::Display::popWidgetContext() {
  widget_context_stack_.pop();
}
void sprinkler::gfx::Display::setFont(const GFXfont &font) {
  gfxfont_ = &font;
}
void sprinkler::gfx::Display::drawChar_(sprinkler::gfx::Point &cursor, unsigned char c, sprinkler::gfx::Color &color) {
  if (gfxfont_ == nullptr) return;

  // NOTE: Adafruit GFX Font compatible character drawing
  //  https://github.com/adafruit/Adafruit-GFX-Library

  std::cout << "@ drawChar_ " << c;

  c -= gfxfont_->first;

  GFXglyph *glyph = gfxfont_->glyph + c;
  std::cout << " " << (uint16_t)c << std::endl;

  uint16_t x, y, bo = glyph->bitmapOffset;
  uint8_t bits = 0, bit = 0;

  for (y = 0; y < glyph->height; y++) {
//    bits = *(const unsigned char *)(&gfxfont_->bitmap[bo++]);
    for (x = 0; x < glyph->width; x++) {
//      color = x == 0 ? gfx::Color::kDebugRed : gfx::Color::kDebugGreen;
      std::cout << "coord: " << x << ", " << y << std::endl;

      std::bitset<8> str_bit(bit);
      std::cout << " counter: " << +(bit & 0x7)  << " " << str_bit << std::endl;

      if (!(bit++ & 0x7)) {
        bits = gfxfont_->bitmap[bo++];
        std::bitset<8> str_bits(bits);
        std::cout << " chunk: " << str_bits << std::endl;
      }
      if (bits & 0x80) {
        std::cout << " draw: " << Point{glyph->xOffset + x, glyph->yOffset + y} << std::endl;
//        auto location = cursor + Point{glyph->xOffset + x, glyph->yOffset + y};
//        drawPixel(location, color);
//      }
//      if (color != gfx::Color::kDebugGreen || color != gfx::Color::kDebugRed) {
        color = gfx::Color::kBlack;
        auto location = cursor + Point{glyph->xOffset + x, glyph->yOffset + y};
        drawPixel(location, color);
      }

      bits <<= 1;
      std::bitset<8> str_bits(bits);
      std::cout << " shift: " << str_bits << std::endl;
    }
  }

  cursor.x += glyph->xAdvance;
}
