# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles\\hwW64_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\hwW64_autogen.dir\\ParseCache.txt"
  "hwW64_autogen"
  )
endif()
