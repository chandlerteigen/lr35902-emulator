cmake_minimum_required(VERSION 3.22.1)
project(lr35902_emulator C CXX)
include(CTest)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(test)
add_subdirectory(src)
