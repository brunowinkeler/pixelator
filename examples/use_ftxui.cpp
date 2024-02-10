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
  auto &pixel_left = screen.PixelAt(0, 0);
  pixel_left.background_color = kYellowishColor;
  pixel_left.character = 'X';
  auto &pixel_right = screen.PixelAt(ftxui::Terminal::Size().dimx - 1,
                                     ftxui::Terminal::Size().dimy - 1);
  pixel_right.background_color = kBlueishColor;
  pixel_right.character = 'O';
  screen.Print();

  std::cout << "Dimensions:" << std::endl;
  std::cout << "X: " << ftxui::Terminal::Size().dimx << std::endl;
  std::cout << "Y: " << ftxui::Terminal::Size().dimy << std::endl;

  return 0;
}
