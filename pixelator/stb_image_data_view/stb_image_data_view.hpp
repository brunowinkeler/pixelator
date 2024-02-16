#pragma once

#include "ftxui/screen/color.hpp"
#include "size.hpp"

#include <filesystem>
#include <string>

namespace pixelator {
class StbImageDataView {
 private:
  int m_width;
  int m_height;
  int m_channels;
  std::filesystem::path m_filepath;
  unsigned char* m_imageData;

  void loadImage(void);

 public:
  StbImageDataView();
  StbImageDataView(std::string image_path);

  StbImageDataView& operator=(StbImageDataView&& other_stb_image);

  StbImageDataView(const StbImageDataView&) = delete;
  StbImageDataView(StbImageDataView&&) = delete;
  StbImageDataView& operator=(const StbImageDataView&) = delete;

  pixelator::Size size(void) const;
  int rows(void) const;
  int cols(void) const;
  bool empty(void) const;
  ftxui::Color at(int row, int col) const;
};
}  // namespace pixelator