set(CMAKE_CXX_STANDARD 20)

if (ESP_PLATFORM)
    idf_component_register(
        SRCS "main.cpp"
        INCLUDE_DIRS "."
        REQUIRES esp-sprinkler
    )
endif ()