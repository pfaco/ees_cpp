cmake_minimum_required(VERSION 3.17)

project(
    EletraGRPC

    LANGUAGES CXX
)

find_package(Threads REQUIRED)
find_package(clipp REQUIRED)
find_package(fmt REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

# Proto file
get_filename_component(hw_proto "${CMAKE_CURRENT_SOURCE_DIR}/protos/helloworld.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# Generated sources
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/helloworld.grpc.pb.h")
add_custom_command(
      OUTPUT 
        "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND 
        $<TARGET_FILE:protobuf::protoc>
      ARGS 
        --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
        "${hw_proto}"
      DEPENDS 
        "${hw_proto}")

add_executable(
    ${PROJECT_NAME}

    src/main.cpp
    ${hw_proto_srcs}
    ${hw_grpc_srcs}
)

target_include_directories(
    ${PROJECT_NAME}

    PRIVATE
        ./include
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}

    PUBLIC
        clipp::clipp
        fmt::fmt
        gRPC::grpc++_reflection
        gRPC::grpc++
        protobuf::libprotobuf
)
