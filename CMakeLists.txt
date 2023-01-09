cmake_minimum_required()

cmake_policy(SET CMP0048 NEW)

project(simple_parser VERSION 1.3.13.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(simple_parser main.cpp)

configure_file(config.h.in config.hpp)

add_subdirectory(io_means)
add_subdirectory(testing)
add_subdirectory(parser)

target_link_libraries(simple_parser PUBLIC io_means testing parser)
target_include_directories(simple_parser PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/io_means"
    "${PROJECT_SOURCE_DIR}/testing"
    "${PROJECT_SOURCE_DIR}/parser"
)