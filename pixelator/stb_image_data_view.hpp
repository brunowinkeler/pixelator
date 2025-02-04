#pragma once

#include "ftxui/screen/color.hpp"
#include "size.hpp"

#include <filesystem>
#include <string>

namespace pixelator {
class StbImageDataView {
 public:
  StbImageDataView() = default;
  StbImageDataView(std::string image_path);

  // Move Operations
  StbImageDataView(StbImageDataView&& other_stb_image);
  StbImageDataView& operator=(StbImageDataView&& other_stb_image);

  ~StbImageDataView();

  // All or nothing
  StbImageDataView(const StbImageDataView&) = delete;
  StbImageDataView& operator=(const StbImageDataView&) = delete;

  pixelator::Size size(void) const;
  int rows(void) const;
  int cols(void) const;
  bool empty(void) const;
  ftxui::Color at(int row, int col) const;

 private:
  int cols_;
  int rows_;
  int channels_;
  std::filesystem::path filepath_;
  unsigned char* image_data_;

  void LoadImage(void);
};
}  // namespace pixelator
