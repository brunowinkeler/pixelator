#include "stb_image_data_view.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <exception>
#include <iostream>

namespace pixelator {

static constexpr auto kLoadAllChannels{0};

StbImageDataView::StbImageDataView()
    : m_cols{0},
      m_rows{0},
      m_channels{0},
      m_filepath{""},
      m_imageData{nullptr} {}

StbImageDataView::StbImageDataView(std::string image_path)
    : m_cols{0},
      m_rows{0},
      m_channels{0},
      m_filepath{image_path},
      m_imageData{nullptr} {
  loadImage();
}

StbImageDataView::~StbImageDataView() { free(m_imageData); }

StbImageDataView& StbImageDataView::operator=(
    StbImageDataView&& other_stb_image) {
  m_cols = other_stb_image.m_cols;
  m_rows = other_stb_image.m_rows;
  m_channels = other_stb_image.m_channels;
  m_filepath = other_stb_image.m_filepath;
  m_imageData = other_stb_image.m_imageData;
  free(other_stb_image.m_imageData);
  return *this;
}

void StbImageDataView::loadImage(void) {
  // Load the data
  // This call also populates rows, cols, channels.
  try {
    m_imageData = stbi_load(
        m_filepath.c_str(), &m_cols, &m_rows, &m_channels, kLoadAllChannels);

    if (!m_imageData) {
      std::cerr << "Failed to load image data from file: " << m_filepath.c_str()
                << std::endl;
    } else {
      std::cout << "Loaded image of size: [width: " << m_cols
                << ", height: " << m_rows << "] with " << m_channels
                << " channels\n";
    }

  } catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

pixelator::Size StbImageDataView::size(void) const {
  return pixelator::Size{m_cols, m_rows};
}

int StbImageDataView::rows(void) const { return m_cols; }

int StbImageDataView::cols(void) const { return m_rows; }

bool StbImageDataView::empty(void) const {
  if (m_cols > 0 && m_rows > 0) { return false; }
  return true;
}

pixelator::Color StbImageDataView::at(int row, int col) const {
  const auto index{m_channels * (row * m_cols + col)};
  const pixelator::Color color{
      m_imageData[index], m_imageData[index + 1], m_imageData[index + 2]};

  std::cout << "Color at pixel: [row: " << row << ", col: " << col
            << "] =  RGB: (" << std::to_string(color.red) << ", "
            << std::to_string(color.red) << ", " << std::to_string(color.red)
            << ")\n";
  return color;
}

}  // namespace pixelator
