add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${PROJECT_SOURCE_DIR}/external/)
if (NOT TARGET stb::stb)
  add_library(stb::stb ALIAS stb)
endif()
