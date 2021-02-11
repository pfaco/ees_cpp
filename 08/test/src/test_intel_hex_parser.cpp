#include "catch.hpp"
#include "hex_string.h"
#include "intel_hex_parser.h"

TEST_CASE("All the checksum calculations are the same as wikipedia example (https://en.wikipedia.org/wiki/Intel_HEX)")
{
    REQUIRE(0x40 == ees::intel_hex_checksum(ees::hex_string_to_bytes("10010000214601360121470136007EFE09D21901")));
    REQUIRE(0x28 == ees::intel_hex_checksum(ees::hex_string_to_bytes("100110002146017E17C20001FF5F160021480119")));
    REQUIRE(0xA7 == ees::intel_hex_checksum(ees::hex_string_to_bytes("10012000194E79234623965778239EDA3F01B2CA")));
    REQUIRE(0xC7 == ees::intel_hex_checksum(ees::hex_string_to_bytes("100130003F0156702B5E712B722B732146013421")));
    REQUIRE(0xFF == ees::intel_hex_checksum(ees::hex_string_to_bytes("00000001")));
}
