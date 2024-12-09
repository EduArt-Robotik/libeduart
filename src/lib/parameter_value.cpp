#include "eduart/parameter_value.hpp"
#include <stdexcept>

namespace eduart {

ParameterValue::ParameterValue(const ParameterValue& value)
{
  // switch (value.type()) {
  //   case ParameterType::STRING:
  //     new(&_data.value_string)(std::string);
  //     _data.value_string = value.as_string();
  //     break;

  //   case ParameterType::INT:
  //     _data.value_int = value.as_int();
  //     break;

  //   case ParameterType::DOUBLE:
  //     _data.value_double = value.as_double();
  //     break;

  //   default:
  //     throw std::runtime_error("ParameterValue: copy failed, because of missing implementation.");
  // }


}

} // end namespace eduart