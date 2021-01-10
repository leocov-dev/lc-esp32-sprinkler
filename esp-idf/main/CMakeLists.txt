if (ESP_PLATFORM)
    idf_component_register(
        SRCS "main.cpp"
        INCLUDE_DIRS "."
        REQUIRES esp-sprinkler
    )

    target_link_libraries(${COMPONENT_LIB} PUBLIC lclibsprinkler)
endif ()