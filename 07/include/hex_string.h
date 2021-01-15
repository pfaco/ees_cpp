#pragma once

#include <vector>
#include <string_view>

namespace ees
{
    std::vector<uint8_t> hex_string_to_bytes(std::string_view sv);
}
