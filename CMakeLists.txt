cmake_minimum_required(VERSION 3.13)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

add_executable(gofish go_fish.cpp player.cpp card.cpp deck.cpp)