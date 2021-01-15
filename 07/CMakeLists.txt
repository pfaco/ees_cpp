cmake_minimum_required(VERSION 3.17)

project(
    IntelHexFiller

    LANGUAGES
        CXX
)

find_package(fmt REQUIRED)
find_package(ctre REQUIRED)

add_library(
    ${PROJECT_NAME}Lib

    src/hex_string.cpp
    src/intel_hex_parser.cpp
)

target_include_directories(
    ${PROJECT_NAME}Lib

    PUBLIC
        ./include
)

target_link_libraries(
    ${PROJECT_NAME}Lib

    PUBLIC
        fmt::fmt
        ctre::ctre
)

target_compile_features(
    ${PROJECT_NAME}Lib

    PUBLIC
        cxx_std_17
)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}

    PRIVATE
        ${PROJECT_NAME}Lib   
)

add_subdirectory(test)
