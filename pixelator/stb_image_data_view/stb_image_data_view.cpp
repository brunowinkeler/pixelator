#include "stb_image_data_view.hpp"

namespace pixelator {
StbImageDataView::StbImageDataView() : m_rows{0}, m_cols{0}, m_filepath{""} {}

StbImageDataView::StbImageDataView(std::string image_path)
    : m_rows{0}, m_cols{0}, m_filepath{image_path} {}

StbImageDataView& StbImageDataView::operator=(
    StbImageDataView&& other_stb_image) {
  this->m_rows = other_stb_image.m_rows;
  this->m_cols = other_stb_image.m_cols;
  this->m_filepath = other_stb_image.m_filepath;
  return *this;
}

void StbImageDataView::loadImage(void) {}

pixelator::Size StbImageDataView::size(void) const {
  return pixelator::Size{0, 0};
}

int StbImageDataView::rows(void) const { return this->m_rows; }

int StbImageDataView::cols(void) const { return this->m_cols; }

bool StbImageDataView::empty(void) const {
  if (this->m_rows != 0 && this->m_cols != 0) { return false; }
  return true;
}

ftxui::Color StbImageDataView::at(int row, int col) const {
  if (this->m_rows != row && this->m_cols != col)
    return ftxui::Color(255, 255, 255);
  return ftxui::Color(0, 0, 0);
}

}  // namespace pixelator
