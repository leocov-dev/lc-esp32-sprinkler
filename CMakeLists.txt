cmake_minimum_required(VERSION 3.16)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME Format.cmake
    VERSION 1.6
    GITHUB_REPOSITORY TheLartians/Format.cmake
    OPTIONS # enable cmake formatting (optional)
    "FORMAT_CHECK_CMAKE ON"
    # path to exclude (optional, supports regular expressions)
    "CMAKE_FORMAT_EXCLUDE cmake/CPM.cmake"
)

add_subdirectory(lib-lc-sprinkler)
add_subdirectory(sdl2)
add_subdirectory(esp-idf/components/lc-sprinkler-esp)
add_subdirectory(esp-idf/main)