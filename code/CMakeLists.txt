cmake_minimum_required(VERSION 2.8.4)
project(rngs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    rng.cpp
    rng.h
    stl_rng.cpp
    stl_rng.h)

add_executable(rngs ${SOURCE_FILES})