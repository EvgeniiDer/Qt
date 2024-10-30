cmake_minimum_required(VERSION 3.14)

project(QMainProject LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(QMainProject
  main.cpp
  head.h
  QCustomMainWindow/mainwindow.h QCustomMainWindow/mainwindow.cpp
  QCustomPushButtons/pushbutton.h QCustomPushButtons/pushbutton.cpp
  QCustomMenuBar/menubar.h QCustomMenuBar/menubar.cpp

)
target_link_libraries(QMainProject Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
include(GNUInstallDirs)
install(TARGETS QMainProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
