set(CMAKE_CXX_STANDARD 20)


set(SRCS
    lib/esp/ssd-1306-display.cpp
    lib/esp/ssd-1306-display.hpp
    )


if (ESP_PLATFORM)
    idf_component_register(
        SRCS ${SRCS}
        INCLUDE_DIRS lib/esp)

#    target_include_directories(${COMPONENT_LIB} PUBLIC ${COMPONENT_DIR}/../../../lib/src)
else ()
    add_library(lc-sprinkler-esp ${SRCS})
    add_dependencies(lc-sprinkler-esp liblcsprinkler)
    target_link_libraries(lc-sprinkler-esp PUBLIC liblcsprinkler)
    target_include_directories(lc-sprinkler-esp PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/lib>
        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>)
endif ()


