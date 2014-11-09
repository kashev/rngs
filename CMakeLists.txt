cmake_minimum_required(VERSION 2.8.4)
project(rngs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INCLUDE_PATH, include, source)

include_directories(include, source)

set(SOURCE_FILES main.cpp stl_rng.cpp rng.cpp stl_rng.h rng.h)
add_executable(rngs ${SOURCE_FILES})