#include "ftxui/screen/color.hpp"
#include "ftxui/screen/screen.hpp"

#include <iostream>

namespace {
const ftxui::Color kYellowishColor = ftxui::Color::RGB(255, 200, 100);
const ftxui::Color kBlueishColor = ftxui::Color::RGB(0, 100, 200);
}  // namespace

int main() {
  const ftxui::Dimensions dimensions{ftxui::Dimension::Full()};
  ftxui::Screen screen{ftxui::Screen::Create(dimensions)};
  
  // One pixel is a group of 2 in terminal

  auto &pixel_left = screen.PixelAt(0, 0);
  pixel_left.background_color = kYellowishColor;
  pixel_left.character = ' ';
  
  auto &pixel_right = screen.PixelAt(1, 0);
  pixel_right.background_color = kBlueishColor;
  pixel_right.character = ' ';

  screen.Print();

  return 0;
}
