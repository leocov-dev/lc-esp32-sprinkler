cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(lcSprinkler
    VERSION 0.0.0
    LANGUAGES C CXX)

add_subdirectory(lib/lcSprinkler)
add_subdirectory(sdl2)
add_subdirectory(esp-idf)