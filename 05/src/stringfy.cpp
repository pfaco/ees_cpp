#include "stringfy.h"
#include <fmt/format.h>
#include <vector>

namespace ees
{
    std::string to_string(int value)
    {
        return fmt::format("{}", value);
    }

    bool is_leap_year(int year)
    {
        return true;
    }
}
