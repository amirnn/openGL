cmake_minimum_required(VERSION 3.16)

project(openGL)

# Set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include dir
include_directories(include)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
find_package(GLEW REQUIRED)
set(GLEW_USE_STATIC_LIBS ON)
# find_package(glfw3 REQUIRED)

# To find variables
# include(CMakeModules/printVariables.cmake)

if (WIN32)
    include(CMakeModules/windows.cmake)

elseif(UNIX AND NOT APPLE)
    find_package(glfw3 REQUIRED)
    include(CMakeModules/linux.cmake)

elseif(APPLE)
    find_package(GLFW3 REQUIRED)
    include(CMakeModules/macos.cmake)

endif()
