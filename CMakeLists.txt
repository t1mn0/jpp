cmake_minimum_required(VERSION 3.25)
project(emathlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(emathlib INTERFACE)
target_include_directories(emathlib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE emathlib)
