cmake_minimum_required(VERSION 3.17)

project(
    test

    LANGUAGES
        CXX
)

add_executable(
    ${PROJECT_NAME}

    main.cpp
    test_stringfy.cpp
    ../src/stringfy.cpp
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC
        ../include
)

target_link_libraries(
    ${PROJECT_NAME}

    fmt::fmt
)
