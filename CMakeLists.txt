cmake_minimum_required(VERSION 3.7)

project(CPROG_Projekt)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(CPROG_Projekt main.cpp Sprite.cpp GameEngine.cpp System.cpp Player.cpp Bullet.cpp Bullet.h TargetSprite.cpp TargetSprite.h Game.cpp Game.h SpriteEngine.cpp SpriteEngine.h GameParams.cpp GameParams.h)
target_link_libraries(CPROG_Projekt ${SDL2_LIBRARIES})