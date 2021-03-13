cmake_minimum_required(VERSION 3.16)

project(
    lc-esp32-sprinkler
    VERSION 0.0.0
    DESCRIPTION "esp32 firmware for sprinkler system controller"
)

add_subdirectory(lib-lc-widgets)
add_subdirectory(lib-lc-sprinkler)
add_subdirectory(sdl2)
#add_subdirectory(esp-idf/components/lc-sprinkler-esp)
#add_subdirectory(esp-idf/main)