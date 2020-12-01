#pragma once

#include <string>

namespace ees
{
    struct ServerParams
    {
        std::string ipv4;
        uint32_t port;
        bool verbose;
    };
}
