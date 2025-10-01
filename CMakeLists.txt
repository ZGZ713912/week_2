cmake_minimum_required(VERSION 3.11)

project(maze)

include_directories(./includes)

add_executable(maze ./src/map.cpp ./src/map_generation.cpp ./src/main.cpp )
