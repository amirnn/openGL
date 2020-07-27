cmake_minimum_required(VERSION 3.10)

project(openGL)

include_directories(include)
find_library(OPENGLLIB opengl64 REQUIRED)

if (WIN32)
    include_directories("C:/Program Files/GLFW/include")
    find_library(GLFWLIB glfw3 PATHS "C:/Program Files/GLFW/lib" REQUIRED)
    
endif (WIN32)

if (UNIX)
    find_library(GLFWLIB glfw3 REQUIRED)
    include_directories(${GLFW3_LIBS})
endif (UNIX)



# main GLFW window.
add_executable(main src/main.cc)
target_link_libraries(main ${GLFWLIB} ${OPENGLLIB})