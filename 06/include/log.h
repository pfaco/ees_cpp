#pragma once

#include <fmt/format.h>

namespace ees
{

template<typename ...Args>
void log(std::string_view fmt_str, Args ...args)
{
    fmt::print(fmt_str, args...);
}

template<typename ...Args>
void info(std::string_view fmt_str, Args ...args)
{
    log(fmt::format("info: {}", fmt::format(fmt_str, args...)));
}

template<typename ...Args>
void warn(std::string_view fmt_str, Args ...args)
{
    log(fmt::format("warn: {}", fmt::format(fmt_str, args...)));
}

template<typename ...Args>
void error(std::string_view fmt_str, Args ...args)
{
    log(fmt::format("error: {}", fmt::format(fmt_str, args...)));
}

}
