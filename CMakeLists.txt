cmake_minimum_required(VERSION 3.18)

project(openGL)
include_directories(include)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenGL
find_library(OPENGL_LIB OpenGL REQUIRED)

if (WIN32)
    include(CMake/windows.txt)

elseif(UNIX AND NOT APPLE)
    include(CMake/linux.txt)

elseif(APPLE)
    include(CMake/macos.txt)

endif()
