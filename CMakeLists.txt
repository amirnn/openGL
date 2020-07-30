cmake_minimum_required(VERSION 3.18)

project(openGL)
include_directories(include)
set(CMAKE_CXX_STANDARD 20)

# To enforce static library linking of glew we add this
# preprocessor defintion. Look at the documentation.
add_definitions(-DGLEW_STATIC)

find_library(OPENGL_LIB OpenGL REQUIRED)

if (WIN32)
include(CMake/windows.txt)
endif ()

if (UNIX AND NOT APPLE)
include(CMake/linux.txt)
endif ()

if(APPLE)
include(CMake/macos.txt)
endif()
