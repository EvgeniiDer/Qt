# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QMainProject_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QMainProject_autogen.dir/ParseCache.txt"
  "QMainProject_autogen"
  )
endif()
