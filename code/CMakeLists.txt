cmake_minimum_required(VERSION 2.8.4)
project(rngs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

set(SOURCE_FILES
    main.cpp
    rng.h
    stl_rng.h
    stl_rng.cpp
    mt19937.h
    mt19937.cpp
    randu.h
    randu.cpp
    minstd.h
    minstd.cpp
    r250.h
    r250.cpp
    ranlux.h
    ranlux.cpp
    xorshift.h
    xorshift.cpp
    cmwc.h
    cmwc.cpp
    tinymt.h
    tinymt.cpp)

add_executable(rngs ${SOURCE_FILES})
