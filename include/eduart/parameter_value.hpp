/**
 * Copyright EduArt Robotik GmbH 2022
 *
 * Author: Christian Wendt (christian.wendt@eduart-robotik.com)
 */
#pragma once

#include <cstring>
#include <string>

namespace eduart {

/**
 * \brief Defines data types used by an parameter.
 */
enum class ParameterType {
  INT,
  DOUBLE,
  STRING,
};

/**
 * \brief Holds the parameter's value of given type.
 */
class ParameterValue
{
public:
  ParameterValue(const ParameterValue&);
  ~ParameterValue();
  explicit ParameterValue(const int value);
  explicit ParameterValue(const double value);
  explicit ParameterValue(const std::string& value);

  inline ParameterType type() const { return _type; }
  int as_int() const;
  double as_double() const;
  const std::string& as_string() const;

private:
  union Data {
    int value_int;
    double value_double;
    std::string value_string;

    Data() { std::memset(this, 0, sizeof(Data)); }
    ~Data() { }
  } _data;

  // keep string outside union for easier handling
  std::string _value_string;

  ParameterType _type;
};

} // end namespace eduart