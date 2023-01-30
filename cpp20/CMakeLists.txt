cmake_minimum_required(VERSION 3.5)

project(cpp20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#include_directories(
#Dependencies/glfw/include
#)

#to link static library
#libglfw3.a
#find_library(GLFW_LIB NAMES libglfw.3.dylib PATHS "${CMAKE_SOURCE_DIR}/Dependencies/glfw/lib-x86_64")

#message("GLFW_LIB: " ${GLFW_LIB})

add_executable(cpp20
span.cpp
#cpp20.cpp
)

#target_link_libraries(cpp20
#    ${GLFW_LIB}
#    "-framework Cocoa"
#    "-framework OpenGL"
#    "-framework IOKit"
#)

install(TARGETS cpp20
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
