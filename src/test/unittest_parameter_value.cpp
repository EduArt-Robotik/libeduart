#include <catch2/catch.hpp>

#include <eduart/parameter_value.hpp>
#include <stdexcept>

using eduart::ParameterValue;
using eduart::ParameterType;

TEST_CASE("Instantiate Value", "[parameter_value]")
{
  // Constructs parameter value object with different types and tries to access it value.

  SECTION("int") {
    ParameterValue value(47);

    CHECK(value.type() == ParameterType::INT);
    CHECK(value.as_int() == 47);
    CHECK_THROWS_AS(value.as_double(), std::invalid_argument);
    CHECK_THROWS_AS(value.as_string(), std::invalid_argument);    
  }

  SECTION("double") {
    ParameterValue value(47.11);

    CHECK(value.type() == ParameterType::DOUBLE);
    CHECK(value.as_double() == 47.11);
    CHECK_THROWS_AS(value.as_int(), std::invalid_argument);
    CHECK_THROWS_AS(value.as_string(), std::invalid_argument);
  }

  SECTION("string") {
    ParameterValue value("47.11");

    CHECK(value.type() == ParameterType::STRING);
    CHECK(value.as_string() == "47.11");
    CHECK_THROWS_AS(value.as_int(), std::invalid_argument);
    CHECK_THROWS_AS(value.as_double(), std::invalid_argument);
  }
}

TEST_CASE("Coping","[parameter_value]")
{
  // Construct an parameter value object and try to copy it.

  SECTION("int") {
    ParameterValue rhs(47);
    ParameterValue lhs(rhs);

    CHECK(lhs.type() == rhs.type());
    CHECK(lhs.as_int() == rhs.as_int());
  }

  SECTION("double") {
    ParameterValue rhs(47.11);
    ParameterValue lhs(rhs);

    CHECK(lhs.type() == rhs.type());
    CHECK(lhs.as_double() == rhs.as_double());
  }

  SECTION("string") {
    ParameterValue rhs("47.11");
    ParameterValue lhs(rhs);

    CHECK(lhs.type() == rhs.type());
    CHECK(lhs.as_string() == rhs.as_string());
  }
}
