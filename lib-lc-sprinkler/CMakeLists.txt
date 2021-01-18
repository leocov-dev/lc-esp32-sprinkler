cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(LIB_TARGET liblcsprinkler)

set(SRCS
    src/sprinkler/app.cpp
    src/sprinkler/display.cpp
    src/sprinkler/transform.cpp
    src/sprinkler/widget.cpp
    src/sprinkler/w-frame.cpp
    src/sprinkler/string-utils.cpp)

add_library(${LIB_TARGET} ${SRCS})

target_include_directories(${LIB_TARGET} PUBLIC ./include)
target_include_directories(${LIB_TARGET} PRIVATE ./src)

target_include_directories(${LIB_TARGET} PUBLIC ../thirdparty/adafruit_gfx)
target_include_directories(${LIB_TARGET} PUBLIC ../thirdparty/nlohmann_json)
