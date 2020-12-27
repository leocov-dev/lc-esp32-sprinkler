idf_component_register(INCLUDE_DIRS ${COMPONENT_DIR}/../../../lib/lcSprinkler/src)

include(FetchContent)

FetchContent_Declare(liblcsprinkler
    SOURCE_DIR "${COMPONENT_DIR}/../../../lib/lcSprinkler"
    )
FetchContent_GetProperties(liblcsprinkler)
FetchContent_MakeAvailable(liblcsprinkler)
FetchContent_GetProperties(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED PATHS ${nlohmann_json_BINARY_DIR})

set(COMPONENT_DUMMY_LIB ${COMPONENT_NAME}_TARGET )

add_library(${COMPONENT_DUMMY_LIB} STATIC IMPORTED GLOBAL)
add_dependencies(${COMPONENT_DUMMY_LIB} liblcsprinkler)

target_link_libraries(${COMPONENT_DUMMY_LIB} INTERFACE liblcsprinkler)
target_link_libraries(${COMPONENT_DUMMY_LIB} INTERFACE nlohmann_json::nlohmann_json)

target_include_directories(${COMPONENT_LIB} INTERFACE ${nlohmann_json_SOURCE_DIR}/single_include)