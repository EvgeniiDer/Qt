# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ListDialogProject_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ListDialogProject_autogen.dir/ParseCache.txt"
  "ListDialogProject_autogen"
  )
endif()
