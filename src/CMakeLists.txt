cmake_minimum_required(VERSION 2.8)

project(clock)

find_package(Qt5Widgets)

aux_source_directory(. SRC_LIST)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_custom_target(forms SOURCES clock.ui)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
