#include "stb_image_data_view.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include <exception>
#include <iostream>

namespace pixelator {

static constexpr auto kLoadAllChannels{0};

StbImageDataView::StbImageDataView(std::string image_path)
    : cols_{0},
      rows_{0},
      channels_{0},
      filepath_{image_path},
      image_data_{nullptr} {
  LoadImage();
}

StbImageDataView::StbImageDataView(StbImageDataView&& other_stb_image)
    : cols_{other_stb_image.cols_},
      rows_{other_stb_image.rows_},
      channels_{other_stb_image.channels_},
      filepath_{other_stb_image.filepath_} {
  other_stb_image.image_data_ = nullptr;
}

StbImageDataView& StbImageDataView::operator=(
    StbImageDataView&& other_stb_image) {
  if (this == &other_stb_image) { return *this; }  // Do not self-assign.
  free(image_data_);  // In case we already owned some memory from before.
  cols_ = other_stb_image.cols_;
  rows_ = other_stb_image.rows_;
  channels_ = other_stb_image.channels_;
  filepath_ = other_stb_image.filepath_;
  image_data_ = other_stb_image.image_data_;
  other_stb_image.image_data_ = nullptr;
  return *this;
}

StbImageDataView::~StbImageDataView() { free(image_data_); }

void StbImageDataView::LoadImage(void) {
  // Load the data
  // This call also populates rows, cols, channels.
  try {
    image_data_ = stbi_load(
        filepath_.c_str(), &cols_, &rows_, &channels_, kLoadAllChannels);

    if (!image_data_) {
      std::cerr << "Failed to load image data from file: " << filepath_.c_str()
                << std::endl;
    } else {
      std::cout << "Loaded image of size: [width: " << cols_
                << ", height: " << rows_ << "] with " << channels_
                << " channels\n";
    }

  } catch (const std::exception& e) { std::cerr << e.what() << '\n'; }
}

pixelator::Size StbImageDataView::size(void) const {
  return pixelator::Size{cols_, rows_};
}

int StbImageDataView::rows(void) const { return cols_; }

int StbImageDataView::cols(void) const { return rows_; }

bool StbImageDataView::empty(void) const {
  if (cols_ > 0 && rows_ > 0) { return false; }
  return true;
}

ftxui::Color StbImageDataView::at(int row, int col) const {
  const auto index{channels_ * (row * cols_ + col)};
  const ftxui::Color color{
      image_data_[index], image_data_[index + 1], image_data_[index + 2]};
  return color;
}

}  // namespace pixelator
