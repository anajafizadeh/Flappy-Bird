cmake_minimum_required(VERSION 3.12)
project(FlappyBirdClone)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(FlappyBird main.cpp)

target_link_libraries(FlappyBird sfml-graphics sfml-audio)
