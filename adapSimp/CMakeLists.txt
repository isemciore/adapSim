cmake_minimum_required(VERSION 3.3)
project(adapSimp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES adaptiveSimpson.h main.cpp)
add_executable(adapSimp ${SOURCE_FILES})