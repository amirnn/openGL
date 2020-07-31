cmake_minimum_required(VERSION 3.18)

project(openGL)
include_directories(include)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_library(OPENGL_LIB OpenGL REQUIRED)

# Create print library
# add_library(print src/print.cc include/print.h)

if (WIN32)
    include(CMakeModules/windows.cmake)

elseif(UNIX AND NOT APPLE)
    include(CMakeModules/linux.cmake)

elseif(APPLE)
    include(CMakeModules/macos.cmake)

endif()
