cmake_minimum_required(VERSION 3.16)

project(ListDialogProject LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

add_executable(ListDialogProject
  main.cpp
  MainWindow/mainwindow.h
  MainWindow/mainwindow.cpp
  head.h
  ListViewDelegate/listviewdelegate.cpp ListViewDelegate/listviewdelegate.h
)
target_link_libraries(ListDialogProject Qt${QT_VERSION_MAJOR}::Core
                                        Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS ListDialogProject
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
