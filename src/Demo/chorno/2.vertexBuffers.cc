// Setup for the shaders and vertex buffers
 #include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <array>
#include "print.h"

// typedef std::string str;
using std::string;
using std::to_string;
using namespace std::string_literals;

// Setup 
int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initilize glew
    if(glewInit() != GLEW_OK)
        std::cout << "Error glewInit" <<std::endl;

    // ---- important stuff start from here.
    // Create a buffer
    uint buffer;
    glGenBuffers(1,&buffer);
    print::printLine("The id of the buffer is: "s + to_string(buffer));
    // So far we haven't defined any size for the buffer.
    glBindBuffer(GL_ARRAY_BUFFER,buffer);

    double positions[6] = {
        -0.5, -0.5,
         0.0,  0.5,
         0.5, -0.5
    };
    glBufferData(GL_ARRAY_BUFFER,6 * sizeof(double), positions, GL_STATIC_DRAW);
    
    // To print out the opengl version with the vendor.
    std::cout << glGetString(GL_VERSION) << std::endl;
  

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // glBegin(GL_TRIANGLES);
        // glVertex2d(-0.5, -0.5);
        // glVertex2d(-0.5, 0.5);
        // glVertex2d(0.0,0.5);
        // glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}