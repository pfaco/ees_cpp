add_executable(
    IntelHexTest

    main.cpp
    src/test_hex_string.cpp
    src/test_intel_hex_parser.cpp
)

target_include_directories(
    IntelHexTest

    PRIVATE
        ./
)

target_link_libraries(
    IntelHexTest

    PRIVATE
        ${PROJECT_NAME}Lib
)
