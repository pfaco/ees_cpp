#include <fmt/format.h>
#include <clipp.h>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "helloworld.grpc.pb.h"
#include "helloworld.pb.h"

using grpc::Server;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

static int visitor_number = 0;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  grpc::Status SayHello(grpc::ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    ++visitor_number;
    reply->set_message(fmt::format("Hello, {}. Welcome to our server! You are visitor number {}", request->name(), visitor_number));
    return grpc::Status::OK;
  }

  grpc::Status ClearVisitor(grpc::ServerContext* context, const helloworld::ClearVisitorRequest* request,
                  helloworld::ClearVisitorReply* reply) override {
    if (request->value() == 0) {
        visitor_number = 0;
        reply->set_value(0);
    } else {
        reply->set_value(1);
    }
    return grpc::Status::OK;
  }
};

void RunServer(int server_port) {
  auto server_address = fmt::format("0.0.0.0:{}", server_port);
  GreeterServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  fmt::print("Server listening on {}\n", server_address);

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv)
{
    int server_port = 50051;

    const auto cli = clipp::group(
        clipp::value("server port", server_port)
    );

    if (!clipp::parse(argc, argv, cli)) {
        std::cout << clipp::make_man_page(cli, argv[0]) << std::endl;
    } else {
        RunServer(server_port);
    }

    return 0;
}
