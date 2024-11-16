# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QCustomDialog_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QCustomDialog_autogen.dir/ParseCache.txt"
  "QCustomDialog_autogen"
  )
endif()
