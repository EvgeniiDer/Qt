cmake_minimum_required(VERSION 3.16)

project(QCustomDialog LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(QCustomDialog
  main.cpp
  MainWindow/qcustommainwindow.h MainWindow/qcustommainwindow.cpp
  PushButtons/PushButtonCopy//pushbuttoncopy.h PushButtons/PushButtonCopy//pushbuttoncopy.cpp
  PushButtons/PushButtonAdd/pushbuttonadd.h PushButtons/PushButtonAdd/pushbuttonadd.cpp
  head.h
)
target_link_libraries(QCustomDialog Qt${QT_VERSION_MAJOR}::Core
                      Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS QCustomDialog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
