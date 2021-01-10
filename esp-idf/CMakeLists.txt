cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

message("\n##################  ESP32 BUILD  ##################\n")
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(sprinkler-esp-idf
    VERSION 0.0.0
    LANGUAGES C CXX)
