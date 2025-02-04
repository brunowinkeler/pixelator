# TODO: Add your libraries here
# You must have the following libraries:

# - stb_image_data_view
add_library(stb_image_data_view STATIC ${PROJECT_SOURCE_DIR}/pixelator/stb_image_data_view.cpp)
target_link_libraries(stb_image_data_view PUBLIC cxx_setup)
target_link_libraries(stb_image_data_view PUBLIC stb::stb)
target_link_libraries(stb_image_data_view PUBLIC ftxui::screen)

# - image
add_library(image STATIC ${PROJECT_SOURCE_DIR}/pixelator/image.cpp)
target_link_libraries(image PUBLIC cxx_setup)
target_link_libraries(image PUBLIC ftxui::screen)

# - pixelate_image

# - drawer

if(BUILD_TESTING)
  include(GoogleTest)
  # TODO: Add your tests executable with all your tests here
  # Name it pixelator_tests.
  # Also use gtest_discover_tests(pixelator_tests)
  # to register them with CTest
endif()
