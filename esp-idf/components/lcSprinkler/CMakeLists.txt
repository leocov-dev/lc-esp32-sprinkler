##idf_component_register(INCLUDE_DIRS ${COMPONENT_DIR}/../../../lib/lcSprinkler/src)
#
#include(FetchContent)
#
#FetchContent_Declare(liblcSprinkler
#    SOURCE_DIR "${COMPONENT_DIR}/../../../lib/lcSprinkler"
#    )
#FetchContent_GetProperties(liblcSprinkler)
#FetchContent_MakeAvailable(liblcSprinkler)
#
#FetchContent_GetProperties(nlohmann_json)
#find_package(nlohmann_json CONFIG REQUIRED PATHS ${nlohmann_json_BINARY_DIR})
#
#
##target_link_libraries(${COMPONENT_LIB}
##    INTERFACE
##    liblcSprinkler)
##
##target_link_libraries(${COMPONENT_LIB}
##    INTERFACE
##    nlohmann_json::nlohmann_json)
##target_include_directories(${COMPONENT_LIB}
##    INTERFACE
##    ${nlohmann_json_SOURCE_DIR}/single_include)
#
#add_library(esp-sprinkler STATIC IMPORTED GLOBAL)
#add_dependencies(esp-sprinkler liblcSprinkler)
#
#set_target_properties(esp-sprinkler PROPERTIES IMPORTED_LOCATION
#    ${liblcSprinkler_BINARY_DIR}/liblcSprinkler.a)
#set_target_properties(esp-sprinkler PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
#    ${COMPONENT_DIR}/../../../lib/lcSprinkler/src)
#
#set_directory_properties( PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES
#    ${liblcSprinkler_BINARY_DIR}/liblcSprinkler.a)


set(CMAKE_CXX_STANDARD 17)
include(${CMAKE_CURRENT_LIST_DIR}/../../../lib/CMakeLists.txt)