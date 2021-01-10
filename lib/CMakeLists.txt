cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

############################ Fetch Deps #############################
include(FetchContent)

# nlohmann_json lib
set(JSON_BUILDTESTS CACHE BOOL OFF)
set(BUILD_TESTING CACHE BOOL OFF)
FetchContent_Declare(nlohmann_json GIT_REPOSITORY git@github.com:nlohmann/json.git)
FetchContent_GetProperties(nlohmann_json)
if (NOT nlohmann_json_POPULATED)
    FetchContent_Populate(nlohmann_json)
    add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif ()
#####################################################################

set(LIB_LC_SPRINKLER_TARGET liblcsprinkler)

set(SOURCE
    src/ada-font/gfxfont.h

    src/sprinkler/app/app.cpp
    src/sprinkler/app/app.hpp
    src/sprinkler/gfx/color.hpp
    src/sprinkler/gfx/display.cpp
    src/sprinkler/gfx/display.hpp
    src/sprinkler/gfx/transform.cpp
    src/sprinkler/gfx/transform.hpp
    src/sprinkler/input/input-event-handler.hpp
    src/sprinkler/widget/widget.cpp
    src/sprinkler/widget/widget.hpp
    src/sprinkler/widget/w-frame.cpp
    src/sprinkler/widget/w-frame.hpp
    src/sprinkler/input/input-event.hpp
    src/sprinkler/util/string-utils.cpp
    src/sprinkler/util/string-utils.hpp
    )

add_library(${LIB_LC_SPRINKLER_TARGET} ${SOURCE})
target_include_directories(${LIB_LC_SPRINKLER_TARGET} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/src>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>)

find_package(nlohmann_json CONFIG REQUIRED PATHS ${nlohmann_json_BINARY_DIR})
target_link_libraries(${LIB_LC_SPRINKLER_TARGET} PUBLIC nlohmann_json::nlohmann_json)
target_include_directories(${LIB_LC_SPRINKLER_TARGET} PUBLIC ${nlohmann_json_SOURCE_DIR}/single_include)
