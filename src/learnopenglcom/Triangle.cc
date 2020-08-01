#include "learnopenglcom/Triangle.h"

Triangle::Triangle(/* args */)
{
}

Triangle::~Triangle()
{
}

void Triangle::initWindow()
{
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        throw std::runtime_error("Error creating window.");
    }
    // set context to current window.
    glfwMakeContextCurrent(window);
};
void Triangle::initGLFW()
{
    if (glfwInit() == GLFW_FALSE)
        throw std::runtime_error("Error creating initializing the GLEW.");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // On macos we need this check
    if (__APPLE__)
    {
        print::printLine("Platform Detected: MacOS");
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }
}

void Triangle::setWindowAttributes(){

    // Set viewport.
    glViewport(0, 0, 800, 600);

    // fix handles:  here, resizing callback
    glfwSetFramebufferSizeCallback(window, windowHandling::framebuffer_size_callback);
}

void Triangle::mainLoop()
{
    // Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // Process Inputs
        windowHandling::processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Triangle::initGLEW()
{
    // glew checks
    // I am using glew, however in the tutorials GLAD is being used.
    GLenum err = glewInit();
    {
        if (GLEW_OK != err)
            throw std::runtime_error("Error initializing GLEW.");

        fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    }
}
void Triangle::cleanup()
{
    // Clear resources.
    glfwTerminate();
}
void Triangle::createInstance() {}