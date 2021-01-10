set(SOURCES
    ssd-1306-display.cpp)


if (ESP_PLATFORM)
    idf_component_register(
        SRCS ${SOURCES}
        INCLUDE_DIRS "."
        PRIV_REQUIRES lcSprinkler)
else ()
    add_library(esp_sprinkler ssd-1306-display.cpp ssd-1306-display.hpp)
endif ()