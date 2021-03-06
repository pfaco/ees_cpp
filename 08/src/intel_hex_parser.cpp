#include "intel_hex_parser.h"
#include "hex_string.h"
#include <numeric>
#include <ctre.hpp>
#include <optional>

namespace ees
{

uint8_t intel_hex_checksum(const std::vector<uint8_t> &vec)
{
    auto sum = std::accumulate(vec.begin(), vec.end(), 0);
    return 0xFF - sum + 1;
}

}
