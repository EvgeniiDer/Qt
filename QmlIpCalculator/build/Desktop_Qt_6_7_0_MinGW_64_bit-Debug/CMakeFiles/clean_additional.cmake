# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appQmlNetworkAnalyzer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appQmlNetworkAnalyzer_autogen.dir\\ParseCache.txt"
  "appQmlNetworkAnalyzer_autogen"
  )
endif()
