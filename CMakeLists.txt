cmake_minimum_required(VERSION 3.11)

project(maze)

include_directories(./includes)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(maze ./src/character.cpp ./src/map.cpp ./src/map_generation.cpp ./src/main.cpp )
target_link_libraries(maze sfml-graphics sfml-window sfml-system)