# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CVUse_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CVUse_autogen.dir\\ParseCache.txt"
  "CVUse_autogen"
  )
endif()
