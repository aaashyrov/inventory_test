cmake_minimum_required(VERSION 3.17)
project(inventory_test LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Gui Multimedia REQUIRED)

add_subdirectory(database)
add_subdirectory(inventory)
add_subdirectory(controller)

add_executable(inventory_test
        main.cpp
        mainwindow.h
        mainwindow.cpp
        item_widget.cpp
        item_widget.hpp
        inventory_widget.cpp
        inventory_widget.hpp

        mainwindow.ui
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Gui Qt5::Widgets Qt5::Multimedia libcontroller)