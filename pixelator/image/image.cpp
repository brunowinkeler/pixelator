#include "image.hpp"

#include <array>

namespace pixelator {
Image::Image(/* args */) : m_cols{0}, m_rows{0}, m_pixImageData{nullptr} {}

Image::Image(const int rows, const int cols) : m_cols{cols}, m_rows{rows} {
  m_pixImageData = new ftxui::Color[rows * cols];
}

Image::Image(const Image& other_image) {
  m_rows = other_image.m_rows;
  m_cols = other_image.m_cols;
  m_pixImageData = new ftxui::Color[other_image.m_rows * other_image.m_cols];
  std::copy(&other_image.m_pixImageData[0],
            &other_image
                 .m_pixImageData[(other_image.m_rows * other_image.m_cols) - 1],
            m_pixImageData);
}

Image::Image(Image&& other_image) {
  m_rows = other_image.m_rows;
  m_cols = other_image.m_cols;
  m_pixImageData = other_image.m_pixImageData;
  other_image.m_pixImageData = nullptr;
}

Image::~Image() { free(m_pixImageData); }

pixelator::Size Image::size(void) const {
  return pixelator::Size{m_rows, m_cols};
}

int Image::rows(void) const { return m_rows; }

int Image::cols(void) const { return m_cols; }

bool Image::empty(void) const {
  if (m_cols != 0 && m_rows != 0) { return false; }
  return true;
}

ftxui::Color Image::at(int row, int col) const {
  return m_pixImageData[row * m_cols + col];
}

}  // namespace pixelator
