#include "hex_string.h"
#include <fmt/format.h>
#include <stdexcept>

namespace ees
{

static uint8_t char_to_u8(char c);
static uint8_t str_to_u8(std::string_view sv);

std::vector<uint8_t> hex_string_to_bytes(std::string_view sv)
{
    if (sv.size() % 2 != 0)
    {
        throw std::logic_error("cannot convert odd-length strings to bytes");
    }

    std::vector<uint8_t> vec;

    for (int i = 0; i < sv.size(); i += 2)
    {
        vec.push_back(str_to_u8(sv.substr(i,2)));
    }

    return vec;
}

static uint8_t char_to_u8(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }

    if (c >= 'A' && c <= 'F')
    {
        return c - 'A' + 10;
    }

    if (c >= 'a' && c <= 'f')
    {
        return c - 'a' + 10;
    }

    throw std::logic_error{fmt::format("cannot conver character '{}' to integer", c)};
}

static uint8_t str_to_u8(std::string_view sv)
{
    return (char_to_u8(sv[0]) << 4) + char_to_u8(sv[1]);
}

}
