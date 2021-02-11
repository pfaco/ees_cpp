#include <fmt/format.h>
#include <string>
#include "intel_hex_parser.h"
#include "hex_string.h"
#include <iostream>
#include <string_view>

int main(int argc, char* argv[])
{
    try
    {
        int number_of_lines_with_FF_checksum = 0;
        std::string str;
        while (std::getline(std::cin, str))
        {
            auto line = std::string_view(str);
            line = line.substr(1, line.size() - 3); //remove ':' and the checksum itself
            auto checksum = ees::intel_hex_checksum(ees::hex_string_to_bytes(line));
            if (checksum == 0xFF) {
                ++number_of_lines_with_FF_checksum;
            }
        }
        fmt::print("number of lines with FF checksum = {}\n", number_of_lines_with_FF_checksum);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
