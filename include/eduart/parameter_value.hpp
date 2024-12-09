/**
 * Copyright EduArt Robotik GmbH 2022
 *
 * Author: Christian Wendt (christian.wendt@eduart-robotik.com)
 */
#pragma once

#include <cstring>
#include <memory>
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
  explicit ParameterValue(const int value);
  explicit ParameterValue(const double value);
  explicit ParameterValue(const std::string& value);

  ParameterValue(const ParameterValue&);
  ~ParameterValue();

  inline ParameterType type() const { return _type; }
  int as_int() const;
  double as_double() const;
  const std::string& as_string() const;

private:
  union Data {
    int value_int;
    double value_double;
    std::string* value_string;
  } _data;

  ParameterType _type;
};

} // end namespace eduart