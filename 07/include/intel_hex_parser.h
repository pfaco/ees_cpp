#pragma once

#include <vector>

namespace ees
{

enum class IntelHexRecordType
{
    DATA,
    END_OF_FILE,
    EXTENDED_SEGMENT_ADDRESS,
    START_SEGMENT_ADDRESS,
    EXTENDED_LINEAR_ADDRESS,
    START_LINEAR_ADDRESS
};

struct IntelHexLine
{
    IntelHexRecordType record_type;
    uint16_t address;
    std::vector<uint8_t> data;
};

using IntelHexFile = std::vector<IntelHexLine>;
   
IntelHexLine intel_hex_parse_line(std::string_view line);   
IntelHexFile intel_hex_parse_file(std::istream file);
uint8_t intel_hex_checksum(const std::vector<uint8_t> &vec);

std::string intel_hex_serialize_line(const IntelHexLine &line);
std::string intel_hex_serialize_file(const IntelHexFile &line);

}
