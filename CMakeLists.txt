cmake_minimum_required(VERSION 3.21)
project(Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Game main.cpp Field.h Track.h Racer.h)
