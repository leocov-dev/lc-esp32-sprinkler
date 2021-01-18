cmake_minimum_required(VERSION 3.5)

message("\n##################  ESP32 BUILD  ##################\n")
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

project(sprinkler-esp-idf
    VERSION 0.0.0
    LANGUAGES C CXX)
