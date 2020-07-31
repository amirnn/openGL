message("Running on Windows based platform.")

# To enforce static library linking of glew we add this
# preprocessor defintion. Look at the documentation. 
add_definitions(-DGLEW_STATIC)
include_directories("C:/Program Files/GLFW/include")
find_library(GLFW_LIB glfw3 PATHS "C:/Program Files/GLFW/lib" REQUIRED)
# Find library glew in windows
find_library(GLEW_LIB)

# main GLFW window.
add_executable(main src/1.main.cc)
target_link_libraries(main ${GLFW_LIB} ${OPENGL_LIB} ${GLEW_LIB})

# vertex buffs and shaders
add_executable(vertexBuffer src/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer ${GLFW_LIB} ${OPENGL_LIB} ${GLEW_LIB})