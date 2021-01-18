set(CMAKE_CXX_STANDARD 20)

if (ESP_PLATFORM)
    idf_component_register(
        SRCS "main.cpp"
        REQUIRES lc-sprinkler-esp
    )

    add_dependencies(${COMPONENT_LIB} liblcsprinkler)
    target_link_libraries(${COMPONENT_LIB} PRIVATE liblcsprinkler)
else()
    add_library(lib-esp-main main.cpp)
    add_dependencies(lib-esp-main liblcsprinkler lc-sprinkler-esp)
    target_link_libraries(lib-esp-main PRIVATE liblcsprinkler lc-sprinkler-esp)
endif ()