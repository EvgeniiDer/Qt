# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QtApi_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QtApi_autogen.dir/ParseCache.txt"
  "QtApi_autogen"
  )
endif()
