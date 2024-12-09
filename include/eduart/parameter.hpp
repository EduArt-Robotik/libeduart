/**
 * Copyright EduArt Robotik GmbH 2022
 *
 * Author: Christian Wendt (christian.wendt@eduart-robotik.com)
 */
#pragma once

#include "eduart/parameter_value.hpp"
#include <eduart/parameter_constrain.hpp>

namespace eduart {

/**
 * \brief Represents an parameter. This class not only holds the parameter, but also checks its validity. The parameter can be connected to various 
 *        frameworks/serializations via adapter classes.
 */
class Parameter
{
public:
  Parameter(const std::string& name, const ParameterValue& default_value);

  inline const ParameterValue& value() const { return _value; }
  inline ParameterType type() const { return _value.type(); }

private:
  ParameterValue _value;
};

} // end namespace eduart
