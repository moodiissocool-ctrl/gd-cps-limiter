
cmake_minimum_required(VERSION 3.21)
project(CPSLimiter VERSION 1.0.0)

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

setup_geode_mod(${PROJECT_NAME})
