#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "print.h"
#include "windowHandeling.h"

int main(int argc, char const *argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // On macos we need this check
    if (__APPLE__)
    {
        print::printLine("Platform Detected: MacOS");
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glew checks
    // I am using glew, however in the tutorials GLAD is being used.
    GLenum err = glewInit();
    {
        if (GLEW_OK != err)
        {
            /* Problem: glewInit failed, something is seriously wrong. */
            fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        }
        fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    }

    glViewport(0, 0, 800, 600);

    // fix resizing callback
    glfwSetFramebufferSizeCallback(window, windowHandling::framebuffer_size_callback);

// Render Loop
    while(!glfwWindowShouldClose(window))
{   
    // Process Inputs
    windowHandling::processInput(window);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Check and call events and swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();    
}

    // Clear resources.
    glfwTerminate();
    return 0;
}
