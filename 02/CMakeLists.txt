cmake_minimum_required(VERSION 3.17)

project(
    HelloEletra

    LANGUAGES CXX
)

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
