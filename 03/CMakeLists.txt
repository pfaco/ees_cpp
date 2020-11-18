cmake_minimum_required(VERSION 3.17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
    HelloEletra

    LANGUAGES CXX
)

find_package(fmt REQUIRED)

add_executable(
    ${PROJECT_NAME}

    src/main.cpp
)

target_include_directories(
    ${PROJECT_NAME}

    PRIVATE
    ./include
)

target_compile_features(
    ${PROJECT_NAME}

    PRIVATE
        cxx_std_17
)

target_link_libraries(
    ${PROJECT_NAME}

    PRIVATE
        fmt::fmt
)
