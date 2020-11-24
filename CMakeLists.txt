cmake_minimum_required(VERSION 3.7)

project(CPROG_Projekt)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(CPROG_Projekt main.cpp Sprite.cpp)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)


target_link_libraries(${CPROG_Projekt} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

