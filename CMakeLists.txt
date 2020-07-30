cmake_minimum_required(VERSION 3.18)

project(openGL)

include_directories(include)

# To enforce static library linking of glew we add this
# preprocessor defintion. Look at the documentation.
add_definitions(-DGLEW_STATIC)

find_library(OPENGLLIB OpenGL REQUIRED)

if (WIN32)
    message("Running on Windows based platform.")   
    include_directories("C:/Program Files/GLFW/include")
    find_library(GLFWLIB glfw3 PATHS "C:/Program Files/GLFW/lib" REQUIRED)
    # Find library glew in windows
endif ()

if (UNIX AND NOT APPLE)
    message("Running on a Linux platform.")    
    find_library(GLEWLIB GLEW REQUIRED)
    find_library(GLFWLIB glfw REQUIRED)
    include_directories(${GLFW3_LIBS})
endif ()

if(APPLE)
    message("Running on an Apple platform.")
    find_library(GLEWLIB GLEW REQUIRED)
    find_library(GLFWLIB glfw REQUIRED)
    include_directories(${GLFW3_LIBS})
endif()





# main GLFW window.
add_executable(main src/1.main.cc)
target_link_libraries(main ${GLFWLIB} ${OPENGLLIB} ${GLEWLIB})

# vertex buffs and shaders
add_executable(vertexBuffer src/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer ${GLFWLIB} ${OPENGLLIB} ${GLEWLIB})