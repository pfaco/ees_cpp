#include <fmt/format.h>
#include <fmt/ostream.h>
#include <clipp.h>
#include <memory>
#include <string>
#include <string_view>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "helloworld.grpc.pb.h"
#include "helloworld.pb.h"
#include "server_params.h"
#include "log.h"

using grpc::Server;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

static int visitor_number = 0;

// Logic and data behind the server's behavior.
class GreeterServiceImpl final : public Greeter::Service {
  grpc::Status SayHello(grpc::ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override {
    static const std::string_view msg = "Hello, {}. Welcome to our server! You are visitor number {}.";
    reply->set_message(fmt::format(msg, request->name(), ++visitor_number));
    return grpc::Status::OK;
  }

  grpc::Status ClearVisitor(grpc::ServerContext* context, const helloworld::ClearVisitorRequest* request,
                  helloworld::ClearVisitorReply* reply) override {
    visitor_number = request->value();
    reply->set_value(visitor_number);
    return grpc::Status::OK;
  }
};

void RunServer(const ees::ServerParams &params) {
  auto server_address = fmt::format("{}:{}", params.ipv4, params.port);
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

  if (params.verbose) {
    fmt::print("Server listening on {}\n", server_address);
  }

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv)
{
    ees::ServerParams params{};
    
    const auto cli = (
        clipp::value("server ipv4 address", params.ipv4),
        clipp::value("server port", params.port),
        clipp::option("-v", "--verbose").set(params.verbose).doc("enables verbose mode")
    );

    if (!clipp::parse(argc, argv, cli)) {
      fmt::print("{}\n", clipp::make_man_page(cli, argv[0]));
    } else {
        RunServer(params);
    }

    return 0;
}
