#pragma once

#include "color.hpp"
#include "size.hpp"

namespace pixelator {
class Image {
 private:
  int m_cols;
  int m_rows;
  pixelator::Color* m_pixImageData;

 public:
  Image(/* args */);
  Image(const int rows, const int cols);
  Image(const Image& other_image);
  Image(Image&& other_image);
  ~Image();

  pixelator::Size size(void) const;
  int rows(void) const;
  int cols(void) const;
  bool empty(void) const;
  pixelator::Color at(int row, int col) const;

  Image& operator=(const Image& other_image) = delete;
  Image& operator=(Image&& other_image) = delete;
};

}  // namespace pixelator
