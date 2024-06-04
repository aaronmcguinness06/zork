# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Zork_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Zork_autogen.dir\\ParseCache.txt"
  "Zork_autogen"
  )
endif()
