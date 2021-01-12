set(CMAKE_CXX_STANDARD 20)

set(SRCS
    esp/ssd-1306-display.cpp
    esp/ssd-1306-display.hpp
    )

if (ESP_PLATFORM)
    idf_component_register(
        SRCS ${SRCS}
        INCLUDE_DIRS esp)
else ()
    add_library(sprinkler-esp ${SRCS})
endif ()