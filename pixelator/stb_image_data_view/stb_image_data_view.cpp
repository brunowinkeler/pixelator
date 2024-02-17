#include "stb_image_data_view.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <exception>
#include <iostream>

namespace pixelator {

static constexpr auto kLoadAllChannels{0};

StbImageDataView::StbImageDataView()
    : m_width{0},
      m_height{0},
      m_channels{0},
      m_filepath{""},
      m_imageData{nullptr} {}

StbImageDataView::StbImageDataView(std::string image_path)
    : m_width{0},
      m_height{0},
      m_channels{0},
      m_filepath{image_path},
      m_imageData{nullptr} {
  loadImage();
}

StbImageDataView::~StbImageDataView() { free(m_imageData); }

StbImageDataView& StbImageDataView::operator=(
    StbImageDataView&& other_stb_image) {
  m_width = other_stb_image.m_width;
  m_height = other_stb_image.m_height;
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
        m_filepath.c_str(), &m_width, &m_height, &m_channels, kLoadAllChannels);

    if (!m_imageData) {
      std::cerr << "Failed to load image data from file: " << m_filepath.c_str()
                << std::endl;
    } else {
      std::cout << "Loaded image of size: [width: " << m_width
                << ", height: " << m_height << "] with " << m_channels
                << " channels\n";
    }

  } catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

pixelator::Size StbImageDataView::size(void) const {
  return pixelator::Size{m_width, m_height};
}

int StbImageDataView::rows(void) const { return m_width; }

int StbImageDataView::cols(void) const { return m_height; }

bool StbImageDataView::empty(void) const {
  if (m_width != 0 && m_height != 0) { return false; }
  return true;
}

ftxui::Color StbImageDataView::at(int row, int col) const {
  if (m_width != row && m_height != col) return ftxui::Color(255, 255, 255);
  return ftxui::Color(0, 0, 0);
}

}  // namespace pixelator
