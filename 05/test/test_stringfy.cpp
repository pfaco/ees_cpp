#include "catch.hpp"
#include "stringfy.h"

TEST_CASE("Stringfy of positive numbers should work correctly")
{
    REQUIRE(ees::to_string(10) == std::string("10"));
    REQUIRE(ees::to_string(100) == std::string("100"));
    REQUIRE(ees::to_string(1000) == std::string("1000"));
    REQUIRE(ees::to_string(10000) == std::string("10000"));
    REQUIRE(ees::to_string(100000) == std::string("100000"));
}

TEST_CASE("Leap year detection should work correctly")
{
    REQUIRE(ees::is_leap_year(2000));
    REQUIRE(ees::is_leap_year(2004));
    REQUIRE(ees::is_leap_year(2008));
    REQUIRE(ees::is_leap_year(2012));
    REQUIRE(ees::is_leap_year(2016));
}
