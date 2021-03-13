cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(sprinkler-sdl
    VERSION 0.0.0
    LANGUAGES CXX)

message("\n##################  SDL2 BUILD  ##################\n")

###################### Fetch ######################
include(FetchContent)

# SDL2
FetchContent_Declare(sdl2_cmake GIT_REPOSITORY https://gitlab.com/aminosbh/sdl2-cmake-modules.git)
FetchContent_GetProperties(sdl2_cmake)
if (NOT sdl2_cmake_POPULATED)
    FetchContent_Populate(sdl2_cmake)
    list(APPEND CMAKE_MODULE_PATH ${sdl2_cmake_SOURCE_DIR})
endif ()

# mINI reader/writer
FetchContent_Declare(m_ini GIT_REPOSITORY https://github.com/pulzed/mINI.git)
FetchContent_GetProperties(m_ini)
if (NOT m_ini_POPULATED)
    FetchContent_Populate(m_ini)
endif ()
################################################

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

set(LIB
    SDL2::Main
    SDL2::TTF
    SDL2::GFX
    lcSprinkler::lcSprinkler
    )

set(SRCS
    src/main.cpp
    lib/sdl2/sdl-display.cpp
    lib/sdl2/sdl-input-transcriber.cpp
    lib/sdl2/sdl-output-visualizer.cpp
    lib/sdl2/sdl-preferences.cpp
    )

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB})

target_include_directories(${PROJECT_NAME} PRIVATE "${m_ini_SOURCE_DIR}/src")
target_include_directories(${PROJECT_NAME} PRIVATE lib)
