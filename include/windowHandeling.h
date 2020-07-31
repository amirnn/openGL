#pragma once
#include <GLFW/glfw3.h>

// Window handling functions.
namespace windowHandling
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow *window);

} // namespace windowHandling
