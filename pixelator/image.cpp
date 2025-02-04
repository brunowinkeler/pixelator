#include "image.hpp"

#include <array>
#include <cstdlib>

namespace pixelator {
Image::Image(const int rows, const int cols) : cols_{cols}, rows_{rows} {
  pix_image_data_ = new ftxui::Color[rows * cols];
}

Image::Image(const Image& other_image)
    : cols_{other_image.cols_}, rows_{other_image.rows_} {
  pix_image_data_ = new ftxui::Color[other_image.rows_ * other_image.cols_];
  std::copy(
      &other_image.pix_image_data_[0],
      &other_image.pix_image_data_[(other_image.rows_ * other_image.cols_) - 1],
      pix_image_data_);
}

Image::Image(Image&& other_image)
    : cols_{other_image.cols_},
      rows_{other_image.rows_},
      pix_image_data_{other_image.pix_image_data_} {
  other_image.pix_image_data_ = nullptr;
}

Image::~Image() { free(pix_image_data_); }

pixelator::Size Image::size(void) const {
  return pixelator::Size{rows_, cols_};
}

int Image::rows(void) const { return rows_; }

int Image::cols(void) const { return cols_; }

bool Image::empty(void) const {
  if (cols_ != 0 && rows_ != 0) { return false; }
  return true;
}

ftxui::Color& Image::at(int row, int col) const {
  return pix_image_data_[row * cols_ + col];
}

}  // namespace pixelator
