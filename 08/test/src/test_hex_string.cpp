#include "catch.hpp"
#include "hex_string.h"

TEST_CASE("")
{
    REQUIRE(ees::hex_string_to_bytes("") == std::vector<uint8_t>{});
    REQUIRE(ees::hex_string_to_bytes("00") == std::vector<uint8_t>{0});
    REQUIRE(ees::hex_string_to_bytes("00000001FF") == std::vector<uint8_t>{0x00, 0x00, 0x00, 0x01, 0xFF});
    REQUIRE_THROWS(ees::hex_string_to_bytes("0000001FF") == std::vector<uint8_t>{0x00, 0x00, 0x00, 0x01, 0xFF});
    REQUIRE_THROWS(ees::hex_string_to_bytes("0000X001FF") == std::vector<uint8_t>{0x00, 0x00, 0x00, 0x01, 0xFF});
}
