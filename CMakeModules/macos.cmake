message("Running on an Apple platform.")

include_directories(/usr/local/include)
# find glew
find_package(GLEW)
set(GLEW_USE_STATIC_LIBS ON)
# include_directories(GLEW_INCLUDEDIR)
# find_library(GLEW_LIB GLEW REQUIRED)


find_library(GLFW_LIB GLFW REQUIRED)
include_directories(${GLFW_INCLUDEDIRS})

# find_library(print_LIB print REQUIRED)

# 1. main GLFW window.
add_executable(main src/chorno/1.main.cc)
target_link_libraries(main ${GLFW_LIB} ${OPENGL_LIB} GLEW::GLEW)

# 2. vertex buffs and shaders
add_executable(vertexBuffer src/chorno/2.vertexBuffers.cc)
target_link_libraries(vertexBuffer ${GLFW_LIB} ${OPENGL_LIB} GLEW::GLEW)

set(WinHandling "include/windowHandeling.h" "src/windowHandeling.cc")
set(Print "include/print.h" "src/print.cc")

# 1. main GLFW window.
add_executable(helloWindow src/learnopenglcom/1.HelloWindow.cc ${WinHandling} ${Print})
target_link_libraries(helloWindow ${GLFW_LIB} ${OPENGL_LIB} GLEW::GLEW)