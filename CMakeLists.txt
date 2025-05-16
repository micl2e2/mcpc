cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(mcpc)

add_subdirectory(src)

enable_testing()
include(CTest)
add_subdirectory(tst)

