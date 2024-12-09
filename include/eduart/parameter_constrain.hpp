/**
 * Copyright EduArt Robotik GmbH 2022
 *
 * Author: Christian Wendt (christian.wendt@eduart-robotik.com)
 */
#pragma once

#include "eduart/parameter_value.hpp"
#include <stdexcept>

namespace eduart {

/**
 * \brief Constrains used by the parameter class. For example to keep the parameter value in range, etc...
 */
class ParameterConstrain
{
public:
  ParameterConstrain(const ParameterType type) : _type(type) { }
  virtual ~ParameterConstrain() = default;

  bool isValid(const ParameterValue& value) {
    if (value.type() != _type) {
      throw std::invalid_argument("ParameterConstrain: given type for validating is wrong.");
    }

    return check(value);
  }

private:
  virtual bool check(const ParameterValue& value) = 0;

  ParameterType _type;
};

/**
 * \brief In range constrains. Checks if the given value is in given min and max range.
 */
class ParameterInRangeConstrain : public ParameterConstrain
{
public:
  explicit ParameterInRangeConstrain(const int min, const int max);
  explicit ParameterInRangeConstrain(const double min, const double max);
  
private:
  bool check(const ParameterValue& value) override;
};

} // end namespace eduart
