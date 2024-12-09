add_library(eduart SHARED
  parameter.cpp
  parameter_value.cpp
)
target_include_directories(eduart
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(eduart

)