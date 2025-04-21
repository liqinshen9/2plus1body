# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appThreeBody2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appThreeBody2_autogen.dir\\ParseCache.txt"
  "appThreeBody2_autogen"
  )
endif()
