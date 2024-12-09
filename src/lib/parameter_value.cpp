#include "eduart/parameter_value.hpp"

#include <stdexcept>

namespace eduart {

ParameterValue::ParameterValue(const int value)
{

}

ParameterValue::ParameterValue(const double value)
{

}

ParameterValue::ParameterValue(const std::string& value)
{

}

ParameterValue::ParameterValue(const ParameterValue& value)
{
  switch (value.type()) {
    case ParameterType::STRING:
      *_data.value_string = value.as_string();
      break;

    case ParameterType::INT:
      _data.value_int = value.as_int();
      break;

    case ParameterType::DOUBLE:
      _data.value_double = value.as_double();
      break;

    default:
      throw std::runtime_error("ParameterValue: copy failed, because of missing implementation.");
  }
}

ParameterValue::~ParameterValue()
{
  if (_type == ParameterType::STRING) {
    delete _data.value_string;
  }
}

int ParameterValue::as_int() const
{
  return 0;
}

double ParameterValue::as_double() const
{
  return 0.0;
}

const std::string& ParameterValue::as_string() const
{
  return "";
}

} // end namespace eduart