message("Running on an Apple platform.")
include_directories(/usr/local/include)


# 1. main GLFW window.
add_executable(main src/chorno/1.main.cc)
target_link_libraries(main glfw OpenGL::GL GLEW::GLEW)

# 2. vertex buffs and shaders
add_executable(vertexBuffer src/chorno/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer glfw OpenGL::GL GLEW::GLEW)

set(WinHandling "include/windowHandeling.h" "src/windowHandeling.cc")
set(Print "include/print.h" "src/print.cc")

# 1. main GLFW window.
add_executable(helloWindow src/learnopenglcom/1.HelloWindow.cc ${WinHandling} ${Print})
target_link_libraries(helloWindow glfw OpenGL::GL GLEW::GLEW)

# 2. Triangle
set(Triangle src/Triangle.cc include/Triangle.h)
add_executable(Triangle src/learnopenglcom/2.TriangleWindow.cc ${Triangle} ${WinHandling} ${Print})
target_link_libraries(Triangle glfw OpenGL::GL GLEW::GLEW)

# 3. Rectangle
add_executable(Rectangle src/learnopenglcom/3.Rectangle.cc ${Triangle} ${WinHandling} ${Print})
target_link_libraries(Rectangle glfw OpenGL::GL GLEW::GLEW)

# 4. Shaders
add_executable(Shaders src/learnopenglcom/4.shaders.cc ${WinHandling} ${Print})
target_link_libraries(Shaders glfw OpenGL::GL GLEW::GLEW)