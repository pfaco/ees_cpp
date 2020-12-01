cmake_minimum_required(VERSION 3.17)

project(
    EletraCpp
    
    LANGUAGES 
        CXX
)

find_package(fmt REQUIRED)

add_executable(
    ${PROJECT_NAME}

    src/main.cpp
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC
        ./include
)

target_link_libraries(
    ${PROJECT_NAME}

    fmt::fmt
)

add_subdirectory(test)
