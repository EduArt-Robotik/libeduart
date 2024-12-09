find_package(Catch2 REQUIRED)

# Unit Tests
## Parameter
add_executable(unittest-parameter
  unittest_parameter.cpp
  unittest_parameter_value.cpp
  unittest_parameter_constrain.cpp
)
target_link_libraries(unittest-parameter
  PRIVATE
    Catch2::Catch2
)
