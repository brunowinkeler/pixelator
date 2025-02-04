#pragma once

#include "ftxui/screen/color.hpp"
#include "size.hpp"

namespace pixelator {
class Image {
 public:
  Image() = default;

  Image(const int rows, const int cols);
  Image(const Image& other_image);
  Image(Image&& other_image);
  ~Image();

  // All or nothing
  Image& operator=(const Image& other_image) = delete;
  Image& operator=(Image&& other_image) = delete;

  pixelator::Size size(void) const;
  int rows(void) const;
  int cols(void) const;
  bool empty(void) const;
  ftxui::Color& at(int row, int col) const;

 private:
  int cols_;
  int rows_;
  ftxui::Color* pix_image_data_;
};

}  // namespace pixelator
