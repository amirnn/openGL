message("Running on a Linux platform.")

# Chorno
set(EXECUTABLE_OUTPUT_PATH ./bin/)
# 1. main GLFW window.
add_executable(main src/Demo/chorno/1.main.cc)
target_link_libraries(main glfw OpenGL::GL GLEW::GLEW)

# 2. vertex buffs and shaders
add_executable(vertexBuffer src/Demo/chorno/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer glfw OpenGL::GL GLEW::GLEW)

# COM
set(WinHandling "include/windowHandeling.h" "src/windowHandeling.cc")
set(Print "src/print.cc" "include/print.h")
set(OglHelper include/openGLHelper.h src/openGLHelper.cc)
set(Triangle include/Triangle.h src/Triangle.cc)

# 1. main GLFW window.
add_executable(helloWindow src/Demo/learnopenglcom/1.HelloWindow.cc ${WinHandling} ${Print})
target_link_libraries(helloWindow glfw OpenGL::GL GLEW::GLEW)

# 2. Triangle
add_executable(DrawTriangle src/Demo/learnopenglcom/2.TriangleWindow.cc ${OglHelper} ${Triangle} ${WinHandling} ${Print})
target_link_libraries(DrawTriangle glfw OpenGL::GL GLEW::GLEW)

# 3. Rectangle
add_executable(DrawRectangle src/Demo/learnopenglcom/3.Rectangle.cc ${OglHelper} ${Triangle} ${WinHandling} ${Print})
target_link_libraries(DrawRectangle glfw OpenGL::GL GLEW::GLEW)

# 4. Shaders
add_executable(ShadersDemo src/Demo/learnopenglcom/4.shaders.cc ${OglHelper} ${Triangle} ${WinHandling} ${Print})
target_link_libraries(ShadersDemo glfw OpenGL::GL GLEW::GLEW)

# 5. Shaders
add_executable(ShadersDemoColorEdge src/Demo/learnopenglcom/5.shaders.cc ${OglHelper} ${Triangle} ${WinHandling} ${Print})
target_link_libraries(ShadersDemoColorEdge glfw OpenGL::GL GLEW::GLEW)