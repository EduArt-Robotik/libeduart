#include "eduart/parameter.hpp"

namespace eduart {

Parameter::Parameter(const std::string& name, const ParameterValue& default_value)
  : _value(default_value)
{
  
}

} // end namespace eduart
