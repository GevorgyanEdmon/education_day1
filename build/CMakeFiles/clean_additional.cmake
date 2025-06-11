# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\SuperCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SuperCalculator_autogen.dir\\ParseCache.txt"
  "SuperCalculator_autogen"
  )
endif()
