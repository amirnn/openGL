cmake_minimum_required(VERSION 3.10)

project(openGL)

include_directories(include)

# To enforce static library linking of glew we add this
# preprocessor defintion.
add_definitions(-DGLEW_STATIC)

find_library(OPENGLLIB OpenGL REQUIRED)

if (WIN32)
    include_directories("C:/Program Files/GLFW/include")
    find_library(GLFWLIB glfw3 PATHS "C:/Program Files/GLFW/lib" REQUIRED)
    
endif (WIN32)

if (UNIX)
    find_library(GLEWLIB GLEW REQUIRED)
    find_library(GLFWLIB glfw REQUIRED)
    include_directories(${GLFW3_LIBS})
endif (UNIX)



# main GLFW window.
add_executable(main src/1.main.cc)
target_link_libraries(main ${GLFWLIB} ${OPENGLLIB} ${GLEWLIB})

# vertex buffs and shaders
add_executable(vertexBuffer src/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer ${GLFWLIB} ${OPENGLLIB} ${GLEWLIB})