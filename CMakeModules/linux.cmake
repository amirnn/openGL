message("Running on a Linux platform.")

find_library(GLEW_LIB GLEW REQUIRED)
find_library(GLFW_LIB glfw REQUIRED)
include_directories(${GLFW3_LIBS})

# main GLFW window.
add_executable(main src/1.main.cc)
target_link_libraries(main ${GLFW_LIB} ${OPENGL_LIB} ${GLEW_LIB})

# vertex buffs and shaders
add_executable(vertexBuffer src/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer ${GLFW_LIB} ${OPENGL_LIB} ${GLEW_LIB})