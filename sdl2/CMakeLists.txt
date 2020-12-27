cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(sprinkler-sdl LANGUAGES CXX)

message("\n##################  SDL2 BUILD  ##################\n")

set(SPRINKLER_SDL_TARGET sprinkler-sdl)

###################### Fetch ######################
include(FetchContent)
FetchContent_Declare(sdl2_cmake GIT_REPOSITORY https://gitlab.com/aminosbh/sdl2-cmake-modules.git)
FetchContent_GetProperties(sdl2_cmake)
if (NOT sdl2_cmake_POPULATED)
    FetchContent_Populate(sdl2_cmake)
    list(APPEND CMAKE_MODULE_PATH ${sdl2_cmake_SOURCE_DIR})
endif ()
################################################

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(lib)

set(LIB
    SDL2::Main
    SDL2::TTF
    SDL2::GFX
    lcSprinkler
    )

set(SOURCE
    src/main.cpp
    lib/sdl2/sdl-display.cpp
    lib/sdl2/sdl-input-transcriber.cpp
    )

add_executable(${SPRINKLER_SDL_TARGET} ${SOURCE})
target_link_libraries(sprinkler-sdl LINK_PUBLIC ${LIB})

file(COPY assets
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
    FILES_MATCHING PATTERN *.ttf)

